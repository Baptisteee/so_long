/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:28:08 by babodere          #+#    #+#             */
/*   Updated: 2025/03/03 01:28:08 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*retval;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	retval = (char *)&s[i];
	if (s[i] != (unsigned char)c)
		return (retval = 0);
	return (retval);
}
