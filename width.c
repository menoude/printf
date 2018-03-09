#include "ft_printf.h"

static void width_handle(t_env *e, char *width)
{
  int i;
  int n;

  i = 0;
  n = 0;
  while (ft_isdigit(width[i]))
  {
    n += n * 10 +  width[i] - 48;
    i++;
  }
  e->width = n;
}

int width_find(t_env *e, char *width)
{
  if (helper_substr("0123456789", width[0]) && !e->precision && !e->length && !e->type)
  {
    if (!e->width)
      width_handle(e, width);
    return (1);
  }
  else
    return (0);
}
