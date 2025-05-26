/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 04:57:54 by babodere          #+#    #+#             */
/*   Updated: 2025/04/28 18:16:07 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	ft_strlenn(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	index;

	index = 0;
	while (tab[index])
		free(tab[index++]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**retval;
	int		i;
	int		j;
	int		words;

	i = 0;
	words = count_words(s, c);
	retval = (char **) malloc(sizeof(char *) * (words + 1));
	if (!retval)
		return (NULL);
	while (i < words)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		retval[i] = (char *) malloc(sizeof(char) * (ft_strlenn(s, c) + 1));
		if (!retval[i])
			return (free_tab(retval), NULL);
		while (*s && *s != c)
			retval[i][j++] = *s++;
		retval[i][j] = '\0';
		i++;
	}
	retval[i] = 0;
	return (retval);
}
