#include "ft_printf.h"

static void precision_handle(t_env *e, char *precision)
{
  int i;
  int n;

  i = 1;
  n = 0;
  while (ft_isdigit(precision[i]))
  {
    n = n * 10 + precision[i] - 48;
    i++;
  }
  e->precision = n;
  if (!e->precision)
    e->empty_precision = 1;
  e->padding_0 = 0;
}

int precision_find(t_env *e, char *precision)
{
  if (ft_substr(".", precision[0]) && !e->length && !e->type)
  {
    if (e->precision)
      ft_error(2);
    precision_handle(e, precision);
    return (1);
  }
  else if (ft_isdigit(precision[0]) && e->precision && !e->length && !e->type)
    return (1);
  else
    return(0);
}
