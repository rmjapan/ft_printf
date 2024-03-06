/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:01:45 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/03/05 17:11:06 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../src/libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_printf_format
{
	int type;           // 変換指定子の種類
	int field_width;    // 幅フラグ
	int precsion_width; // 精度フラグ
	bool minus_flag;    // マイナスフラ
	bool zero_flag;     // 0フラグ
	int				c;
	char			*s;
	unsigned long long	p;
	int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	xx;
}					t_printf_format;

int					ft_printf(const char *, ...);
//t_printf_format		*init_t_printf_format(t_printf_format *);
void	init_t_printf_format(t_printf_format *);

t_printf_format		*set_id_type_conv_spec(t_printf_format *, char, va_list *);
t_printf_format		*set_zero_flag(t_printf_format *, const char *);
t_printf_format		*set_field_width_flag(t_printf_format *, const char *);
void				printf_target(t_printf_format *, int *);
void				printf_c(t_printf_format *, int *);
void				printf_s(t_printf_format *, int *);
void				printf_p(t_printf_format *, int *);
void				printf_d_i_u(t_printf_format *, int *);
void				printf_x(t_printf_format *, int *);
void				printf_xx(t_printf_format *, int *);
unsigned int		a_minus_b(int, int);
char				*itoa_hexa(unsigned long long, int);
bool	is_conversion_specifier(char); // 変換指定子を識別する
char				*ft_itoa_u(size_t);
#endif // FT_PRINTF_H
