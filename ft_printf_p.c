/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrigarc <adrigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:02:16 by adrigarc          #+#    #+#             */
/*   Updated: 2023/09/06 16:10:56 by adrigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p_num(unsigned long long num, char *base)
{
	int	out;
	int	aux1;
	int	aux2;

	out = 0;
	aux1 = 0;
	aux2 = 0;
	if (num < 16)
	{
		if (ft_putchar(base[num]) == -1)
			return (-1);
		out++;
	}
	else
	{
		aux1 = ft_printf_p_num(num / 16, base);
		aux2 = ft_printf_p_num(num % 16, base);
		if (aux1 == -1 || aux2 == -1)
			return (-1);
		out += aux1 + aux2;
	}
	return (out);
}

int	ft_printf_p(unsigned long long p)
{
	int	out;
	int	aux1;
	int	aux2;

	out = 0;
	aux1 = 0;
	aux2 = 0;
	if (!p)
	{
		out = ft_printf_s("0x0", 0);
		if (out == -1)
			return (-1);
	}
	else
	{
		aux1 = ft_printf_s("0x", 0);
		if (aux1 == -1)
			return (-1);
		aux2 = ft_printf_p_num(p, "0123456789abcdef");
		if (aux2 == -1)
			return (-1);
		out += aux1;
		out += aux2;
	}
	return (out);
}
