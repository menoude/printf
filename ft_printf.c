#include "ft_printf.h"

int   ft_printf(char *format, ...)
{
  t_env e;
  int i;

  helper_init_e(&e);
  va_start(e.args, format);
  i = 0;
  while (format[i])
  {
    if (format[i] == '%')
      conversion_start(&e, format, &i);
    else
    {
      buffer_fill(&e, format + i, 1);
      i++;
    }
  }
  buffer_print(&e);
  va_end(e.args);
  return e.nb_printed;
}
