/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:47:39 by babodere          #+#    #+#             */
/*   Updated: 2025/05/23 00:50:12 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include <libft.h>

#include <stdlib.h>

int	vector_grow(t_vector *vec, size_t new_cap)
{
	char	**temp;

	if (vec->capacity >= new_cap)
		return (0);
	vec->capacity = new_cap;
	temp = malloc(sizeof(*vec->data) * vec->capacity);
	if (!temp)
		return (1);
	ft_memcpy(temp, vec->data, vec->size);
	free(vec->data);
	vec->data = temp;
	return (0);
}

t_vector	vector_init()
{
	t_vector	res;
	
	res.data = NULL;
	res.capacity = 0;
	res.size = 0;
	return (res);
}

int 	vector_push(t_vector *vec, char *e)
{
	if (vec->size == vec->capacity 
		&& vector_grow(vec, (vec->capacity * 2) | 8))
		return (1);
	vec->data[vec->size++] = e;
	return (0);
}

char 	*vector_pop(t_vector *vec)
{
	if (vec->size > 0)
		return vec->data[--vec->size];
	return (NULL);
}

void 	vector_destroy(t_vector *vec)
{
	char *temp;

	temp = vector_pop(vec);
	while (temp)
	{
		free(temp);
		temp = vector_pop(vec);
	}
	free(vec->data);
	vec->capacity = 0;
}
