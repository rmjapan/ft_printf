/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:41:10 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/01 12:55:38 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1:マイナスフラグが存在する場合
// Point1（マイナスフラグ×最小フィールド幅×精度桁×c）
// 2:マイナスフラグが存在しない場合
// ゼロフラグが存在する場合
// Point2（ゼロフラグ×最小フィールド幅×変換指定子の組み合わせ）
// ゼロフラグが存在しない場合
// Point3（最小フィールド幅×精度桁×変換指定子の組み合わせ）

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"
#include <stdio.h>

void	minus_field_c(all_type_conversion_specifier *memo)
{
	write(1, &memo->c, 1);
	while (memo->width_flag-- > 1) //（フィールド幅-1）×空白文字
		write(1, " ", 1);
}
void	non_minus_field_c(all_type_conversion_specifier *memo)
{
	while (memo->width_flag-- > 1)
	{
		if (memo->zero_flag == true)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	write(1, &memo->c, 1);
}

void	print_c(all_type_conversion_specifier *memo)
{
	if (memo->minus_flag == true)
		minus_field_c(memo);
	else
	{
		non_minus_field_c(memo);
	}
}
