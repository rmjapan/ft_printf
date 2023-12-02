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
	void						*p;
	int							d;
	int							i;
	unsigned int				u;
	unsigned int				x;
	unsigned int				X;

}								all_type_conversion_specifier;

int								ft_printf(const char *format, ...);							init_all_type_conversion_specifier(all_type_conversion_specifier *all_type);
all_type_conversion_specifier	*init_all_type_conversion_specifier(all_type_conversion_specifier *all_type);
all_type_conversion_specifier	*set_identified_type_conversion_specifier(all_type_conversion_specifier *all_type_conversion_specifier,
		char format, va_list target)

#endif // FT_PRINTF_H
