/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:55:12 by meyami            #+#    #+#             */
/*   Updated: 2018/03/21 22:15:36 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include "./libft/includes/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>

# define BUFFER_SIZE 1000
# define UTF_MAX 1114111

typedef struct	s_env
{
	void	(*types[256]) (struct s_env *);
	char	buffer[BUFFER_SIZE];
	int		buffer_index;
	int		nb_printed;
	int		left_align;
	int		alternate_form;
	int		padding_0;
	int		pre_space;
	int		plus_sign;
	int		width;
	int		precision;
	int		has_precision;
	int		precision_zero;
	int		length;
	int		shift;
	int		type;
	int		neg;
	int		err;
	va_list	args;
}				t_env;

int				ft_printf(char *format, ...);

void			ft_error(int code);
int				ft_substr(char *haystack, char needle);
long int		ft_abs_value(long int number);
int				ft_wcharlen(int c);
int				ft_wstrlen(t_env *e, int *str);

char			*itoa_long(t_env *e, long int n);
char			*itoa_long_base(t_env *e, unsigned long int n,
								int base, char *symbols);

void			initializer_init(t_env *e);
void			initializer_types_init(t_env *e);
void			initializer_reset(t_env *e);

void			buffer_fill_char(t_env *e, char c, int n);
void			buffer_fill_string(t_env *e, char *str, int n);
void			buffer_fill_utf_char(t_env *e, int c);
void			buffer_fill_utf_string(t_env *e, int *str, int n);
void			buffer_print(t_env *e);

void			converter_parse(t_env *e, char *format, int *index);
void			converter_convert(t_env *e, char *flag);

int				format_find(t_env *e, char format);
int				width_find(t_env *e, char *width);
int				precision_find(t_env *e, char *precision);
int				length_find(t_env *e, char *length);
int				type_find(char type);

void			type_d_i(t_env *e);
void			type_ld(t_env *e);
void			type_c(t_env *e);
void			type_s(t_env *e);
void			type_lc(t_env *e);
void			type_ls(t_env *e);
void			type_o(t_env *e);
void			type_lo(t_env *e);
void			type_x(t_env *e);
void			type_maj_x(t_env *e);
void			type_u(t_env *e);
void			type_lu(t_env *e);
void			type_p(t_env *e);
void			type_percent(t_env *e);
void			type_b(t_env *e);

#endif
