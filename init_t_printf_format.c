/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inital_t_printf_format.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:05:44 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/10 13:41:49 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

t_printf_format	*init_t_printf_format(t_printf_format *t_printf_format)
{
	t_printf_format = malloc(sizeof(t_printf_format));

	t_printf_format->type = 0;
	t_printf_format->field_width = -1;
	t_printf_format->precsion_width = -1;
	t_printf_format->minus_flag = false;
	t_printf_format->zero_flag = false;
    t_printf_format->c = 0;
	t_printf_format->s = 0;
	t_printf_format->p = 0;
	t_printf_format->d = 0;
	t_printf_format->i = 0;
	t_printf_format->u = 0;
	t_printf_format->x = 0;
	t_printf_format->X = 0;
	return (t_printf_format);
}



