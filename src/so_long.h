/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:35:12 by babodere          #+#    #+#             */
/*   Updated: 2025/05/22 23:46:53 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "parsing.h"

# define CELL_COLLECTIBLE 'C'
# define CELL_WALL '1'
# define CELL_EMPTY '0'
# define CELL_PLAYER_SPAWN 'P'
# define CELL_EXIT 'E'
# define CELL_PATROL 'X'
# define VALID_CELLS "C10PEX"

typedef struct s_game	t_game;

typedef struct s_map
{
	t_error	*error;
	char	**data;
	int		collectible;
	int		max_collectible;
	int		sprite;
	int		size;
}		t_map;

int			init_game(t_map *map);
t_error		*generate_error(void);
t_map		*create_struct(char *file_path);

#endif
