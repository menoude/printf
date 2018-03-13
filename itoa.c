#include "ft_printf.h"

static void	itoa_set_vars(long int *n, int *digits)
{
  long int copy;

  copy = *n;
  *digits = 0;
  while (copy)
  {
    copy /= 10;
    *digits = *digits + 1;
  }
}

char		*itoa_long(t_env *e, long int n)
{
  char		*str;
  int			digits;

  if (!n && !e->empty_precision)
    return (ft_strdup("0"));
  else if (!n && e->empty_precision)
    return (ft_strdup(""));
  if (n < 0)
  {
    e->neg = 1;
    e->pre_space = 0;
    n *= -1;
  }
  itoa_set_vars(&n, &digits);
  if (!(str = malloc(sizeof(char) * digits + 1)))
    return (0);
  str[digits] = 0;
  digits--;
  while (digits >= 0)
  {
    str[digits] = ft_abs_value(n % (long int) 10) + 48;
    n /= 10;
    digits--;
  }
  return (str);
}
