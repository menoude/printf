/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:55:12 by meyami            #+#    #+#             */
/*   Updated: 2018/02/12 17:55:14 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include "./libft/includes/libft.h"
#include <stdarg.h>
# include <stdio.h> // a enlever !!!

#define BUFFER_SIZE 1000

typedef struct s_env
{
    char buffer[BUFFER_SIZE];
    int buffer_index;
    int nb_printed;
    int format;
    int width;
    int precision;
    int length;
    int type;
    int alternate;
    int sign;
    int padding;
    int precision_nb;
    int alignment;

    va_list args;
}             t_env;


int   ft_printf(char *format, ...);

void helper_error(int code);
void helper_init_e(t_env *e);
int helper_substr(char *haystack, char needle);

void buffer_fill(t_env *e, char *str, int length);
void buffer_print(t_env *e);

void conversion_start(t_env *e, char *format, int *index);
void conversion_read(t_env *e, char *format, int *index);
void conversion_crack(t_env *e, char *flag);

int find_format(t_env *e, char c);
int find_width(t_env *e, char c);
int find_precision(t_env *e, char c);
int find_length(t_env *e, char *c);
int find_type(char c);

void handler_d(t_env *e);

#endif
