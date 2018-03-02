#include "ft_printf.h"

void buffer_fill(char *location, t_env *e, int length)
{
  int i = 0;

  while (i < length)
  {
    e->buffer[e->buffer_index] = location[i];
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
