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
  *e = (t_env) {.buffer_index = 0, .nb_printed = 0,
                .format = 0, .width = 0,
                .precision = 0, .length = 0,
                .type = 0};
  ft_bzero(e->buffer, BUFFER_SIZE);
}

int helper_substr(char *haystack, char *needle)
{
  const char *s;
  char *pos;

  s = (const char *) haystack;
  pos = ft_strchr(s, needle[0]);
  if (pos == NULL)
    return (0);
  else if (needle[1] == 'l' || needle[1] == 'h')
  {
    if (ft_strchr(pos, needle[1]) != NULL)
      return (1);
    else
      return (0);
  }
  else
    return (1);
}
