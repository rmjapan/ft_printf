#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

//仕様
///引き数
//・変換指定子(format)
//・変換指定子に対応する引数 ...
//・変換指定子は%で始まる

size_t	count_format_data_type(const char *format);
int		identify_data_type(char target);


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

	va_list target; // char*型をtypedefしたものとは限らない。コンパイラやプラットフォームに依存する。
	va_start(target, format);
	//#define va_start(ap,v) ((ap)=(Va_list)&(v)+sizeof(v)
	// Va_startは、可変長引数リストの先頭を指定してくれる関数
	//この場合は、apが先頭のアドレスを指すようになっている。
	// formatは、固定引数というやつ。printf関数ならば、最初の第一引数がそれに当たる。
	//固定引数=シグネチャに定義されている引数,可変長引数はシグネチャには明示的に含まれません。
	//シグネチャ=関数の名前、戻り値の型、および引数の型と数の組み合わせを意味する。
	//たとえば、int sum(int,int) という関数のシグネチャは、戻り値が int であり、二つの int 型の引数を取ることを意味します。
	count = count_format_data_type(const char *format);
	// formatの中にある変換指定子の数を数える。
	for (int i = 0; i < count; i++)
	{
		data_type = 0;
		data_type = identify_data_type(*target);
		switch (data_type) // data_type毎にva_argsを適用する。
		{
		case 1:
			c_target = va_args(target, char);
			break ;
		case 2:
			s_target = va_args(target, char *);
			break ;
		case 3:
			p_target = va_args(target, void *);
			break ;
		case 4:
			d_target = va_args(target, int);
			break ;
		case 5:
			int i_target = va_args(target, int); //%iと%dの違いは？　i:基数10の整数を出力する。
			break ;
		case 6:
			u_target = va_args(target, unsigned int);
			break ;
		case 7:
			x_target = va_args(target, unsigned int);
			break ;
		case 8:
			X_target = va_args(target, unsigned int);
			break ;
		case 9:
			persent_persent_target = va_args(target, int);
			break ;
		default: //エラー処理は別途考える。
		}
	}
	va_end(args); //可変長引数リストをクリアする。
	return (0);
}
