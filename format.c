#include "ft_printf.h"

static void format_handle(t_env *e, char c)
{
  if (c == '-')
    e->left_align = 1;
  else if (c == '+')
  {
    e->plus_sign = 1;
    e->pre_space = 0;
  }
  else if (c == ' ' && !e->plus_sign)
    e->pre_space = 1;
  else if (c == '0')
    e->padding_0 = 1;
  else if (c == '#')
    e->alternate_form = 1;
}

int format_find(t_env *e, char format)
{
  if (ft_substr(" #-+0", format) && !e->width && !e->precision
      && !e->length && !e->type)
  {
    format_handle(e, format);
    return (1);
  }
  else
    return (0);
}
