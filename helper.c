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

int helper_substr(char *haystack, char needle)
{
  const char *s;

  s = (const char *) haystack;
  return (ft_strchr(s, needle) != NULL);
}
