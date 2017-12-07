/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:14:09 by tfavart           #+#    #+#             */
/*   Updated: 2017/12/06 15:42:30 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

int				ft_draw(t_mlx *smlx, char** tab);
int				ft_key_hook(int keycode, t_mlx *smlx);

#endif
