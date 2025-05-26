/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:35:05 by babodere          #+#    #+#             */
/*   Updated: 2025/05/22 23:53:57 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <libft.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	t_map *map = create_struct(av[1]);
	if (!map)
	{
		ft_printf("Error");
		return (1);
	}
	int	i = -1;
	while (map->data[++i])
		ft_printf("%s\n", map->data[i]);
	ft_printf("END");
}
