#include "ft_printf.h"

int main(void)
{
  char *pointer;

  ft_printf("ft_printf: |%#.o %#.0o|\n", 0, 0);

  printf("   printf: |%#.o %#.0o|\n", 0, 0);

  return 0;
}
