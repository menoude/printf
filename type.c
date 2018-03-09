#include "ft_printf.h"

int type_find(char type)
{
  return helper_substr("sSpdDioOuUxXcC", type);
}

void (*types(int action))(t_env *e)
{
  static void (*types[256]) (struct s_env *) =
  {
    ['d'] = &type_d_i,
    ['D'] = &type_D,
    ['i'] = &type_d_i,
    ['s'] = &type_s,
    ['S'] = &type_S,
    ['p'] = &type_p,
    ['o'] = &type_o,
    ['O'] = &type_O,
    ['u'] = &type_u,
    ['U'] = &type_U,
    ['x'] = &type_x,
    ['X'] = &type_X,
    ['c'] = &type_c,
    ['C'] = &type_C,
    ['%'] = &type_percent
  };

  return (types[action]);
}

void type_d_i(t_env *e)
{
  long int n;
  char *s;
  int len;
  int padding;

  n = va_arg(e->args, long int);
  if (e->len_short)
    n = (n << 48) >> 48;
  else if (!e->len_long)
    n = (n << 32) >> 32;
  s = itoa_long(e, n);
  len = ft_strlen(s);
  e->precision = e->precision < len ? len : e->precision;
  padding = e->width > e->precision ? e->width - e->precision : 0;
  buffer_fill_char(e, e->padding_sym, e->left_align ? 0 : padding);
  buffer_fill_char(e, e->neg ? '-' : '+', (e->plus_sign && !e->neg) || e->neg);
  buffer_fill_char(e, '0', e->precision > len ? e->precision - len : 0);
  buffer_fill_string(e, s);
  buffer_fill_char(e, ' ', e->left_align ? padding : 0);
  free(s);
  e->type = 1;
}

void type_s(t_env *e)
{
  e->type = 1;
}

void type_p(t_env *e)
{
  e->type = 1;
}

void type_S(t_env *e)
{
  e->type = 1;
}
void type_D(t_env *e)
{
  e->type = 1;
}

void type_o(t_env *e)
{
  e->type = 1;
}

void type_O(t_env *e)
{
  e->type = 1;
}

void type_x(t_env *e)
{
  e->type = 1;
}

void type_X(t_env *e)
{
  e->type = 1;
}

void type_c(t_env *e)
{
  e->type = 1;
}

void type_C(t_env *e)
{
  e->type = 1;
}

void type_u(t_env *e)
{
  e->type = 1;
}

void type_U(t_env *e)
{
  e->type = 1;
}

void type_percent(t_env *e)
{
  e->type = 1;
}
