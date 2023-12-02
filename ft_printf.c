#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

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

all_type_conversion_specifier *output_target(char *format, va_list target)
{
	all_type_conversion_specifier	*memo;

	if (is_conversion_specifier(format))
	{
		memo = init_all_type_conversion_specifier(memo);//初期化
		memo = set_identified_type_conversion_specifier(memo, *format, target);//変換指定子の型にそって、値をセットする。
		return (memo);	
	}
	else{
		set_conversion_specifier_type(format+1, target);//進む
		//戻るモード
		if(*format=='.'){
			//精度がある場合は、精度桁を明らかにする関数を作成する//この時点で、値をどんどん変更させていく

		}







	}
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
				output_target(p, target);
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
