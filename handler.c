#include "ft_printf.h"

void handler_d(t_env *e)
{
    char *str;
    int len;

    str = ft_itoa(va_arg(e->args, int));
    len = ft_strlen(str);
    e->type = 1;
    buffer_fill(e, str, len);
}
