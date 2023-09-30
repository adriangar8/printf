/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrigarc <adrigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:48:15 by adrigarc          #+#    #+#             */
/*   Updated: 2023/09/06 15:54:13 by adrigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(unsigned int num, char *base)
{
	int	i;
	int	aux1;
	int	aux2;

	i = 0;
	aux1 = 0;
	aux2 = 0;
	if (num < 16)
	{
		if (ft_putchar(base[num]) == -1)
			return (-1);
		i++;
	}
	else
	{
		aux1 = ft_printf_x(num / 16, base);
		if (aux1 == -1)
			return (-1);
		aux2 = ft_printf_x(num % 16, base);
		if (aux2 == -1)
			return (-1);
		i += aux1 + aux2;
	}
	return (i);
}
