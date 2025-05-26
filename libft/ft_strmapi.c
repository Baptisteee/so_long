/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:07:00 by babodere          #+#    #+#             */
/*   Updated: 2025/03/06 18:07:00 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*retval;
	int		index;

	index = 0;
	retval = (char *) malloc(sizeof(char) * (ft_strlen((char *) s) + 1));
	if (!retval)
		return (NULL);
	while (s[index])
	{
		retval[index] = f(index, s[index]);
		index++;
	}
	retval[index] = '\0';
	return (retval);
}
