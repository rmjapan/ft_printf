/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_width_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:27:15 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/25 14:27:22 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf_format	*set_field_width_flag(t_printf_format *memo, const char *format)
{
	if (memo->minus_flag == true)
		format++;
	if (memo->zero_flag == true)
		format++;
	memo->field_width = ft_atoi(format);
	return (memo);
}
