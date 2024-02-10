/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zero_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:51:10 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/10 12:51:13 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

t_printf_format	*set_zero_flag(t_printf_format *memo,
		char *format)
{
	if (memo->minus_flag == true || memo->precsion_width != -1)
	{
		return (memo);
	}

	else
	{
		if (*format == '0')
		{
			memo->zero_flag = true;
		}
	}
	return (memo);
}