#include "ft_printf.h"

// s'il est dans les formats et qu'il n'y a pas de width/precision/length/type, alors on prend en compte ce qu'il veut dire
// sinon s'il est dans les width et qu'il n'y a pas de prec/len/type, j'applique au bon critere
// sinon s'il est dans les precs et qu'il n'y a pas de length / type alors j'applique
// sinon si c'est un length, j'applique
// sinon si c'est un type, j'applique et je break

int flag_format(t_env *e, char *c)
{
  return helper_substr(" #-+0", c) && !e->width && !e->precision && !e->length && !e->type);
}
int flag_width(t_env *e, char *c)
{
  return helper_substr("0123456789", c) && !e->precision && !e->length && !e->type);
}
int flag_precision(t_env *e, char *c)
{
  return helper_substr(".", c) && !e->length && !e->type);
}
int flag_length(t_env *e, char *c)
{
  return helper_substr("hljz", ) && !e->width && !e->precision && !e->length && !e->type);

}
int flag_type(t_env *e, char *c)
{
  return helper_substr(" #-+0") && !e->width && !e->precision && !e->length && !e->type);

}
