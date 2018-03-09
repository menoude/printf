#include "ft_printf.h"

void helper_error(int code)
{
  if (code == 1)
  ft_putendl("an error occured");
  else if (code == 2)
  {
    //
  }
  exit(0);
}

void helper_init_e(t_env *e)
{
  *e = (t_env) {
    .buffer_index = 0,
    .nb_printed = 0,
    .left_align = 0,
    .alternate_form = 0,
    .padding_0 = 0,
    // .padding_space = 0,
    .plus_sign = 0,
    .width = 0,
    .precision = 0,
    .length = 0,
    .type = 0,
  };
  ft_bzero(e->buffer, BUFFER_SIZE);
}

int helper_substr(char *haystack, char needle)
{
  const char *s;

  s = (const char *) haystack;
  return (ft_strchr(s, needle) != NULL);
}

static void	helper_itoa_set_vars(int *neg, long int *n, int *digits)
{
  long int copy;

  copy = *n;
  *digits = 0;
  if (*n < 0)
  {
    *neg = 1;
    *n = *n * -1;
  }
  else
    *neg = 0;
  while (copy)
  {
    copy /= 10;
    *digits = *digits + 1;
  }
}

char		*helper_itoa(long int n)
{
  char		*str;
  int			digits;
  int			neg;

  if (!n)
    return (ft_strdup("0"));
  helper_itoa_set_vars(&neg, &n, &digits);
  if (!(str = malloc(sizeof(char) * digits + neg + 1)))
    return (0);
  str[digits + neg] = 0;
  digits = digits + neg - 1;
  while (digits - neg >= 0)
  {
    str[digits] = n % 10 + 48;
    n /= 10;
    digits--;
  }
  str[0] = neg ? '-' : str[0];
  return (str);
}
