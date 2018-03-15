#include "ft_printf.h"

void buffer_fill_char(t_env *e, char c, int n)
{
  int i;

  i = 0;
  while (i < n)
  {
    e->buffer[e->buffer_index] = c;
    e->buffer_index++;
    i++;
    if (e->buffer_index == BUFFER_SIZE)
      buffer_print(e);
  }
}

void buffer_fill_string(t_env *e, char *str, int n)
{
  int i;

  i = 0;
  while (str[i] && i < n)
  {
    e->buffer[e->buffer_index] = str[i];
    e->buffer_index++;
    i++;
    if (e->buffer_index == BUFFER_SIZE)
    buffer_print(e);
  }
}

void buffer_print(t_env *e)
{
  write(1, e->buffer, e->buffer_index);
  e->nb_printed += e->buffer_index;
  e->buffer_index = 0;
}
