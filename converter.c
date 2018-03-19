#include "ft_printf.h"

void converter_parse(t_env *e, char *format, int *index)
{
  int i;

  i = *index + 1;
  while (!type_find(format[i]))
  {
    if (format_find(e, format[i]) || width_find(e, format + i) || precision_find(e, format + i) || length_find(e, format + i))
      i++;
    else if (format[i] == '%')
      break;
    else
      e->err = 1;
  }
  if (e->err)
    return ;
  converter_convert(e, format + i);
  i++;
  *index = i;
}

void converter_convert(t_env *e, char *type)
{
  int key;

  key = (int) *type;
  types(key)(e);
  e->type = 1;
}
