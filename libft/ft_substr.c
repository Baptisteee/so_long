/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 04:36:01 by babodere          #+#    #+#             */
/*   Updated: 2025/04/22 18:09:05 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	size;
	char	*retval;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		retval = malloc(1);
		if (!retval)
			return (NULL);
		return (retval[0] = '\0', retval);
	}
	if (start + len > slen)
		size = slen - start;
	else
		size = len;
	retval = (char *) malloc(sizeof(char) * (size + 1));
	if (!retval)
		return (NULL);
	ft_strlcpy(retval, s + start, size + 1);
	return (retval);
}
