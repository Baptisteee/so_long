/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:35:05 by babodere          #+#    #+#             */
/*   Updated: 2025/06/20 21:46:30 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <libft.h>
#include <mlx.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	t_map	*map;
	char	**split_name;

	if (ac != 2)
	{
		ft_printf("Error : No map specified.");
		return (0);
	}
	split_name = ft_split(av[1], '.');
	if (!split_name[1] || !ft_strcmp(split_name[1], ".ber"))
	{
		free_tab(split_name);
		ft_putstr_fd("Error, file does not end with .ber\n", 2);
		exit(1);
	}
	free_tab(split_name);
	map = create_struct(av[1]);
	if (!map || !map->error)
		return (ft_printf("Error"), 1);
	if (map->error && map->error->error == 1)
	{
		ft_printf("Error : %s", map->error->message);
		return (free(map->error), free(map), 1);
	}
	init_game(map);
}
