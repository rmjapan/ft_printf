#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

size_t	from_percent_to_conversion_specifier_len(char*format)//%から変換指定子までの長さ(これは、ポインターを進めるための長さを図るため。
{
	size_t len = 1; //必ず一つは存在するから
	while (!identyfy_conversion_specifier(format[len++]))
	return len;
}
size_t	output_target(char *format, va_list target)
{
	size_t	len;
	len = part_of_format_len(format);



	return len;
}
int	ft_printf(const char *format, ...)
{
	va_list	target;

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
				p = p + output_target(p, target);
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
