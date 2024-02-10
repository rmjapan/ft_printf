#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"
#include <stdio.h>

unsigned int	a_minus_b(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (0);
}

void	minus_field_precision_x(all_type_conversion_specifier *memo)
{
	char			*x_value;
	unsigned int	x_len;
	unsigned int	width_minus_x_len;
	unsigned int	prec_minus_x_len;

	x_value = itoa_hexa(memo->x, 7);
	x_len = ft_strlen(x_value);
	width_minus_x_len = a_minus_b(memo->width_flag, x_len);
	prec_minus_x_len = a_minus_b(memo->precision_flag, x_len);
	while (memo->precision_flag-- > (int)(x_len))
		write(1, "0", 1);
	write(1, x_value, sizeof(x_value));
	while (width_minus_x_len-- > prec_minus_x_len)
		write(1, " ", 1);
}

void	zero_field_x(all_type_conversion_specifier *memo)
{
	char			*x_value;
	unsigned int	x_len;

	x_value = itoa_hexa(memo->x, 7);
	x_len = ft_strlen(x_value);
	while (memo->width_flag-- > (int)(x_len))
		write(1, "0", 1);
	write(1, x_value, sizeof(x_value));
}

void	field_precision_x(all_type_conversion_specifier *memo)
{
	char			*x_value;
	unsigned int	x_len;
	unsigned int	width_minus_x_len;
	unsigned int	prec_minus_x_len;
	x_value = itoa_hexa(memo->x, 7);
	x_len = ft_strlen(x_value);
	width_minus_x_len = a_minus_b(memo->width_flag, x_len);
	prec_minus_x_len = a_minus_b(memo->precision_flag, x_len);
	while (width_minus_x_len-- > prec_minus_x_len)
		write(1, " ", 1);
	while (memo->precision_flag-- > (int)(x_len))
		write(1, "0", 1);
	write(1, x_value, sizeof(x_value));
}

void	print_x(all_type_conversion_specifier *memo)
{
	if (memo->minus_flag == true)
	{
		minus_field_precision_x(memo);
	}
	else if (memo->zero_flag == true)
	{
		zero_field_x(memo);
	}
	else
	{
		field_precision_x(memo);
	}
}

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ここに all_type_conversion_specifier 構造体と print_x 関数の定義を含める

// void	test_printf_x(all_type_conversion_specifier *memo)
// {
// 	write(1, "[", 1);
// 	print_x(memo);
// 	write(1, "]", 1);
// 	printf("\n");
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Dedicated test function for %x scenarios
void	test_printf_x(all_type_conversion_specifier *memo)
{
	printf("マイナスフラグ: %d /", memo->minus_flag);
	printf("ゼロフラグ: %d /", memo->zero_flag);
	printf("精度フラグ: %d /", memo->precision_flag);
	printf("フィールド幅フラグ: %d /", memo->width_flag);
	printf("出力値: %d\n", memo->x);
	
	char format[50]; // To hold the format string for dynamic configuration
	// Building the format string based on specified flags and precision
	if (memo->minus_flag)
		{
			printf("マイナスフラグが存在する場合\n");
			snprintf(format, sizeof(format), "Std:  [%%-%d.%dx]\n",
				memo->width_flag, memo->precision_flag);
		}
	else if (memo->zero_flag && memo->precision_flag < 0)
	{
		printf("ゼロフラグが存在する場合\n");
		snprintf(format, sizeof(format), "Std:  [%%0%d.%dx]\n",
			memo->width_flag,
					memo->precision_flag); // Width duplicated for zero padding
	}
	else
	{
		memo->zero_flag = false;
		printf("フラグが存在しない場合\n");
		snprintf(format, sizeof(format), "Std:  [%%%d.%dx]\n", memo->width_flag,
			memo->precision_flag);
	}
	// Benchmark output with standard printf function
	printf(format, memo->x);
	// Prefix for custom printf function output
	write(1, "Cust: [", 7);
	print_x(memo);
	// Invoke custom function to simulate `%x` output via `ft_printf`
	write(1, "]\n", 2);
	printf("\n");
}

int	main(void)
{
	all_type_conversion_specifier	*memo;

	memo = (all_type_conversion_specifier *)malloc(sizeof(all_type_conversion_specifier));
	// Test configuration for %x conversion specifier tests
	unsigned int test_values[] = {0, 1, 3, 255, 0xFFFF, 0xFFFFFFFF};
	// Including edge cases
	int field_widths[] = {1, 4, 8};
	// Example field widths
	int precisions[] = {1, 2, 4};
	// Precision settings, -1 for no precision
	bool flags[][2] = {{false, false}, {true, false}, {false, true}};
	// Flag configurations: no flags, minus, zero
	for (int i = 0; i < sizeof(test_values) / sizeof(test_values[0]); i++)
	{
		for (int w = 0; w < sizeof(field_widths) / sizeof(field_widths[0]); w++)
		{
			for (int p = 0; p < sizeof(precisions) / sizeof(precisions[0]); p++)
			{
				for (int f = 0; f < sizeof(flags) / sizeof(flags[0]); f++)
				{
					memo->x = test_values[i];
					memo->width_flag = field_widths[w];
					memo->precision_flag = precisions[p];
					memo->minus_flag = flags[f][0];
					memo->zero_flag = flags[f][1];
					// Execute custom test function
					test_printf_x(memo);
				}
			}
		}
	}
	// Deallocate memory
	free(memo);
	return (0);
}

// int	main(void)
// {
// 	all_type_conversion_specifier	*memo;

// 	memo = (all_type_conversion_specifier *)malloc(sizeof(all_type_conversion_specifier));
// 	// 1-a. 精度とフィールド幅が値の長さより大きい場合
// 	printf("1-a. Precision and width greater than value length\n");
// 	memo->x = 16;
// 	memo->precision_flag = 5; // 精度の設定
// 	memo->width_flag = 10;    // フィールド幅の設定
// 	memo->minus_flag = true;
// 	memo->zero_flag = false;
// 	printf("[%-10.5x]\n", 16);
// 	test_printf_x(memo);
// 	// 他のテストケースも同様に追加...
// 	// 1-b. 精度がフィールド幅より大きいが、値の長さより小さい場合
// 	printf("1-b. Precision greater than width, but less than value length\n");
// 	memo->x = 12345;
// 	memo->precision_flag = 3; // 精度の設定
// 	memo->width_flag = 10;    // フィールド幅の設定
// 	memo->minus_flag = true;
// 	memo->zero_flag = false;
// 	printf("[%-10.3x]\n", 12345);
// 	test_printf_x(memo);
// 	// 1-c. フィールド幅のみが指定され、精度が指定されていない場合
// 	printf("1-c. Only width specified, no precision\n");
// 	memo->x = 255;
// 	memo->precision_flag = 0; // 精度未設定
// 	memo->width_flag = 10;    // フィールド幅の設定
// 	memo->minus_flag = true;
// 	memo->zero_flag = false;
// 	printf("[%-10x]\n", 255);
// 	test_printf_x(memo);
// 	// 2-a. フィールド幅が値の長さより大きい場合
// 	printf("2-a. Width greater than value length with zero flag\n");
// 	memo->x = 16;
// 	memo->precision_flag = 0; // 精度未設定
// 	memo->width_flag = 10;    // フィールド幅の設定
// 	memo->minus_flag = false;
// 	memo->zero_flag = true;
// 	printf("[%010x]\n", 16);
// 	test_printf_x(memo);
// 	// 2-b. フィールド幅が値の長さに等しい場合
// 	printf("2-b. Width equal to value length with zero flag\n");
// 	memo->x = 12345;
// 	memo->precision_flag = 0; // 精度未設定
// 	memo->width_flag = 5;     // フィールド幅の設定
// 	memo->minus_flag = false;
// 	memo->zero_flag = true;
// 	printf("[%05x]\n", 12345);
// 	test_printf_x(memo);
// 	// 2-c. フィールド幅が値の長さより小さい場合
// 	printf("2-c. Width less than value length with zero flag\n");
// 	memo->x = 12345;
// 	memo->precision_flag = 0; // 精度未設定
// 	memo->width_flag = 3;     // フィールド幅の設定
// 	memo->minus_flag = false;
// 	memo->zero_flag = true;
// 	printf("[%03x]\n", 12345);
// 	test_printf_x(memo);
// 	// 3-a. フィールド幅と精度が両方指定されている場合
// 	printf("3-a. Both width and precision specified\n");
// 	memo->x = 16;
// 	memo->precision_flag = 5; // 精度の設定
// 	memo->width_flag = 10;    // フィールド幅の設定
// 	memo->minus_flag = false;
// 	memo->zero_flag = false;
// 	printf("[%10.5x]\n", 16);
// 	test_printf_x(memo);
// 	// 3-b. フィールド幅のみが指定されている場合
// 	printf("3-b. Only width specified\n");
// 	memo->x = 255;
// 	memo->precision_flag = 0; // 精度未設定
// 	memo->width_flag = 10;    // フィールド幅の設定
// 	memo->minus_flag = false;
// 	memo->zero_flag = false;
// 	printf("[%10x]\n", 255);
// 	test_printf_x(memo);
// 	// 3-c. 精度のみが指定されている場合
// 	printf("3-c. Only precision specified\n");
// 	memo->x = 255;
// 	memo->precision_flag = 5; // 精度の設定
// 	memo->width_flag = 0;     // フィールド幅��設定
// 	memo->minus_flag = false;
// 	memo->zero_flag = false;
// 	printf("[%.5x]\n", 255);
// 	test_printf_x(memo);
// 	// エッジケース: 値が0の場合
// 	printf("Edge Case: Value is 0\n");
// 	memo->x = 0;
// 	memo->precision_flag = 5; // 精度の設定
// 	memo->width_flag = 10;    // フィールド幅の設定
// 	memo->minus_flag = true;  // マイナスフラグをテスト
// 	memo->zero_flag = false;
// 	printf("[%-10.5x]\n", 0);
// 	test_printf_x(memo);
// 	// エッジケース: フィールド幅と精度が非常に大きい場合
// 	printf("Edge Case: Very large width and precision\n");
// 	memo->x = 255;
// 	memo->precision_flag = 40; // 大きな精度の設定
// 	memo->width_flag = 50;     // 大きなフィールド幅の設定
// 	memo->minus_flag = false;
// 	memo->zero_flag = false;
// 	printf("[%50.40x]\n", 255);
// 	test_printf_x(memo);
// 	// エッジケース: フィールド幅と精度が0の場合
// 	printf("Edge Case: Width and Precision are 0\n");
// 	memo->x = 255;
// 	memo->precision_flag = 0; // 精度を0に設定
// 	memo->width_flag = 0;     // フィールド幅を0に設定
// 	memo->minus_flag = false;
// 	memo->zero_flag = false;
// 	printf("[%.0x]\n", 255);
// 	test_printf_x(memo);
// 	// エッジケース: フィールド幅が値の長さより小さいが、精度が高い場合
// 	printf("Edge Case: Width less than value length, but high precision\n");
// 	memo->x = 1234;
// 	memo->precision_flag = 10; // 高精度設定
// 	memo->width_flag = 3;      // 小さいフィールド幅の設定
// 	memo->minus_flag = false;
// 	memo->zero_flag = false;
// 	printf("[%3.10x]\n", 1234);
// 	test_printf_x(memo);
// 	return (0);
// }
