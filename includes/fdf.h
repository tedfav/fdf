/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:14:09 by tfavart           #+#    #+#             */
/*   Updated: 2017/12/15 13:13:57 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_img
{
	void			*ptr;
	char			*str;
	int				bpp;
	int				size_l;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*image;

	int				lenx;
	int				leny;
	int				lenz;

	int				max_u;
	int				max_v;
	int				min_u;
	int				min_v;

	int				ox;
	int				oy;
	int				oz;

	int				wlenx;
	int				wleny;

	t_img			img;
}					t_mlx;

typedef struct		s_lst
{
	int				x;
	int				y;
	int				z;

	int				u;
	int				v;

	struct s_lst	*next_l;
	struct s_lst	*next_c;
}					t_lst;

typedef struct		s_coord
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_coord;

int					ft_key_hook(int keycode, void *params);
t_lst				*ft_parser(char *map, t_lst *begin);
void				error(char *str);
void				*ft_free_tab(char **tab);
void				*ft_free_lst(t_lst *begin);
void				ft_draw(t_lst *begin, t_mlx *smlx);
void				ft_len(t_lst *begin, t_mlx *smlx);
void				ft_init_coord(t_lst *begin, t_mlx *smlx);
void				ft_smlx(t_mlx *smlx);
void				ft_pixel(int x, int y, t_mlx *smlx);

#endif
