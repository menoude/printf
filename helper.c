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

int ft_wstrlen(int *str)
{
  int i;
  int len;

  len = 0;
  i = 0;
  while (str[i])
  {
    if (str[i] < 0 || str[i] > UTF_MAX || (str[i] > 127 && MB_CUR_MAX <= 1)
        || (str[i] >= 0xD800 && str[i] <= 0xDFFF)) 
      return (-1);
    else if (str[i] > 65535)
      len += 4;
    else if (str[i] > 2047)
      len += 3;
    else if (str[i] > 127)
      len += 2;
    else
      len += 1;
    i++;
  }
  return (len);
}
