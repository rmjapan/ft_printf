/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:05:04 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/12/14 21:30:13 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

void	process_minus_flag(all_type_conversion_specifier *memo)
{
	if (memo->width_flag != -1)
	{
		if (memo->precision_flag != -1)
		{
			// マイナスフラグ+フィールド幅＋精度パターンが最大
           if(場合わけ（変換指定子のタイプによって）)
           
           
        
		}
		else
		{
			// マイナスフラグ＋フィールド幅
		}
	}
	else if (memo->precision_flag != -1)
	{
		// マイナスフラグ＋精度パターン
	}
	// マイナスフラグのみ
}

void	process_zero_flag(all_type_conversion_specifier *memo)
{
	if (memo->width_flag)
	{
		// フィールド幅＋ゼロフラグ
	}
}

void	process_no_flags(all_type_conversion_specifier *memo)
{
	// マイナスフラグ＝false,ゼロフラグ=falseなので、フィールド幅＋精度パターン
}

void	printf_target(all_type_conversion_specifier *memo)
{
	if (memo->minus_flag == true)
	{
		process_minus_flag(memo);
	}
	else if (memo->zero_flag == true)
	{
		process_zero_flag(memo);
	}
	else
	{
		process_no_flags(memo);
	}
}