#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

unsigned int	identify_conversion_specifier_type(char c) //変換指定子の型を識別する
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'd')
		return (4);
	else if (c == 'i')
		return (5);
	else if (c == 'u')
		return (6);
	else if (c == 'x')
		return (7);
	else if (c == 'X')
		return (8);
	else
		return (0);
}

void set_conversion_specifier_type(all_type_conversion_specifier *all_type_conversion_specifier, unsigned int conversion_specifier_type, va_list target)
{
    all_type_conversion_specifier->type = conversion_specifier_type;
}

void set_conversion_specifier_value(all_type_conversion_specifier *all_type_conversion_specifier, va_list target)
{
    if (all_type_conversion_specifier->type == 1)
        all_type_conversion_specifier->c = va_arg(target, int);
    else if (all_type_conversion_specifier->type == 2)
        all_type_conversion_specifier->s = va_arg(target, char *);
    else if (all_type_conversion_specifier->type == 3)
        all_type_conversion_specifier->p = va_arg(target, void *);
    else if (all_type_conversion_specifier->type == 4)
        all_type_conversion_specifier->d = va_arg(target, int);
    else if (all_type_conversion_specifier->type == 5)
        all_type_conversion_specifier->i = va_arg(target, int);
    else if (all_type_conversion_specifier->type == 6)
        all_type_conversion_specifier->u = va_arg(target, unsigned int);
    else if (all_type_conversion_specifier->type == 7)
        all_type_conversion_specifier->x = va_arg(target, unsigned int);
    else if (all_type_conversion_specifier->type == 8)
        all_type_conversion_specifier->X = va_arg(target, unsigned int);
}


all_type_conversion_specifier	*set_identified_type_conversion_specifier(all_type_conversion_specifier *all_type_conversion_specifier,
		char format, va_list target)
{
	unsigned int conversion_specifier_type = 0;
	conversion_specifier_type = identify_conversion_specifier_type(format);
    set_conversion_specifier_type(all_type_conversion_specifier, conversion_specifier_type, target);
    set_conversion_specifier_value(all_type_conversion_specifier, target);
    return (all_type_conversion_specifier);
}