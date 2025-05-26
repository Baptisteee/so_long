/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:40:06 by babodere          #+#    #+#             */
/*   Updated: 2025/03/04 02:40:06 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*array;

	array = (unsigned char *)s;
	while (n--)
	{
		if ((unsigned char) c == *array)
		{
			return ((unsigned char *) array);
		}
		array++;
	}
	return (NULL);
}
