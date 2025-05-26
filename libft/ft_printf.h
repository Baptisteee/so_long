/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:58:10 by babodere          #+#    #+#             */
/*   Updated: 2025/04/27 15:06:57 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_putcharr(char c);
int	ft_putstrr(char *s);
int	ft_putnbrr(int nb);
int	ft_puthex(unsigned long long nb, int flag);
int	ft_putptr(void *ptr);
int	ft_putunsignedd(unsigned int nbr);
int	ft_printf(const char *str, ...);

#endif
