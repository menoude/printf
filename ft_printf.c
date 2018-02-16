#include "ft_printf.h"

int   ft_printf(char *format, ...)
{
  va_list list;
  int i;

  va_start(list, format);
  i = 0;
  while (format[i])
  {
    if (format[i] == '%')
    {
        if (format[i + 1] == 's')
        {
          i++;
          ft_putstr(va_arg(list, char *));
        }
        else if (format[i + 1] == 'd')
        {
          i++;
          ft_putnbr(va_arg(list, int));
        }
    }
    else
    {

    ft_putchar(format[i]);
  }
  i++;
  }
  return 0;
}
