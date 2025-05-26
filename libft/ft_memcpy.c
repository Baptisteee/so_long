/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 06:24:10 by babodere          #+#    #+#             */
/*   Updated: 2025/05/07 03:12:04 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)src;
	i = -1;
	if (!dest && !src)
		return (NULL);
	while (++i < n)
		ft_memset((dest + i), *(s + i), 1);
	return (dest);
}
