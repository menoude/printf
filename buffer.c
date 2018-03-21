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

void buffer_fill_UTF_char(t_env *e, int c)
{
  if (c > 65535)
  {
    buffer_fill_char(e, (char) 0b11110000 | (0b111 & (c >> 18)), 1);
    buffer_fill_char(e, (char) 0b10000000 | (0b111111 & (c >> 12)), 1);
    buffer_fill_char(e, (char) 0b10000000 | (0b111111 & (c >> 6)), 1);
    buffer_fill_char(e, (char) 0b10000000 | (0b111111 & c), 1);
  }
  else if (c > 2047)
  {
    buffer_fill_char(e, (char) 0b11100000 | (0b1111 & (c >> 12)), 1);
    buffer_fill_char(e, (char) 0b10000000 | (0b111111 & (c >> 6)), 1);
    buffer_fill_char(e, (char) 0b10000000 | (0b111111 & c), 1);
  }
  else if (c > 127)
  {
      buffer_fill_char(e, 0b11000000 | (0b11111 & (c >> 6)), 1);
      buffer_fill_char(e, (char) 0b10000000 | (0b111111 & c), 1);
  }
  else
    buffer_fill_char(e, (char) c, 1);
}

int buffer_fill_UTF_string(t_env *e, int *str, int n)
{
  int i;

  i = 0;
  while (str[i] != 0 && i < n)
  {
    if (str[i] < 0 || (str[i] > 127 && MB_CUR_MAX <= 1)
        || str[i] > UTF_MAX || (str[i] >= 0xd800 && str[i] <= 0xDFFF ))
    {
      e->err = 1;
      return (0);
    }
    // faut comprendre le delire ici
    if (n - i > (str[i] > 127) + (str[i] > 2047) + (str[i] > 65535))
      buffer_fill_UTF_char(e, str[i]);
    else
      return ((str[i] > 127) + (str[i] > 2047) + (str[i] > 65535) - n - i);
    n -= (str[i] > 127) + (str[i] > 2047) + (str[i] > 65535);
    i++;
  }
  return (0);
}

void buffer_print(t_env *e)
{
  write(1, e->buffer, e->buffer_index);
  e->nb_printed += e->buffer_index;
  e->buffer_index = 0;
}
