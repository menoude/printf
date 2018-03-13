#include "ft_printf.h"

void ft_error(int code)
{
  if (code == 1)
  ft_putendl("an error occured");
  else if (code == 2)
  {
    ft_putendl("error");
  }
  exit(0);
}

int ft_substr(char *haystack, char needle)
{
  const char *s;

  s = (const char *) haystack;
  return (ft_strchr(s, needle) != NULL);
}

long int ft_abs_value(long int number)
{
  return (number < 0 ? number * -1 : number);
}
