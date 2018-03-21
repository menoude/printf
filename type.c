#include "ft_printf.h"

int type_find(char type)
{
  return ft_substr("sSpdDioOuUxXcC", type);
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
  n = (n << e->shift) >> e->shift;
  s = itoa_long(e, n);
  len = ft_strlen(s);
  padding = e->precision > len ? e->width - e->precision : e->width - len;
  padding -= (e->neg || (e->plus_sign && n >= 0));
  buffer_fill_char(e, ' ', e->pre_space && !e->neg && !e->plus_sign);
  padding -= e->pre_space && !e->neg && !e->plus_sign;
  buffer_fill_char(e, ' ', e->left_align ? 0 : padding * !e->padding_0);
  buffer_fill_char(e, '+', e->plus_sign && n >= 0);
  buffer_fill_char(e, '-', e->neg);
  buffer_fill_char(e, '0', e->left_align ? 0 : padding * e->padding_0);
  buffer_fill_char(e, '0', e->precision > len ? e->precision - len : 0);
  buffer_fill_string(e, s, len);
  buffer_fill_char(e, ' ', e->left_align ? padding : 0);
  free(s);
}

void type_c(t_env *e)
{
  char c;
  int padding;

  if (!e->shift)
  {
    types('C')(e);
    return ;
  }
  c = (char) va_arg(e->args, int);
  padding = e->width > 1 ? e->width - 1 : 0;
  buffer_fill_char(e, ' ', !e->left_align ? padding : 0);
  buffer_fill_char(e, c, 1);
  buffer_fill_char(e, ' ', e->left_align ? padding : 0);
}

void type_s(t_env *e)
{
  char *s;
  int padding;
  int len;
  int to_free;

  if (!e->shift)
  {
    types('S')(e);
    return ;
  }
  to_free = 0;
  s = va_arg(e->args, char *);
  if (s == NULL)
  {
    s = ft_strdup("(null)");
    to_free++;
  }
  len = ft_strlen(s);
  len = e->has_precision && len > e->precision ? e->precision : len;
  padding = e->width > len ? e->width - len : 0;
  buffer_fill_char(e, ' ', !e->left_align ? padding : 0);
  buffer_fill_string(e, s, len);
  buffer_fill_char(e, ' ', e->left_align ? padding : 0);
  if (to_free)
  free(s);
}

void type_C(t_env *e)
{
  int c;
  int padding;

  c = va_arg(e->args, int);
  if (c < 0 || (c > 127 && MB_CUR_MAX <= 1) || c > UTF_MAX
  || (c >= 0xD800 && c <= 0xDFFF))
  {
    e->err = 1;
    return ;
  }
  padding = e->width > 1 ? e->width - 1 - (c > 127) - (c > 2047) - (c > 65535) : 0;
  buffer_fill_char(e, ' ', !e->left_align ? padding : 0);
  buffer_fill_UTF_char(e, c);
  buffer_fill_char(e, ' ', e->left_align ? padding : 0);
}

void type_S(t_env *e)
{
  int *str;
  int padding;
  int len;

  str = va_arg(e->args, int *);
  len = ft_wstrlen(str);
  if (len == -2)
  {
    len = e->has_precision && e->precision < 6 ? e->precision : 6;
    padding = e->width > len ? e->width - len : 0;
    buffer_fill_char(e, ' ', !e->left_align ? padding : 0);
    buffer_fill_UTF_string(e, L"(null)", len);
    buffer_fill_char(e, ' ', e->left_align ? padding : 0);
  }
  else if (len == -1)
    e->err = 1;
  else
  {
    len = e->has_precision && e->precision < len ? e->precision : len;
    padding = e->width > len ? e->width - len : 0;
    buffer_fill_char(e, ' ', !e->left_align ? padding : 0);
printf("padding %d\n", padding);
    padding -= buffer_fill_UTF_string(e, str, len);
    printf("padding %d\n", padding);
    buffer_fill_char(e, ' ', e->left_align ? padding : 0);
  }
}

void type_p(t_env *e)
{
  unsigned long int n;
  char *s;
  int len;
  int padding;

  n = va_arg(e->args, unsigned long int);
  s = itoa_long_base(e, n, 16, "0123456789abcdef");
  len = ft_strlen(s);
  padding = e->width > len ? e->width - len - 2 : 0;
  buffer_fill_char(e, ' ', e->left_align ? 0 : padding);
  buffer_fill_string(e, "0x", 2);
  buffer_fill_string(e, s, len);
  buffer_fill_char(e, ' ', e->left_align ? padding : 0);
  free(s);
}

void type_D(t_env *e)
{
  e->shift = 0;
  types('d')(e);
}

void type_o(t_env *e)
{
  unsigned long int n;
  char *s;
  int len;
  int padding;

  n = va_arg(e->args, unsigned long int);
  n = (n << e->shift) >> e->shift;
  s = itoa_long_base(e, n, 8, "012345678");
  len = ft_strlen(s);
  if (e->precision > len)
  e->alternate_form = 0;
  e->precision = e->precision < len ? len : e->precision;
  padding = e->width > e->precision ?
  e->width - e->precision -
  (e->alternate_form && s[0] != '0') : 0;
  buffer_fill_char(e, ' ', e->pre_space && !padding);
  buffer_fill_char(e, '0', e->alternate_form && len && s[0] != '0' && !padding);
  buffer_fill_char(e, e->padding_0 ? '0' : ' ', e->left_align ? 0 : padding);
  buffer_fill_char(e, '0', e->alternate_form && len && s[0] != '0' && padding);
  buffer_fill_char(e, '0', e->precision > len ? e->precision - len : 0);
  if (!(!n && e->precision_zero && !e->alternate_form))
  buffer_fill_string(e, len ? s : "0", !len ? 1 : len);
  buffer_fill_char(e, ' ', e->left_align ? padding : 0);
  free(s);
}

void type_O(t_env *e)
{
  e->shift = 0;
  types('o')(e);
}

void type_x(t_env *e)
{
  unsigned long int n;
  char *s;
  int len;
  int padding;

  n = va_arg(e->args, unsigned long int);
  n = (n << e->shift) >> e->shift;
  s = itoa_long_base(e, n, 16, "0123456789abcdef");
  len = ft_strlen(s);
  e->precision = e->precision < len ? len : e->precision;
  padding = e->width > e->precision ?
  e->width - e->precision - e->alternate_form * 2 * (n != 0) : 0;
  buffer_fill_char(e, ' ', e->pre_space && !padding);
  buffer_fill_string(e, "0x", e->alternate_form * 2 * (n != 0 && e->padding_0));
  buffer_fill_char(e, e->padding_0 ? '0' : ' ', e->left_align ? 0 : padding);
  buffer_fill_string(e, "0x", e->alternate_form * 2 * (n != 0 && !e->padding_0));
  buffer_fill_char(e, '0', e->precision > len ? e->precision - len : 0);
  buffer_fill_string(e, s, len);
  buffer_fill_char(e, ' ', e->left_align ? padding : 0);
  free(s);
}

void type_X(t_env *e)
{
  unsigned long int n;
  char *s;
  int len;
  int padding;

  n = va_arg(e->args, unsigned long int);
  n = (n << e->shift) >> e->shift;
  s = itoa_long_base(e, n, 16, "0123456789ABCDEF");
  len = ft_strlen(s);
  e->precision = e->precision < len ? len : e->precision;
  padding = e->width > e->precision ?
  e->width - e->precision - e->alternate_form * 2 * (n != 0) : 0;
  buffer_fill_char(e, ' ', e->pre_space && !padding);
  buffer_fill_string(e, "0X", e->alternate_form * 2 * (n != 0 && e->padding_0));
  buffer_fill_char(e, e->padding_0 ? '0' : ' ', e->left_align ? 0 : padding);
  buffer_fill_string(e, "0X", e->alternate_form * 2 * (n != 0 && !e->padding_0));
  buffer_fill_char(e, '0', e->precision > len ? e->precision - len : 0);
  buffer_fill_string(e, s, len);
  buffer_fill_char(e, ' ', e->left_align ? padding : 0);
  free(s);
}


void type_u(t_env *e)
{
  long unsigned int n;
  char *s;
  int len;
  int padding;

  n = va_arg(e->args, long unsigned int);
  n = (n << e->shift) >> e->shift;
  s = itoa_long_base(e, n, 10, "0123456789");
  len = ft_strlen(s);
  e->precision = e->precision < len ? len : e->precision;
  padding = e->width > e->precision ? e->width - e->precision : 0;
  buffer_fill_char(e, e->padding_0 ? '0' : ' ', e->left_align ? 0 : padding);
  buffer_fill_char(e, '0', e->precision > len ? e->precision - len : 0);
  buffer_fill_string(e, s, len);
  buffer_fill_char(e, ' ', e->left_align ? padding : 0);
  free(s);
}

void type_U(t_env *e)
{
  e->shift = 0;
  types('u')(e);
}

void type_percent(t_env *e)
{
  int padding;

  padding = e->width > 1 ? e->width - 1 : 0;
  buffer_fill_char(e, e->padding_0 ? '0' : ' ', !e->left_align ? padding : 0);
  buffer_fill_char(e, '%', 1);
  buffer_fill_char(e, ' ', e->left_align ? padding : 0);
}
