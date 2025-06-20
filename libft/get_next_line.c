/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:17:33 by babodere          #+#    #+#             */
/*   Updated: 2025/05/21 06:10:31 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, int size)
{
	char	*retval;
	int		str_size;

	if (!str)
		return (malloc(sizeof(char) * size));
	str_size = ft_strlen((const char *) str);
	retval = (char *)malloc(sizeof(char) * (str_size + size));
	if (!retval)
		return (free(str), NULL);
	ft_strcpy((void *)retval, str);
	free(str);
	return (retval);
}

char	*init_retval(char stash[BUFFER_SIZE + 1])
{
	char	*retval;
	int		malloc_size;

	if (stash[0] != '\0')
		malloc_size = ft_strlen(stash) + 1;
	else
		malloc_size = 1;
	retval = (char *)malloc(sizeof(char) * malloc_size);
	if (!retval)
		return (NULL);
	retval[0] = '\0';
	if (stash[0] != '\0')
		retval = (char *)ft_strcpy(retval, stash);
	return (retval);
}

char	*read_line(int fd, char stash[BUFFER_SIZE + 1], char *retval)
{
	int	r;

	r = 1;
	while (r > 0)
	{
		r = read(fd, stash, BUFFER_SIZE);
		stash[r] = '\0';
		if (r < 0)
			break ;
		retval = ft_realloc(retval, r + 1);
		if (!retval)
			return (NULL);
		ft_strcat(retval, (const char *)stash);
		if (retval[0] == 0)
			break ;
		if (check_retval(stash, retval) == 1 || r == 0)
			return (ft_strnew(retval));
	}
	return (free(retval), NULL);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*retval;

	retval = init_retval(stash);
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !retval)
		return (free(retval), stash[0] = 0, NULL);
	if (check_retval(stash, retval) == 1)
		return (ft_strnew(retval));
	retval = read_line(fd, stash, retval);
	if (!retval)
		return (stash[0] = 0, NULL);
	return (retval);
}
