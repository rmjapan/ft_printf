/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:05:04 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/12/15 22:55:30 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

void	process_minus_flag(all_type_conversion_specifier *memo)
{
	if (memo->width_flag != -1)
	{
		if (memo->precision_flag != -1)
		{// マイナスフラグ+フィールド幅＋精度パターンが最大
		//変換指定子のタイプによって場合わけ
		//　数値系（d,i,u,x,X）の場合
		//正の場合:（値が正の場合）[精度幅ー値の長さ]×’0’+[値の出力]+([フィールド幅ー値の長さ]-[精度幅ー値の長さ])×空白文字（ただし、各計算で値が負の場合は0とする）
        //負の場合は、(d,i)の場合、'-'+[精度幅-値の長さ]×'0'+[値の出力]+([フィールド幅-値の長さ]-[精度幅-値の長さ]-1）×空白文字（ただし、各計算で値が負の場合は0とする）
		//x,Xの場合における負の値の扱いに対処する必要がある。
		//文字系（c,s,p）の場合
           
        
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