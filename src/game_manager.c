/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 04:14:38 by babodere          #+#    #+#             */
/*   Updated: 2025/06/17 17:40:45 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_manager.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_manager.h"
#include "parsing.h"
#include "so_long.h"

#include <stdlib.h>

int	init_game(t_map *map)
{
	t_game	game;
	t_loc	player_pos;

	game.player_pos = malloc(sizeof(t_loc));
	if (!game.player_pos)
		return (free(map->data), 1);
	game.map = map;
	player_pos = find_player_spawn(map->data);
	game.player_pos->x = player_pos.x;
	game.player_pos->y = player_pos.y;
	game.moves = 0;
	create_window(&game);
	return (0);
}

void	handle_movement(t_game *game, int x, int y)
{
	t_loc	new_pos;
	char	**map;

	map = game->map->data;
	new_pos.x = game->player_pos->x + x;
	new_pos.y = game->player_pos->y + y;
	if (map[new_pos.y][new_pos.x] && map[new_pos.y][new_pos.x] != CELL_WALL)
	{
		if (map[new_pos.y][new_pos.x] == CELL_COLLECTIBLE)
		{
			game->map->data[new_pos.y][new_pos.x] = '0';
			game->map->collectible++;
		}
		else if (map[new_pos.y][new_pos.x] == CELL_EXIT)
		{
			ft_printf("Moves: %d\n", game->moves + 1);
			if (game->map->collectible == game->map->max_collectible)
				destroy_window(game);
		}
		else if (map[new_pos.y][new_pos.x] == CELL_PATROL)
			free((ft_printf("YOU DIED !"), destroy_window(game), NULL));
		game->player_pos->x = new_pos.x;
		game->player_pos->y = new_pos.y;
		game->moves++;
	}
}

void	display_moves(t_game *game)
{
	char	*move_count;
	char	*move_str;
	int		moves;

	moves = game->moves;
	if (!game || !game->mlx_data->mlx || !game->mlx_data->win)
		return ;
	move_count = ft_itoa(moves);
	if (!move_count)
		return ;
	move_str = ft_strjoin("Moves: ", move_count);
	if (!move_str)
	{
		free(move_count);
		return ;
	}
	mlx_string_put(game->mlx_data->mlx, game->mlx_data->win,
		10, 20, 0x1c2833, move_str);
	ft_printf("%s\n", move_str);
	free(move_count);
	free(move_str);
}

void	move_player(t_game *game, int x, int y)
{
	t_mlx_data	*mlx_data;
	t_loc		*player_pos;
	char		**map;

	mlx_data = game->mlx_data;
	map = game->map->data;
	player_pos = game->player_pos;
	handle_movement(game, x, y);
	display_images(game);
	display_moves(game);
}

t_error	*generate_error(void)
{
	t_error	*error;

	error = malloc(sizeof(t_error));
	if (!error)
		return (NULL);
	error->error = 1;
	error->message = NULL;
	return (error);
}
