#include "ft_printf.h"

int main(void)
{
  char *pointer;

  setlocale(LC_ALL, "en_US.UTF-8");

  ft_printf("ft_printf: |%lc %lc %lc %lc %lc %lc|\n", 0x2D4E, 0x2D3B, 0x2D4F, 0x2D4F, 0x2D30, 0x2D37);
  printf("   printf: |%C %C %C %C %C %C|\n", 0x2D4E, 0x2D3B, 0x2D4F, 0x2D4F, 0x2D30, 0x2D37);

  return 0;
}
