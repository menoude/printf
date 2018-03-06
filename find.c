#include "ft_printf.h"

int find_format(t_env *e, char c)
{
  return (helper_substr(" #-+0", c) && !e->width && !e->precision && !e->length && !e->type);
}
int find_width(t_env *e, char c)
{
  return (helper_substr("0123456789", c) && !e->precision && !e->length && !e->type);
}
int find_precision(t_env *e, char c)
{
  return (helper_substr(".", c) && !e->length && !e->type);
}
int find_length(t_env *e, char *c)
{
  if (c[1])
    return (helper_substr("hljz", *c) && !e->type);
  else
    return (helper_substr("hljz", *c) && helper_substr("hljz", c[1]) && !e->type);
    // est-ce que si j'ai un null byte juste après le premier caractere ça fait buguer helper_substr a cause de ft_strchr ?
}
int find_type(char c)
{
  return helper_substr("sSpdDioOuUxXcC", c);
}
