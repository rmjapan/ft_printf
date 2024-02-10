
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"
#include <stdio.h>
#include <string.h>

void	minus_field_precision_d_i_u(all_type_conversion_specifier *memo)
{
	char			*value_d;
	int				d_len;
	unsigned int	width_minus_d_len;
	unsigned int	prec_minus_d_len;
	int				width_prec_len;

	value_d = ft_itoa(memo->d); //文字列に変換
	if (memo->d < 0)
	{
		write(1, "-", 1);
		value_d++; //マイナスの場合は文字列の先頭をスキップ
	}
	d_len = ft_strlen(value_d); //文字列の長さを取得
	width_minus_d_len = a_minus_b(memo->width_flag, d_len);
	prec_minus_d_len = a_minus_b(memo->precision_flag, d_len);
	width_prec_len = width_minus_d_len - prec_minus_d_len;
	if (memo->d < 0)
	{
		width_prec_len--; //マイナスの場合は、マイナス記号の分を引く
	}
	while (prec_minus_d_len-- > 0)
		write(1, "0", 1);
	write(1, value_d, d_len);
	while (width_prec_len-- > 0)
		write(1, " ", 1);
}

void	zero_field_d_i_u(all_type_conversion_specifier *memo)
{
	char	*value_d;
	int		d_len;
	int		width_minus_d_len;

	value_d = ft_itoa(memo->d);
	d_len = ft_strlen(value_d);
	width_minus_d_len = a_minus_b(memo->width_flag, d_len);
		//フィールド幅から値の長さとマイナス記号の分を引く
	if (memo->d < 0)
	{
		write(1, "-", 1);
		value_d++; //マイナスの場合は文字列の先頭をスキップ
	}
	while (width_minus_d_len-- > 0)
		write(1, "0", 1);
	write(1, value_d, d_len);
}

void	field_precision_d_i_u(all_type_conversion_specifier *memo)
{
	char			*value_d;
	int				d_len;
	unsigned int	width_minus_d_len;
	unsigned int	prec_minus_d_len;
	int				width_prec_len;
	int				pivot;

	pivot = 0;
	value_d = ft_itoa(memo->d); //文字列に変換
	if (memo->d < 0)
	{
		value_d++; //マイナスの場合は文字列の先頭をスキップ
		pivot++;
	}
	d_len = ft_strlen(value_d);
	width_minus_d_len = a_minus_b(memo->width_flag, d_len);
	prec_minus_d_len = a_minus_b(memo->precision_flag, d_len);
	width_prec_len = width_minus_d_len - prec_minus_d_len;
	while (width_prec_len-- > pivot)
		write(1, " ", 1);
	if (memo->d < 0)
	{
		write(1, "-", 1);
	}
	while (prec_minus_d_len-- > 0)
		write(1, "0", 1);
	write(1, value_d, d_len);
}

void	print_d_i_u(all_type_conversion_specifier *memo)
{
	if (memo->minus_flag == true)
		minus_field_precision_d_i_u(memo);
	else if (memo->zero_flag == true)
	{
		zero_field_d_i_u(memo);
	}
	else
	{
		field_precision_d_i_u(memo);
	}
}
