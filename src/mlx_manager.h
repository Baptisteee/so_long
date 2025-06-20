/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 04:47:26 by babodere          #+#    #+#             */
/*   Updated: 2025/06/05 13:29:15 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MANAGER_H
# define MLX_MANAGER_H

# define IMG_WIDTH 50
# define IMG_HEIGHT 50

# include "game_manager.h"
# include "parsing.h"
# include "so_long.h"

# define COLLECTIBLE_PATH "assets/collectible.xpm"
# define PLAYER_PATH "assets/player.xpm"
# define EMPTY_PATH "assets/empty.xpm"
# define EXIT_PATH "assets/exit.xpm"
# define P_SPAWN_PATH "assets/player_spawn.xpm"
# define WALL_PATH "assets/wall.xpm"
# define PATROL_PATH "assets/patrol.xpm"
# define OR_PATH "assets/or.xpm"
# define DIAMOND_PATH "assets/diamond.xpm"
# define EMERALD_PATH "assets/emerald.xpm"

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*textures[10];
	int		height;
	int		width;
}			t_mlx_data;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	ON_KEYDOWNMASK = 1L << 0,
	ON_KEYUPMASK = 1L << 1,
	ON_DESTROYMASK = 1L << 0
};

enum
{
	ESC_KEY = 65307,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
};

int		destroy_window(t_game *game);
int		create_window(t_game *game);
int		display_sprite(t_game *game);
int		check_textures(t_game *game);
void	display_images(t_game *game);
void	*get_imgptr_from_map(t_mlx_data *mlx_data, char c);

#endif
