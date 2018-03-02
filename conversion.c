#include "ft_printf.h"

void conversion_parse(t_env *e, char *format, int *index)
{
  int i;

  i = *index;
  // tant que j'ai pas un type
  // je lis chaque caractere
  // s'il est dans les formats et que qu'il n'y a pas de width/precision/length/type, alors on prend en compte ce qu'il veut dire
  // sinon s'il est dans les width et qu'il n'y a pas de prec/len/type, j'applique au bon critere
   // sinon s'il est dans les precs et qu'il n'y a pas de length / type alors j'applique
   // sinon si c'est un length, j'applique
   // sinon si c'est un type, j'applique et je break
   // sinon (autre carac, dont null byte) je lance une erreur
}

void conversion_start(t_env *e, char *format, int *index)
{
  conversion_parse(e, format, index);
  
}
