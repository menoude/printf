#include "ft_printf.h"

static void init_printer(t_printer *printer)
{
  printer->buffer_index = 0;
  printer->nb_printed = 0;
  ft_bzero(printer->buffer, BUFFER_SIZE);
}

int   ft_printf(char *format, ...)
{
  va_list list;
  int i;
  t_printer printer;
  va_start(list, format);

  init_printer(&printer);
  i = 0;
  while (format[i])
  {
    if (format[i] == '%')
      process_conversion(format, &printer, &i);
    else
    {
      add_to_buffer((void *)format + i, &printer, 1);
      i++;
    }
  }
  buffer_print(&printer);
  return printer.nb_printed;
}
