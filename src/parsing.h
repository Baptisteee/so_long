/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:45:34 by babodere          #+#    #+#             */
/*   Updated: 2025/05/25 17:45:34 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_loc
{
	int	x;
	int	y;
}	t_loc;

# define ERROR_1 "Error encountered during map parsing"
# define ERROR_2 "Player spawnpoint not found"
# define ERROR_3 "Problem with path finding or number of valid collectibles"
# define ERROR_4 "The map isn't surrounded by walls"

typedef struct s_error
{
	int		error;
	char	*message;
}	t_error;

int		find_collectibles(char **map);
int		is_surrounded_by_walls(char **map);
int		get_number_of_lines(char **map);
int		get_line_length(char **map);
void	reset_map(char **map);
t_loc	find_player_spawn(char **map);

#endif
