#include "ft_printf.h"

int main(void)
{
  char *pointer;

  setlocale(LC_ALL, "en_US.UTF-8");

  int val1 = ft_printf("ft_printf: |%-1C|\n", 2250);
  printf("%d\n", val1);

  int val2 = printf("   printf: |%-1C|\n", 2250);
  printf("%d\n", val2);

  return 0;
}

// 0x2D4E, 0x2D3B, 0x2D4F, 0x2D4F, 0x2D30, 0x2D37
// 0x2D4E, 0x2D3B, 0x2D4F, 0x2D4F, 0x2D30, 0x2D37
