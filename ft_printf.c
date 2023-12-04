#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"

bool	is_conversion_specifier(char c) //変換指定子を識別する
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X');
}

size_t	from_percent_to_conversion_specifier_len(char *format)
//%から変換指定子までの長さ(これは、ポインターを進めるための長さを図るため。
{
	size_t len = 1; //必ず一つは存在するから
	while (!is_conversion_specifier(format[len++]))

		return (len);
}

all_type_conversion_specifier	*set_minus_precision_value(char *format,
		va_list target)
{
	all_type_conversion_specifier	*memo;

	if (is_conversion_specifier(format))
	{
		memo = init_all_type_conversion_specifier(memo);
		//初期化
		memo = set_identified_type_conversion_specifier(memo, *format, target);
		//変換指定子の型にそって、値をセットする。
		return (memo);
	}
	else
	{
		memo = set_minus_precision_value(format + 1, target); //変換指定子が来るまで読み続ける。
		//戻るモード
		if (*format == '.')
		{
			memo->precision_flag = ft_atoi(format + 1);
			//精度がある場合は、精度桁を明らかにするために、変換指定子まで読み続ける。
			// ft_atoiを使えば良いのでは?
		}
		if (*format == '-')
		{
			memo->minus_flag = true;
		}
		// zero_flagの有無の処理と、width_flagの有無の処理はここでは行なっていない。というかここでは行なえないので、別の関数で行う。
		return (memo);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list							target;
	all_type_conversion_specifier	*memo;

	// char*型をtypedefしたものとは限らない。コンパイラやプラットフォームに依存する。
	va_start(target, format);
	//// Va_startは、可変長引数リストの先頭を指定してくれる関数
	for (const char *p = format; *p != '\0'; p++) // formatの処理方法を考える
	{
		if (*p == "%")
		{
			p++;
			if (p == "%")
			{
				write(1, "%", 1);
			}
			else
			{
				//関数を呼び出すから少し長くなるかも
				memo = set_minus_precision_value(p, target);
				memo = set_zero_flag(memo, p);
				memo = set_width_flag(memo, p);
				print_target(memo);
				p = p + from_percent_to_conversion_specifier_len(p);
			}
		}
		else
		{
			write(1, *p, 1);
		}
	}
	va_end(args); //可変長引数リストをクリアする。
	return (0);
}
