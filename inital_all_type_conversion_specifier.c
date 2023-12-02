#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

all_type_conversion_specifier	*init_all_type_conversion_specifier(all_type_conversion_specifier *all_type_conversion_specifier)
{
	all_type_conversion_specifier = malloc(sizeof(all_type_conversion_specifier));

	all_type_conversion_specifier->type = 0;
	all_type_conversion_specifier->width_flag = -1;
	all_type_conversion_specifier->precision_flag = -1;
	all_type_conversion_specifier->minus_flag = false;
	all_type_conversion_specifier->zero_flag = false;
    all_type_conversion_specifier->c = 0;
	all_type_conversion_specifier->s = 0;
	all_type_conversion_specifier->p = 0;
	all_type_conversion_specifier->d = 0;
	all_type_conversion_specifier->i = 0;
	all_type_conversion_specifier->u = 0;
	all_type_conversion_specifier->x = 0;
	all_type_conversion_specifier->X = 0;
	return (all_type_conversion_specifier);
}