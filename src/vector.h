/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:46:29 by babodere          #+#    #+#             */
/*   Updated: 2025/05/23 00:49:18 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include <stddef.h>

typedef struct s_dynamic_array
{
	char	**data;
	size_t	capacity;
	size_t	size;
}	t_vector;

int			vector_grow(t_vector *vec, size_t new_cap);
int 		vector_push(t_vector *vec, char *e);
char		*vector_pop(t_vector *vec);
void		vector_destroy();
t_vector	vector_init();

#endif
