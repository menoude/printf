#include "ft_printf.h"

void throw_err(int code)
{
  if (code == 1)
    ft_putendl("an error occured");
  else if (code == 2)
  {
    //
  }
  exit(0);
}
