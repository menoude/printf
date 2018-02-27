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

typedef struct s_printer
{
    char buffer[BUFFER_SIZE];
    int buffer_index;
    int nb_printed;
    int conversion_len;
}             t_printer;

void throw_err(int code);

int   ft_printf(char *format, ...);

void add_to_buffer(char *location, t_printer *printer, int length);
void buffer_flush(t_printer *printer);
void buffer_print(t_printer *printer);

void process_conversion(char *location, t_printer *printer, int *index);


#endif
