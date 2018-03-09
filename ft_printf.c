#include "ft_printf.h"

int   ft_printf(char *format, ...)
{
  t_env e;
  int i;

  initializer_init(&e);
  va_start(e.args, format);
  i = 0;
  while (format[i])
  {
    if (format[i] == '%')
    {
      converter_parse(&e, format, &i);
      initializer_reset(&e);
    }
    else
    {
      buffer_fill_char(&e, format[i], 1);
      i++;
    }
  }
  buffer_print(&e);
  va_end(e.args);
  return e.nb_printed;
}
