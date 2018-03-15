#include "ft_printf.h"

void initializer_init(t_env *e)
{
  *e = (t_env) {
    .buffer_index = 0,
    .nb_printed = 0,
    .left_align = 0,
    .alternate_form = 0,
    .padding_0 = 0,
    .pre_space = 0,
    .plus_sign = 0,
    .width = 0,
    .precision = 0,
    .has_precision = 0,
    .precision_zero = 0,
    .length = 0,
    .shift = 32,
    .type = 0,
    .neg = 0
  };
  ft_bzero(e->buffer, BUFFER_SIZE);
}

void initializer_reset(t_env *e)
{
    e->left_align = 0;
    e->alternate_form = 0;
    e->padding_0 = 0;
    e->pre_space = 0;
    e->plus_sign = 0;
    e->width = 0;
    e->precision = 0;
    e->has_precision = 0;
    e->precision_zero = 0;
    e->length = 0;
    e->shift = 32;
    e->type = 0;
    e->neg = 0;
}
