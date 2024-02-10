#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct
{
	int type;           //変換指定子の種類
	int width_flag;     //幅フラグ
	int precision_flag; //精度フラグ
	bool minus_flag;    //マイナスフラグ
	bool zero_flag;     // 0フラグ
	char						c;
	char						*s;
	unsigned int				p;
	int							d;
	int							i;
	unsigned int				u;
	unsigned int				x;
	unsigned int				X;

}								all_type_conversion_specifier;

int								ft_printf(const char *format, ...);
all_type_conversion_specifier	*init_all_type_conversion_specifier(all_type_conversion_specifier *all_type);
all_type_conversion_specifier	*init_all_type_conversion_specifier(all_type_conversion_specifier *all_type);
all_type_conversion_specifier	*set_identified_type_conversion_specifier(all_type_conversion_specifier *all_type_conversion_specifier,
									char format, va_list target);
all_type_conversion_specifier	*set_zero_flag(all_type_conversion_specifier *memo,
									char *foramt);
all_type_conversion_specifier	*set_width_flag(all_type_conversion_specifier *memo,
									char *foramt);
void							print_target(all_type_conversion_specifier *memo);
void							printf_c(all_type_conversion_specifier *memo);
void							printf_s(all_type_conversion_specifier *memo);
void							printf_p(all_type_conversion_specifier *memo);
void							printf_d(all_type_conversion_specifier *memo);
void							printf_i(all_type_conversion_specifier *memo);
void							printf_u(all_type_conversion_specifier *memo);
void							printf_x(all_type_conversion_specifier *memo);
void							printf_X(all_type_conversion_specifier *memo);
unsigned int					a_minus_b(int a, int b);
char							*itoa_hexa(unsigned int n, int type);
bool	is_conversion_specifier(char c) //変換指定子を識別する
#endif // FT_PRINTF_H
