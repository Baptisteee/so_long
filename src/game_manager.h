/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 04:31:02 by babodere          #+#    #+#             */
/*   Updated: 2025/06/05 13:31:09 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MANAGER_H
# define GAME_MANAGER_H

# include "parsing.h"
# include "so_long.h"

typedef struct s_mlx_data	t_mlx_data;

typedef struct s_game
{
	t_map					*map;
	t_loc					*player_pos;
	t_mlx_data				*mlx_data;
	int						moves;
}							t_game;

void						move_player(t_game *game, int x, int y);

#endif
