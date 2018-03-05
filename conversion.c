#include "ft_printf.h"

void conversion_set(t_env *e, char *format, int *index)
{
  int i;

  (void)e;
  i = *index;
  while (!flag_type(e, format + i))
  {
    if (flag_format(e, format + i) || flag_width(e, format + i)
    || flag_precision(e, format + i) || flag_length(e, format + i) || format[i] == '%')
    {
      conversion_flag(format + i);
      i++;
    }
    else
      helper_error(2);
  }
  conversion_flag(format + i);
}
// tant que j'ai pas un type ou un pourcentage
// je lis chaque caractere
// s'il est dans les formats et qu'il n'y a pas de width/precision/length/type, alors on prend en compte ce qu'il veut dire
// sinon s'il est dans les width et qu'il n'y a pas de prec/len/type, j'applique au bon critere
// sinon s'il est dans les precs et qu'il n'y a pas de length / type alors j'applique
// sinon si c'est un length, j'applique
// sinon si c'est un type, j'applique et je break
// sinon (autre carac, dont null byte) je lance une erreur
}

void conversion_start(t_env *e, char *format, int *index)
{
  // conversion_init
  conversion_set(e, format, index);
  // conversion_run
}
