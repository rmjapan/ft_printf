/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:01:45 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/04/07 21:04:55 by rmiyauch         ###   ########.fr       */
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
	int					type;
	int					field_width;
	int					precsion_width;
	bool				minus_flag;
	bool				zero_flag;
	int					c;
	char				*s;
	unsigned long long	p;
	int					d;
	int					i;
	unsigned int		u;
	unsigned int		x;
	unsigned int		xx;
}						t_printf_format;

int						ft_printf(const char *format, ...);
void					init_t_printf_format(t_printf_format *format);
t_printf_format			*set_id_type_conv_spec(t_printf_format *format, char c,
							va_list *args);
t_printf_format			*set_zero_flag(t_printf_format *format,
							const char *str);
t_printf_format			*set_field_width_flag(t_printf_format *format,
							const char *str);
void					printf_target(t_printf_format *format,
							int *return_result);
void					printf_c(t_printf_format *format, int *return_result);
void					printf_s(t_printf_format *format, int *return_result);
void					printf_p(t_printf_format *format, int *return_result);
void					printf_d_i_u(t_printf_format *format,
							int *return_result);
void					printf_x(t_printf_format *format, int *return_result);
void					printf_xx(t_printf_format *format, int *return_result);
unsigned int			a_minus_b(int a, int b);
char					*itoa_hexa(unsigned long long nbr, int is_upper);
bool					is_conversion_specifier(char c);
char					*ft_itoa_u(size_t n);
void					write_chars(char c, int count, int *return_result,
							int compared_num);

#endif // FT_PRINTF_H