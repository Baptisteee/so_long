/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 04:45:09 by babodere          #+#    #+#             */
/*   Updated: 2025/06/20 21:23:23 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_manager.h"
#include "mlx_manager.h"
#include "parsing.h"
#include "so_long.h"
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

int	destroy_window(t_game *game)
{
	t_mlx_data	*mlx_data;
	int			index;

	index = -1;
	mlx_data = game->mlx_data;
	while (++index < 10)
	{
		if (mlx_data->textures[index] != NULL)
			mlx_destroy_image(mlx_data->mlx, mlx_data->textures[index]);
	}
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_display(mlx_data->mlx);
	free(mlx_data->mlx);
	free(game->map->error);
	free(game->player_pos);
	free_tab(game->map->data);
	free(game->map);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		destroy_window(game);
	else if (keycode == W_KEY)
		move_player(game, 0, -1);
	else if (keycode == S_KEY)
		move_player(game, 0, 1);
	else if (keycode == A_KEY)
		move_player(game, -1, 0);
	else if (keycode == D_KEY)
		move_player(game, 1, 0);
	return (0);
}

void	display_images(t_game *game)
{
	t_mlx_data	*mlx_data;
	t_map		*map;
	int			i;
	int			j;

	mlx_data = game->mlx_data;
	map = game->map;
	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
				get_imgptr_from_map(mlx_data, map->data[i][j]), (j
					* IMG_WIDTH), (i * IMG_HEIGHT));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->textures[0],
		(game->player_pos->x * IMG_WIDTH), game->player_pos->y
		* IMG_HEIGHT);
	display_sprite(game);
}

void	setup_images(t_game *game)
{
	int	w;
	int	h;

	game->mlx_data->textures[0] = mlx_xpm_file_to_image(game->mlx_data->mlx,
			PLAYER_PATH, &w, &h);
	game->mlx_data->textures[1] = mlx_xpm_file_to_image(game->mlx_data->mlx,
			COLLECTIBLE_PATH, &w, &h);
	game->mlx_data->textures[2] = mlx_xpm_file_to_image(game->mlx_data->mlx,
			EMPTY_PATH, &w, &h);
	game->mlx_data->textures[3] = mlx_xpm_file_to_image(game->mlx_data->mlx,
			EXIT_PATH, &w, &h);
	game->mlx_data->textures[4] = mlx_xpm_file_to_image(game->mlx_data->mlx,
			P_SPAWN_PATH, &w, &h);
	game->mlx_data->textures[5] = mlx_xpm_file_to_image(game->mlx_data->mlx,
			WALL_PATH, &w, &h);
	game->mlx_data->textures[6] = mlx_xpm_file_to_image(game->mlx_data->mlx,
			PATROL_PATH, &w, &h);
	game->mlx_data->textures[7] = mlx_xpm_file_to_image(game->mlx_data->mlx,
			EMERALD_PATH, &w, &h);
	game->mlx_data->textures[8] = mlx_xpm_file_to_image(game->mlx_data->mlx,
			DIAMOND_PATH, &w, &h);
	game->mlx_data->textures[9] = mlx_xpm_file_to_image(game->mlx_data->mlx,
			OR_PATH, &w, &h);
	if (check_textures(game))
		destroy_window(game);
}

int	create_window(t_game *game)
{
	t_mlx_data	mlx_data;
	t_map		*map;

	map = game->map;
	mlx_data.mlx = mlx_init();
	if (!mlx_data.mlx)
		return (1);
	mlx_data.width = IMG_WIDTH * get_line_length(map->data);
	mlx_data.height = IMG_HEIGHT * get_number_of_lines(map->data);
	mlx_data.win = mlx_new_window(mlx_data.mlx, mlx_data.width, mlx_data.height,
			"Minecraft So_Long goated");
	if (!mlx_data.win)
		return (free(mlx_data.mlx), 1);
	mlx_hook(mlx_data.win, ON_KEYDOWN, ON_KEYDOWNMASK, &key_press, game);
	mlx_hook(mlx_data.win, ON_DESTROY, ON_DESTROYMASK, &destroy_window, game);
	map->collectible = 0;
	map->max_collectible = find_collectibles(map->data);
	game->mlx_data = &mlx_data;
	setup_images(game);
	map->sprite = 0;
	display_images(game);
	mlx_loop(mlx_data.mlx);
	return (0);
}
