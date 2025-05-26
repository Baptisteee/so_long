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

int	find_collectibles(char **map);
int	is_surrounded_by_walls(char **map);
int	get_number_of_lines(char **map);
int	get_line_length(char **map);

#endif
