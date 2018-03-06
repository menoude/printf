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
                .type = 0, .alternate = 0,
                .padding = 0, .precision_nb = 0,
                .alignment = 0};
  ft_bzero(e->buffer, BUFFER_SIZE);
}

int helper_substr(char *haystack, char needle)
{
  const char *s;

  s = (const char *) haystack;
  return (ft_strchr(s, needle) != NULL);
}
