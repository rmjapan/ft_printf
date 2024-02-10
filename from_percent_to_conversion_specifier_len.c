#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#

unsigned int from_percent_to_conversion_specifier_len(const char *format)
{
    const char *p = format;
    unsigned int len = 0;
    while (!is_conversion_specifier(p[len++]))
        ;
    return (len);



}