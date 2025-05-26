/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:00:18 by babodere          #+#    #+#             */
/*   Updated: 2025/03/09 21:00:18 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_charset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*retval;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] && is_in_charset(str[start], set))
		start++;
	while (str[end] && is_in_charset(str[end], set))
		end--;
	retval = ft_substr(str, start, (end - start + 1));
	if (!retval)
		return (NULL);
	return (retval);
}
