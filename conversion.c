#include "ft_printf.h"

void conversion_read(t_env *e, char *format, int *index)
{
  int i;

  i = *index + 1;
  while (!find_type(format[i]))
  {
    if (find_format(e, format[i]) || find_width(e, format[i]) || find_precision(e, format[i]) || find_length(e, format + i) || format[i] == '%')
      conversion_crack(e, format + i);
    else
      helper_error(2);
    i++;
  }
  conversion_crack(e, format + i);
  i++;
  *index = i;
}

void conversion_crack(t_env *e, char *flag)
{
  int action;

  action = (int) *flag;
  handler(action)(e);
}

void conversion_start(t_env *e, char *format, int *index)
{
  // conversion_init
  conversion_read(e, format, index);
  // conversion_apply
}
