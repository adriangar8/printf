/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrigarc <adrigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:48:29 by adrigarc          #+#    #+#             */
/*   Updated: 2023/09/06 16:16:15 by adrigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_placeholder_checker(char ph, va_list ptr_arg)
{
	int	ret;

	ret = 0;
	if (ph == 'c')
		ret = ft_printf_c(va_arg(ptr_arg, int));
	else if (ph == 's')
		ret = ft_printf_s(va_arg(ptr_arg, char *), 0);
	else if (ph == 'p')
		ret = ft_printf_p(va_arg(ptr_arg, unsigned long long));
	else if (ph == 'd' || ph == 'i')
		ret = ft_printf_di(va_arg(ptr_arg, int));
	else if (ph == 'u')
		ret = ft_printf_u(va_arg(ptr_arg, unsigned int));
	else if (ph == 'x')
		ret = ft_printf_x(va_arg(ptr_arg, unsigned int), "0123456789abcdef");
	else if (ph == 'X')
		ret = ft_printf_x(va_arg(ptr_arg, unsigned int), "0123456789ABCDEF");
	else if (ph == '%')
		ret = ft_printf_5();
	return (ret);
}

int	ft_printf(char const *str, ...)
{
	va_list		ptr_arg;
	int			res;
	int			i;
	int			aux;

	va_start(ptr_arg, str);
	res = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			aux = ft_placeholder_checker(str[++i], ptr_arg);
			if (aux == -1)
				return (-1);
			res += aux;
		}
		else
		{
			if (ft_putchar(str[i]) == -1)
				return (-1);
			res++;
		}
	}
	return (res);
}
/*
int	main(void)
{
	char					*str;
	int						num;
	unsigned int			unum;
	unsigned long long		ptr;
	char					ch;

	str = "Hello, World!";
	num = 42;
	unum = 42;
	ptr = 0x7fff5fbff700;
	ch = 'A';
	printf("Original printf:\n");
	printf("Expected:\n");
	printf("String: %s\n", str);
	printf("Integer: %d\n", num);
	printf("Unsigned Integer: %u\n", unum);
	printf("Pointer: %p\n", &ptr);
	printf("Character: %c\n", ch);
	printf("Hexadecimal (lowercase): %x\n", num);
	printf("Hexadecimal (uppercase): %X\n", num);
	printf("Percent: %%\n");
	printf("\nActual:\n");
	printf("Implemented printf:\n");
	ft_printf("String: %s\n", str);
	ft_printf("Integer: %d\n", num);
	ft_printf("Unsigned Integer: %u\n", unum);
	ft_printf("Pointer: %p\n", &ptr);
	ft_printf("Character: %c\n", ch);
	ft_printf("Hexadecimal (lowercase): %x\n", num);
	ft_printf("Hexadecimal (uppercase): %X\n", num);
	ft_printf("Percent: %%\n");
	return (0);
}
*/
