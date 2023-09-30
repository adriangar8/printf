/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrigarc <adrigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:45:19 by adrigarc          #+#    #+#             */
/*   Updated: 2023/09/06 16:06:38 by adrigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

/* This section contains the re- implementation of the C printf function*/
int			ft_printf(char const *str, ...);
int			ft_placeholder_checker(char ph, va_list ptr_arg);
int			ft_printf_c(int c);
int			ft_printf_s(char *str, int malloc_check);
int			ft_printf_di(int num);
int			ft_printf_u(unsigned int num);
int			ft_printf_x(unsigned int num, char *base);
int			ft_printf_5(void);
int			ft_printf_p(unsigned long long p);

/* This section contains UTILS for the implementation of printf */
int			ft_putchar(char c);
long		ft_minmax(long n);

#endif 