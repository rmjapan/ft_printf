/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:01:45 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/10 15:47:51 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct　s_printf_format
{
	int type;           // 変換指定子の種類
	int field_width;    // 幅フラグ
	int precsion_width; // 精度フラグ
	bool minus_flag;    // マイナスフラグ
	bool zero_flag;     // 0フラグ
	char			c;
	char			*s;
	unsigned int	p;
	int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;
}
t_printf_format;

int					ft_printf(const char *format, ...);
t_printf_format		*init_t_printf_format(t_printf_format *all_type);
t_printf_format		*set_identified_type_conversion_specifier(t_printf_format *t_printf_format,
						char format, va_list target);
t_printf_format		*set_zero_flag(t_printf_format *memo, char *foramt);
t_printf_format		*set_field_width(t_printf_format *memo, char *foramt);
void				print_target(t_printf_format *memo);
void				printf_c(t_printf_format *memo);
void				printf_s(t_printf_format *memo);
void				printf_p(t_printf_format *memo);
void				printf_d_i_u(t_printf_format *memo);
void				printf_x(t_printf_format *memo);
void				printf_xx(t_printf_format *memo);
unsigned int		a_minus_b(int a, int b);
char				*itoa_hexa(unsigned int n, int type);
bool	is_conversion_specifier(char c) // 変換指定子を識別する
#endif                               // FT_PRINTF_H
