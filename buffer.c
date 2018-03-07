#include "ft_printf.h"

void buffer_fill (t_env *e, char *str, int mode)
{
  int i;

  i = 0;
  if (mode == 1)
  {
    e->buffer[e->buffer_index] = str[0];
    e->buffer_index++;
    if (e->buffer_index == BUFFER_SIZE)
      buffer_print(e);
  }
  else if (mode == 2)
  {
    while (str[i])
    {
      e->buffer[e->buffer_index] = str[i];
      e->buffer_index++;
      i++;
      if (e->buffer_index == BUFFER_SIZE)
        buffer_print(e);
    }
  }
}

void buffer_print(t_env *e)
{
  write(1, e->buffer, e->buffer_index);
  e->nb_printed += e->buffer_index;
  e->buffer_index = 0;
}
