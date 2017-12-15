/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:19:08 by tfavart           #+#    #+#             */
/*   Updated: 2017/12/15 15:15:28 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_scaling(t_mlx *smlx)
{
	int			res;

	res = 10;
	if ((smlx->lenx * smlx->leny) > 10000)
		res = 5;
	if ((smlx->lenx * smlx->leny) > 100000)
		res = 2;
	return (res);
}

static void		ft_coord_points(t_lst *c, t_mlx *smlx)
{
	double		a;
	int			s;

	a = 30 * 0.0174533;
	s = ft_scaling(smlx);
	c->u = ((c->x) * cos(a) + (c->y) * cos(a + 2.0944) +
			(c->z) * cos(a - 2.0944)) * s;
	c->v = ((c->x) * sin(a) + (c->y) * sin(a + 2.0944) +
			(c->z) * sin(a - 2.0944)) * s;
	if (smlx->max_u < c->u)
		smlx->max_u = c->u;
	if (smlx->max_v < c->v)
		smlx->max_v = c->v;
	if (smlx->min_u > c->u)
		smlx->min_u = c->u;
	if (smlx->min_v > c->v)
		smlx->min_v = c->v;
}

void			ft_init_coord(t_lst *begin, t_mlx *smlx)
{
	t_lst		*tmp;

	while (begin)
	{
		tmp = begin;
		while (tmp)
		{
			ft_coord_points(tmp, smlx);
			tmp = tmp->next_l;
		}
		begin = begin->next_c;
	}
}

void			ft_pixel(int x, int y, t_mlx *smlx)
{
	int			i;
	int			color;

	i = x * 4 + y * smlx->img.size_l;
	color = 0x00FFFFFF;
	(smlx->img.str)[i] = color;
	(smlx->img.str)[i + 1] = color >> 8;
	(smlx->img.str)[i + 2] = color >> 16;
	(smlx->img.str)[i + 3] = color >> 24;
}
