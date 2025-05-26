/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:05:58 by babodere          #+#    #+#             */
/*   Updated: 2025/03/27 22:10:37 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_puthex(unsigned long long nb, int flag)
{
	int		count;
	char	c;

	count = 0;
	if (nb >= 16)
		count += ft_puthex(nb / 16, flag);
	if (flag)
		c = "0123456789ABCDEF"[nb % 16];
	else
		c = "0123456789abcdef"[nb % 16];
	count += write(1, &c, 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_puthex((unsigned long long) ptr, 0);
	return (count);
}
