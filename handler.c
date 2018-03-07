#include "ft_printf.h"

void (*handler(int action))(t_env *e)
{
  static void (*handlers[256]) (struct s_env *) =
  {
    ['d'] = &handler_d,
    ['D'] = &handler_D,
    ['i'] = &handler_i,
    ['s'] = &handler_s,
    ['S'] = &handler_S,
    ['p'] = &handler_p,
    ['o'] = &handler_o,
    ['O'] = &handler_O,
    ['u'] = &handler_u,
    ['U'] = &handler_U,
    ['x'] = &handler_x,
    ['X'] = &handler_X,
    ['c'] = &handler_c,
    ['C'] = &handler_C
  };

  return (handlers[action]);
}

void handler_d(t_env *e)
{
    char *str;

    str = ft_itoa(va_arg(e->args, int));
    buffer_fill(e, str, 2);
    e->type = 1;
}

void handler_s(t_env *e)
{
  buffer_fill(e, va_arg(e->args, char *), 2);
  e->type = 1;
}

void handler_p(t_env *e)
{
  long int address;
  char *str;

  address = (long int) va_arg(e->args, void *);
  str = ft_itoa(address);
  buffer_fill(e, str, 2);
  e->type = 1;
}

void handler_S(t_env *e)
{
  e->type = 1;
}
void handler_D(t_env *e)
{
e->type = 1
}

void handler_i(t_env *e)
{
e->type = 1
}

void handler_o(t_env *e)
{
e->type = 1
}

void handler_O(t_env *e)
{
e->type = 1
}

void handler_x(t_env *e)
{
e->type = 1
}

void handler_X(t_env *e)
{
e->type = 1
}

void handler_c(t_env *e)
{
e->type = 1
}

void handler_C(t_env *e)
{
e->type = 1
}

void handler_u(t_env *e)
{
e->type = 1
}

void handler_U(t_env *e)
{
e->type = 1
}
