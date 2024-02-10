#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"

unsigned int	a_minus_b(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (0);
}
void	minus_field_precision_p(all_type_conversion_specifier *memo)
{
	char			*p_value;
	unsigned int	p_len;
	unsigned int	width_minus_p_len;
	unsigned int	prec_minus_p_len;

	p_value = itoa_hexa(memo->p, 3);
	p_len = ft_strlen(p_value);
	width_minus_p_len = a_minus_b(memo->width_flag, p_len);
	prec_minus_p_len = a_minus_b(memo->precision_flag, p_len);
	write(1, "0x", 2);
	while (memo->precision_flag-- > (int)(p_len))
		write(1, "0", 1);
	write(1, p_value, sizeof(p_value));
	while (width_minus_p_len-- > prec_minus_p_len)
		write(1, " ", 1);
}

void	zero_field_precision_p(all_type_conversion_specifier *memo)
{
	char			*p_value;
	unsigned int	p_len;

	p_value = itoa_hexa(memo->p, 3);
	p_len = ft_strlen(p_value);
	write(1, "0x", 2);
	while (memo->width_flag-- > (int)(p_len + 2))
		write(1, "0", 1);
	write(1, p_value, sizeof(p_value));
}

void	field_precision_p(all_type_conversion_specifier *memo)
{
	char			*p_value;
	unsigned int	p_len;
	unsigned int	width_minus_p_len;
	unsigned int	prec_minus_p_len;

	p_value = itoa_hexa(memo->p, 3);
	p_len = ft_strlen(p_value);
	width_minus_p_len = a_minus_b(memo->width_flag, p_len);
	prec_minus_p_len = a_minus_b(memo->precision_flag, p_len);
	while (width_minus_p_len-- > prec_minus_p_len)
		write(1, " ", 1);
	write(1, "0x", 2);
	while (memo->precision_flag-- > (int)(p_len))
		write(1, "0", 1);
	write(1, p_value, sizeof(p_value));
}

void	print_p(all_type_conversion_specifier *memo)
{
	if (memo->minus_flag == true)
	{
		minus_field_precision_p(memo);
	}
	else if (memo->zero_flag == true)
	{
		zero_field_precision_p(memo);
	}
	else
	{
		field_precision_p(memo);
	}
}