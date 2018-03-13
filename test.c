#include "ft_printf.h"

int main(void)
{
  char *pointer;

  ft_printf("ft_printf: |%lld|\n", -9223372036854775808);

  printf("   printf: |%lld|\n", -9223372036854775808);

  return 0;
}
