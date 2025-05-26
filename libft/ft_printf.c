/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:48:42 by babodere          #+#    #+#             */
/*   Updated: 2025/04/27 15:15:51 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_args(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putcharr((char) va_arg(args, int)));
	else if (c == 's')
		return (ft_putstrr(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbrr(va_arg(args, int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_putcharr('%'));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'u')
		return (ft_putunsignedd(va_arg(args, unsigned int)));
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(c, 1);
		return (2);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;
	int		count;

	va_start(args, str);
	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] == '%')
		{
			index++;
			count += handle_args(str[index], args);
		}
		else
			count += ft_putcharr(str[index]);
		index++;
	}
	va_end(args);
	return (count);
}
