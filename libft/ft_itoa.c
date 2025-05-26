/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:56:54 by babodere          #+#    #+#             */
/*   Updated: 2025/03/06 23:56:54 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_size(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		count = 1;
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	long	nbr;
	char	*retval;
	int		index;
	int		size;

	size = get_num_size(nb);
	retval = (char *) malloc(sizeof(char) * (size + 1));
	if (!retval)
		return (NULL);
	index = 0;
	nbr = (long) nb;
	if (nbr == 0)
		retval[0] = '0';
	if (nbr < 0)
	{
		retval[index] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		retval[size - index++ - 1] = nbr % 10 + '0';
		nbr /= 10;
	}
	retval[size] = '\0';
	return (retval);
}
