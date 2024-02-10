/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:50:27 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/10 12:50:44 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"

t_printf_format	*set_witdth_flag(t_printf_format *memo,
		char *format)
{
	if (memo->minus_flag == true)
		format++;
	if (memo->zero_flag == true)
		format++;
	memo->field_width = ft_atoi(format);
	return (memo);
}
