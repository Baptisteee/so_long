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

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <unistd.h>
# include <fcntl.h>

# define CELL_COLLECTIBLE 'C'
# define CELL_WALL '1'
# define CELL_EMPTY '0'
# define CELL_PLAYER_SPAWN 'P'
# define CELL_EXIT 'E'
# define VALID_CELLS "C10PE"

typedef struct	s_map
{
	char	**data;
	int		collectible;
	int		max_collectible;
	int		size;
}	t_map;

t_map	*create_struct(char *file_path);
//void	create_window();

#endif
