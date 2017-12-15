/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 12:50:23 by tfavart           #+#    #+#             */
/*   Updated: 2017/12/15 14:57:50 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_draw_line1(t_coord c, t_mlx *smlx)
{
	int			x;

	if (c.x1 < c.x2)
	{
		x = c.x1;
		while (x < c.x2)
		{
			ft_pixel(x, c.y1 + ((c.y2 - c.y1) * (x - c.x1)) / (c.x2 - c.x1), smlx);
			x++;
		}
	}
	else
	{
		x = c.x2;
		while (x < c.x1)
		{
			ft_pixel(x, c.y2 + ((c.y1 - c.y2) * (x - c.x2)) / (c.x1 - c.x2), smlx);
			x++;
		}
	}
}

static void		ft_draw_line2(t_coord c, t_mlx *smlx)
{
	int			y;

	if (c.y1 < c.y2)
	{
		y = c.y1;
		while (y < c.y2)
		{
			ft_pixel(c.x1 + ((c.x2 - c.x1) * (y - c.y1)) / (c.y2 - c.y1), y, smlx);
			y++;
		}
	}
	else
	{
		y = c.y2;
		while (y < c.y1)
		{
			ft_pixel(c.x2 + ((c.x1 - c.x2) * (y - c.y2)) / (c.y1 - c.y2), y, smlx);
			y++;
		}
	}
}

void			ft_choise_octant(t_coord c, t_mlx *smlx)
{
	int			dx;
	int			dy;

	dx = abs(c.x2 - c.x1);
	dy = abs(c.y2 - c.y1);
	if (dx > dy)
		ft_draw_line1(c, smlx);
	else
		ft_draw_line2(c, smlx);
}

static void		ft_scale(t_lst *origin, t_lst *dest, t_mlx *smlx)
{
	t_coord		coord;

	coord.x1 = origin->u + abs(smlx->min_u) + 50;
	coord.y1 = origin->v + abs(smlx->min_v) + 50;
	coord.x2 = dest->u + abs(smlx->min_u) + 50;
	coord.y2 = dest->v + abs(smlx->min_v) + 50;
	ft_choise_octant(coord, smlx);
}

void			ft_draw(t_lst *begin, t_mlx *smlx)
{
	t_lst		*tmp;

	while (begin)
	{
		tmp = begin;
		while (tmp)
		{
			if (tmp->next_l)
				ft_scale(tmp, tmp->next_l, smlx);
			if (tmp->next_c)
				ft_scale(tmp, tmp->next_c, smlx);
			tmp = tmp->next_l;
		}
		begin = begin->next_c;
	}
}
