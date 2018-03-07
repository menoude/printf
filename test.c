#include "ft_printf.h"

int main(void)
{
  char *pointer;
  
  ft_printf("placeholder right here: %s, %p it's over\n", "hey ho", pointer);

  printf("placeholder right here: %%, %p it's over\n", pointer);

  return 0;
}
