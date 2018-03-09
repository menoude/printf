#include "ft_printf.h"

int main(void)
{
  char *pointer;

  ft_printf("placeholder right here: %10.5d it's over\n", 30);

  printf("placeholder right here: %10.5d it's over\n", 30);

  return 0;
}
