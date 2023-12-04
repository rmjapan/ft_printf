#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

all_type_conversion_specifier	*set_zero_flag(all_type_conversion_specifier *memo,
		char *format)
{
	if (memo->minus_flag == true)
	{
		if (*format + 1 == '0')
		{
			memo->zero_flag = true;
		}
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