/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrigarc <adrigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:31:14 by adrigarc          #+#    #+#             */
/*   Updated: 2023/09/04 20:23:23 by adrigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *str, int malloc_check)
{
	int	i;
	int	out;

	i = -1;
	out = 0;
	if (str)
	{
		while (str[++i])
		{
			out = ft_putchar(str[i]);
			if (out == -1)
				return (-1);
		}
	}
	else
	{
		i = 6;
		out = ft_printf_s("(null)", 0);
		if (out == -1)
			return (-1);
	}
	if (malloc_check == 1)
		free(str);
	return (i);
}
