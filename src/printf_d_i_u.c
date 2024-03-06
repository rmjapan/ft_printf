/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d_i_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:44:54 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/03/06 13:30:53 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//この関数は、変換指定子の種類毎に文字列に変換する関数を呼びだすための関数です。
char	*ft_itoa_d_i_u(t_printf_format *memo)
{
	if (memo->type == 4)
	{
		return (ft_itoa(memo->d));
	}
	else if (memo->type == 5)
	{
		return (ft_itoa(memo->i));
	}
	else
	{
		return (ft_itoa_u(memo->u));
	}
}

void	minus_field_precision_d_i_u(t_printf_format *memo,
		long long value_d_i_u, int *return_result)
{
	char			*value;
	char			*value_p;
	unsigned int	prec_minus_len;
	int				width_prec_len;

	value = ft_itoa_d_i_u(memo);
	value_p = value;
	if (value_d_i_u < 0)
	{
		write(1, "-", 1);
		value++;
	}
	*return_result += ft_strlen(value);
	prec_minus_len = a_minus_b(memo->precsion_width, ft_strlen(value));
	width_prec_len = a_minus_b(memo->field_width, ft_strlen(value))
		- prec_minus_len;
	if (value_d_i_u < 0)
		width_prec_len--;
	*return_result += width_prec_len + prec_minus_len;
	while (prec_minus_len-- > 0)
		write(1, "0", 1);
	write(1, value, ft_strlen(value));
	while (width_prec_len-- > 0)
		write(1, " ", 1);
	free(value_p);
}

void	zero_field_d_i_u(t_printf_format *memo, long long value_d_i_u,
		int *return_result)
{
	char	*value;
	char	*value_p;
	int		len;
	int		width_minus_len;

	value = ft_itoa_d_i_u(memo);
	value_p = value;
	len = ft_strlen(value);
	*return_result += len;
	width_minus_len = a_minus_b(memo->field_width, len);
	if (value_d_i_u < 0)
	{
		write(1, "-", 1);
		value++;
	}
	while (width_minus_len-- > 0)
	{
		write(1, "0", 1);
		*return_result += 1;
	}
	write(1, value, len);
	free(value_p);
}

void	field_precision_d_i_u(t_printf_format *memo, long long value_d_i_u,
		int *return_result)
{
	char			*value;
	char			*value_p;
	unsigned int	pre_minus_len;
	int				wid_pr_len;
	int				pivot;

	pivot = 0;
	value = ft_itoa_d_i_u(memo);
	value_p = value;
	if (value_d_i_u < 0)
	{
		value++;
		pivot++;
	}
	pre_minus_len = a_minus_b(memo->precsion_width, ft_strlen(value));
	wid_pr_len = a_minus_b(memo->field_width, ft_strlen(value)) - pre_minus_len;
	*return_result += wid_pr_len + pre_minus_len + ft_strlen(value_p);
	while (wid_pr_len-- > pivot)
		write(1, " ", 1);
	if (value_d_i_u < 0)
		write(1, "-", 1);
	while (pre_minus_len-- > 0)
		write(1, "0", 1);
	write(1, value, ft_strlen(value));
	free(value_p);
}

// long long 型に変換するのは、int型の最小値、最大値の範囲の数値を処理可能で、かつunsigned　int型の最大値も処理可能だからです。
void	printf_d_i_u(t_printf_format *memo, int *return_result)
{
	long long	value_d_i_u;

	if (memo->type == 4)
	{
		value_d_i_u = memo->d;
	}
	if (memo->type == 5)
	{
		value_d_i_u = memo->i;
	}
	if (memo->type == 6)
	{
		value_d_i_u = memo->u;
	}
	if (memo->minus_flag == true)
		minus_field_precision_d_i_u(memo, value_d_i_u, return_result);
	else if (memo->zero_flag == true)
	{
		zero_field_d_i_u(memo, value_d_i_u, return_result);
	}
	else
	{
		field_precision_d_i_u(memo, value_d_i_u, return_result);
	}
}
