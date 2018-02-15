#include "ft_printf.h"

int   ft_printf(char *format, ...)
{
  va_list list;

  va_start(list, format);
  int i = 0;
  //
  while (i < 2)
  {
    printf("%s", va_arg(list, char *));
    i++;
  }
  return 0;
}
