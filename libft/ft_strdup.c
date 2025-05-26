/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 07:24:17 by babodere          #+#    #+#             */
/*   Updated: 2025/03/02 07:24:17 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(src);
	dest = (char *) malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, size + 1);
	return (dest);
}
