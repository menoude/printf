#include "ft_printf.h"

void conversion_read(t_env *e, char *format, int *index)
{
  int i;

  (void)e;
  i = *index;
  while (!find_type(format[i]))
  {
    if (find_format(e, format[i]) || find_width(e, format[i])
    || find_precision(e, format[i]) || find_length(e, format + i))
    {
      // fonction of that character
      i++;
    }
    else if (format[i] == '%')
    // fonction
    (void)e;
    else
      helper_error(2);
  }
}

void conversion_start(t_env *e, char *format, int *index)
{
  // conversion_init
  conversion_read(e, format, index);
  // conversion_apply
}
