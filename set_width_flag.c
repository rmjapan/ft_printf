#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"
all_type_conversion_specifier	*set_witdth_flag(all_type_conversion_specifier *memo,
		char *format)
{
	if (memo->minus_flag == true || memo->zero_flag == true)
		format++;
	if (memo->minus_flag == true && memo->zero_flag == true)
		format++;
	memo->width_flag = ft_atoi(format);
	return (memo);
}

