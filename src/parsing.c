/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:42:51 by babodere          #+#    #+#             */
/*   Updated: 2025/06/21 00:18:06 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "so_long.h"
#include "vector.h"
#include <fcntl.h>
#include <libft.h>

static char	**parse_to_str(char *file_path)
{
	t_vector	vec;
	char		*line;
	char		*temp;
	int			fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	vec = vector_init();
	while (line)
	{
		temp = ft_strtrim(line, "\n");
		free(line);
		if (!temp || vector_push(&vec, temp))
			return (close(fd), vector_destroy(&vec), NULL);
		line = get_next_line(fd);
	}
	close(fd);
	if (vector_push(&vec, NULL))
		return (vector_destroy(&vec), NULL);
	return (vec.data);
}

static int	find_path(char **map, int i, int j)
{
	if (!map[i][j])
		return (0);
	if (map[i][j] < 0)
		return (0);
	if (map[i][j] && map[i][j] == CELL_WALL)
		return (0);
	if (map[i][j] && map[i][j] == CELL_EXIT)
	{
		map[i][j] = -map[i][j];
		return (1);
	}
	if (map[i][j] && map[i][j] == CELL_COLLECTIBLE)
	{
		map[i][j] = -map[i][j];
		return (1 + find_path(map, i + 1, j) + find_path(map, i - 1, j)
			+ find_path(map, i, j + 1) + find_path(map, i, j - 1));
	}
	map[i][j] = -map[i][j];
	return (find_path(map, i + 1, j) + find_path(map, i - 1, j)
		+ find_path(map, i, j + 1) + find_path(map, i, j - 1));
}

static int	check_map(char **map)
{
	int	i;
	int	j;
	int	mask;

	i = -1;
	mask = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr(VALID_CELLS, map[i][j]) || (map[i][j] == CELL_EXIT
					&& (mask & 1) != 0))
				return (0);
			if (map[i][j] == CELL_EXIT)
				mask |= 1;
			if (map[i][j] == CELL_PLAYER_SPAWN && (mask & 2) != 0)
				return (0);
			if (map[i][j] == CELL_PLAYER_SPAWN)
				mask |= 2;
			if (map[i][j] == CELL_COLLECTIBLE)
				mask |= 4;
		}
	}
	return (mask == 7);
}

void	reset_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] < 0)
				map[i][j] = -map[i][j];
			j++;
		}
		i++;
	}
}

t_map	*create_struct(char *file_path)
{
	t_map	*map;
	t_loc	loc;
	char	**str_map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->error = generate_error();
	if (!map->error)
		return (NULL);
	str_map = parse_to_str(file_path);
	if (!str_map)
		return (map->error->message = ERROR_1, map);
	map->data = str_map;
	loc = find_player_spawn(map->data);
	if (loc.x == -1 || loc.y == -1)
		return (free_tab(map->data), map->error->message = ERROR_2, map);
	if (!check_map(map->data) || find_path(map->data, loc.y, loc.x)
		- 1 != find_collectibles(map->data))
		return (free_tab(map->data), map->error->message = ERROR_3, map);
	if (!is_surrounded_by_walls(map->data))
		return (free_tab(map->data), map->error->message = ERROR_4, map);
	map->error->error = 0;
	return (map);
}
