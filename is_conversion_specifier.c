/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conversion_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:51:55 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/10 12:52:00 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

bool	is_conversion_specifier(char c) //変換指定子を識別する
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X');
}
