#include "ft_printf.h"

void initializer_init(t_env *e)
{
  *e = (t_env) {
    .buffer_index = 0,
    .nb_printed = 0,
    .left_align = 0,
    .alternate_form = 0,
    .padding_sym = ' ',
    .plus_sign = 0,
    .width = 0,
    .precision = 0,
    .length = 0,
    .len_short = 0,
    .len_long = 0,
    .type = 0,
    .neg = 0
  };
  ft_bzero(e->buffer, BUFFER_SIZE);
}

void initializer_reset(t_env *e)
{
    e->left_align = 0;
    e->alternate_form = 0;
    e->padding_sym = ' ';
    e->plus_sign = 0;
    e->width = 0;
    e->precision = 0;
    e->length = 0;
    e->len_short = 0;
    e->len_long = 0;
    e->type = 0;
    e->neg = 0;
}
