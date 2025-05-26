/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:02:04 by babodere          #+#    #+#             */
/*   Updated: 2025/03/06 18:02:04 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *prefix, const char *suffix)
{
	int		index;
	char	*retval;

	retval = (char *) malloc(sizeof(char)
			* (ft_strlen(prefix) + ft_strlen(suffix) + 1));
	if (!retval)
		return (NULL);
	index = 0;
	while (*prefix)
		retval[index++] = *prefix++;
	while (*suffix)
		retval[index++] = *suffix++;
	retval[index] = '\0';
	return (retval);
}
