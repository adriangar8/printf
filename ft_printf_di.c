/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrigarc <adrigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:55:22 by adrigarc          #+#    #+#             */
/*   Updated: 2023/09/06 15:52:42 by adrigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	else if (num < 0)
	{
		i ++;
		num = ft_minmax(num);
	}
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int	ft_printf_di(int num)
{
	int		i;
	int		res;
	char	*str;

	i = ft_numlen(num);
	res = 0;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (-1);
	str[i] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
		str[0] = '-';
	while (num)
	{
		i--;
		str[i] = ft_minmax(num % 10) + '0';
		num /= 10;
	}
	res = ft_printf_s(str, 1);
	if (res == -1)
		free(str);
	return (res);
}
