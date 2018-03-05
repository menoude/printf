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

// sinon (autre carac, dont null byte) je lance une erreur
}

void conversion_start(t_env *e, char *format, int *index)
{
  // conversion_init
  conversion_set(e, format, index);
  // conversion_run
}
