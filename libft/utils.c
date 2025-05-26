/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:53:43 by babodere          #+#    #+#             */
/*   Updated: 2025/04/27 15:16:27 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharr(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstrr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbrr(int n)
{
	unsigned int	nbr;
	int				count;

	nbr = n;
	count = 0;
	if (n < 0)
	{
		count += ft_putcharr('-');
		nbr = -n;
	}
	if (nbr >= 10)
	{
		count += ft_putnbrr(nbr / 10);
	}
	count += ft_putcharr((nbr % 10) + '0');
	return (count);
}

int	ft_putunsignedd(unsigned int nbr)
{
	int				count;

	count = 0;
	if (nbr >= 10)
	{
		count += ft_putnbrr(nbr / 10);
	}
	count += ft_putcharr((nbr % 10) + '0');
	return (count);
}
