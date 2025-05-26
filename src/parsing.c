/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:42:51 by babodere          #+#    #+#             */
/*   Updated: 2025/05/23 01:02:13 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "vector.h"
#include "so_long.h"

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
		if (line[0] == 0)
			return (close(fd), free(line), vector_destroy(&vec), NULL);
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
	if (map[i][j] < 0)
		return (0);
	if (map[i][j] && map[i][j] == CELL_WALL)
		return (0);
	if (map[i][j] && map[i][j] == CELL_EXIT)
		return (1);
	if (map[i][j] && map[i][j] == CELL_COLLECTIBLE)
		return (1);
	map[i][j] = -map[i][j];
	return (find_path(map, i + 1, j) + find_path(map, i - 1, j) + 
		 find_path(map, i, j + 1) + find_path(map, i, j - 1));
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
			if (!ft_strchr(VALID_CELLS, map[i][j]) 
				|| (map[i][j] == CELL_EXIT && (mask & 1) != 0))
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

static void	reset_map(char **map)
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
	char	**str_map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	str_map = parse_to_str(file_path);
	if (!str_map)
		return (free(map), NULL);
	map->data = str_map;
	if (!check_map(map->data)
		|| find_path(map->data, 3, 1) != find_collectibles(map->data))
		return (free(map->data), free(map), NULL);
	reset_map(map->data);
	if (!is_surrounded_by_walls(map->data))
		return (free(map->data), free(map), NULL);
	return (map);
}
