/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:36:23 by babodere          #+#    #+#             */
/*   Updated: 2025/06/20 21:23:48 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_manager.h"
#include "mlx.h"
#include "mlx_manager.h"
#include "parsing.h"
#include "so_long.h"

#include <stddef.h>

int	display_sprite(t_game *game)
{
	t_loc		*loc;
	char		**map;

	loc = game->player_pos;
	map = game->map->data;
	if (map[loc->y + 1][loc->x] == CELL_WALL)
		mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->win,
			game->mlx_data->textures[7 + game->map->sprite],
			IMG_HEIGHT * loc->x, IMG_WIDTH * (loc->y + 1));
	if (map[loc->y - 1][loc->x] == CELL_WALL)
		mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->win,
			game->mlx_data->textures[7 + game->map->sprite],
			IMG_HEIGHT * loc->x, IMG_WIDTH * (loc->y - 1));
	if (map[loc->y][loc->x + 1] == CELL_WALL)
		mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->win,
			game->mlx_data->textures[7 + game->map->sprite],
			IMG_HEIGHT * (loc->x + 1), IMG_WIDTH * loc->y);
	if (map[loc->y][loc->x - 1] == CELL_WALL)
		mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->win,
			game->mlx_data->textures[7 + game->map->sprite],
			IMG_HEIGHT * (loc->x - 1), IMG_WIDTH * loc->y);
	game->map->sprite++;
	if (game->map->sprite > 2)
		game->map->sprite = 0;
	return (1);
}

void	*get_imgptr_from_map(t_mlx_data *mlx_data, char c)
{
	if (c == 'C')
		return (mlx_data->textures[1]);
	else if (c == '0')
		return (mlx_data->textures[2]);
	else if (c == 'E')
		return (mlx_data->textures[3]);
	else if (c == 'P')
		return (mlx_data->textures[4]);
	else if (c == '1')
		return (mlx_data->textures[5]);
	else if (c == 'X')
		return (mlx_data->textures[6]);
	return (NULL);
}

int	check_textures(t_game *game)
{
	int	index;

	index = -1;
	while (++index < 10)
	{
		if (game->mlx_data->textures[index] == NULL)
			return (1);
	}
	return (0);
}
