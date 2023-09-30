/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrigarc <adrigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:11:53 by adrigarc          #+#    #+#             */
/*   Updated: 2023/09/06 15:38:48 by adrigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int num)
{
	int	coun;

	coun = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		coun++;
	}
	return (coun);
}

int	ft_printf_u(unsigned int num)
{
	int		res;
	int		i;
	char	*str;

	num = ft_minmax(num);
	res = 0;
	i = ft_numlen(num);
	str = (char *)malloc(sizeof(char) * (i) + 1);
	if (!str)
		return (-1);
	str[i] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		i--;
		str[i] = ft_minmax(num % 10) + '0';
		num = num / 10;
	}
	res = ft_printf_s(str, 1);
	if (res == -1)
		free (str);
	return (res);
}
