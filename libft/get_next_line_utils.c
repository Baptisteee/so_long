/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:38:52 by babodere          #+#    #+#             */
/*   Updated: 2025/05/21 06:11:30 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	dstlen;

	dstlen = 0;
	if (!dst || !src)
		return (0);
	dstlen = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dst);
}

int	check_retval(char stash[BUFFER_SIZE + 1], char *retval)
{
	int	s_index;
	int	r_index;
	int	line;

	s_index = 0;
	r_index = 0;
	line = 0;
	while (retval[r_index])
	{
		if (line == 1)
		{
			stash[s_index++] = retval[r_index];
			retval[r_index] = '\0';
		}
		if (retval[r_index] == '\n')
			line = 1;
		r_index++;
	}
	stash[s_index] = '\0';
	return (line);
}

char	*ft_strnew(char *s)
{
	char	*retval;
	int		s_size;

	if (!s)
		return (NULL);
	s_size = ft_strlen(s);
	retval = (char *)malloc(sizeof(char) * (s_size + 1));
	if (!retval)
		return (free(s), NULL);
	ft_strcpy(retval, s);
	free(s);
	return (retval);
}
