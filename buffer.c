#include "ft_printf.h"

void add_to_buffer(char *location, t_printer *printer, int length)
{
  int i = 0;

  while (i < length)
  {
    printer->buffer[printer->buffer_index] = location[i];
    printer->buffer_index++;
    i++;
    if (printer->buffer_index == BUFFER_SIZE)
      buffer_flush(printer);
  }
}

void buffer_flush(t_printer *printer)
{
  write(1, printer->buffer, BUFFER_SIZE);
  printer->nb_printed += BUFFER_SIZE;
  printer->buffer_index = 0;
}

void buffer_print(t_printer *printer)
{
  write(1, printer->buffer, printer->buffer_index);
  printer->nb_printed += printer->buffer_index;
}
