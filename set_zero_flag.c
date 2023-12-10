#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

all_type_conversion_specifier	*set_zero_flag(all_type_conversion_specifier *memo,
		char *format)
{
	if (memo->minus_flag == true || memo->precision_flag != -1)
	{
		return memo;
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