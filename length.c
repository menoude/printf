#include "ft_printf.h"

static void length_handle(t_env *e, char *length)
{
  if ((length[0] == 'l' && length[1] == 'l')
  || length[0] == 'l' || length[0] == 'z'
  || length[0] == 'j')
    e->len_long = 1;
  else if ((length[0] == 'h' && length[1] == 'h')
  || length[0] == 'h')
    e->len_short = 1;
}

int length_find(t_env *e, char *length)
{
  if (!e->type
    && ((length[0] == 'l' && length[1] == 'l')
    || (length[0] == 'h' && length[1] == 'h') || helper_substr("hljz", length[0])))
    {
      if (!e->length)
        length_handle(e, length);
      e->length = 1;
      return (1);
    }
    else
      return (0);
  }
