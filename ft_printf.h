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

int   ft_printf(char *format, ...);

#endif
