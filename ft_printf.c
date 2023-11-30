#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

//仕様
///引き数
//・変換指定子(format)
//・変換指定子に対応する引数 ...
//・変換指定子は%で始まる

int	identify_data_type(char target); //定義は別ファイルに書く。

// printf関数の仕様
///出力：stdoutの出力
void	data_type_write(int data_type, va_list target)
{
	switch (data_type) // data_type毎にva_argsを適用する。
	{
	case 1:
		c_target = va_args(target, char);
		write(1, &c_target, 1);
		break ;
	case 2:
		s_target = va_args(target, char *);
		write(1, s_target, ft_strlen(s_target));
		break ;
	case 3:
		p_target = va_args(target, void *);
		write(1, p_target, sizeof(p_target));
		break ;
	case 4:
		d_target = va_args(target, int);
		write(1, &d_target, sizeof(d_target));
		break ;
	case 5:
		i_target = va_args(target, int); //%iと%dの違いは？　i:基数10の整数を出力する。
		write(1, &i_target, sizeof(i_target));
		break ;
	case 6:
		u_target = va_args(target, unsigned int);
		write(1, &u_target, sizeof(u_target));
		break ;
	case 7:
		x_target = va_args(target, unsigned int);
		write(1, &x_target, sizeof(x_target));
		break ;
	case 8:
		X_target = va_args(target, unsigned int);
		write(1, &X_target, sizeof(X_target));
		break ;
	case 9:
		persent_persent_target = va_args(target, int);
		write(1, "%", 1);
		break ;
	default: //エラー処理は別途考える。
	}
}

int	ft_printf(const char *format, ...)
{
	size_t			count;
	int				data_type;
	char			c_target;
	char			*s_target;
	void			*p_target;
	int				d_target;
	unsigned int	u_target;
	int				x_target;
	int				X_target;
	int				persent_persent_target;
	size_t			format_len;

	va_list target; // char*型をtypedefしたものとは限らない。コンパイラやプラットフォームに依存する。
	// Va_startは、可変長引数リストの先頭を指定してくれる関数
	va_start(target, format);
	//#define va_start(ap,v) ((ap)=(Va_list)&(v)+sizeof(v)
	//仕様調査。
	// stdoutに出力される。//標準出力	stdout	1(write(1,?,?))
	//位置指定子を使用する場合/そうでない場合の処理は必要。
	// EX printf("%2$d %1$d", 1, 2);->2,1と出力 : 10進数の数字の文字列に続いて $ がある場合、その数字はアクセスする引数の順番を指定している。
		//但し、位置指定子を使う場合は一貫性を持たせることが重要。すべての変換仕様で位置指定を使うか、または一切使わないかのどちらかに統一する必要があります。
		//変換仕様について
		// http://www9.plala.or.jp/sgwr-t/detail/FormatString.html、https://www.mm2d.net/main/prog/c/printf_format-03.html（明日はここから。）
		if (位置指定子が存在する場合)
	{
		if (すべての変換仕様で位置指定子を使用しているか確認)
		//使用していない場合、結果は不定となる。
	}
	else
	{
		//位置指定を使っている一部の指定子と使っていない他の指定子を混在させると、結果は不定（予測不可能）になります。
		for (const char *p = format; *p != '\0'; p++)
		{
			data_type = identify_data_type(*target); //出力形式の特定.
			if (data_type == 0)                      //単なる文字の場合と変換指定子の場合での場合分け
			{
				//特殊文字の場合もあるからこれは安直である。
				write(1, p, 1);
			}
			else
			{
				//%9dなどの場合の処理に対応する必要がある。
				//加えて、それに応じてPointerのススメ具合も変更する必要あり
				//
				data_type_write(data_type, target);
		)
			}
		}
	}
	va_end(args); //可変長引数リストをクリアする。
	return (0);
}
import openai


for (int i = 0; i < 10; i++)
{
	//bot=
	if()
}

