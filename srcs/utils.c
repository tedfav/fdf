/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:04:58 by tfavart           #+#    #+#             */
/*   Updated: 2017/12/14 17:30:20 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_key_hook(int keycode, void *params)
{
	(void)params;
	if (keycode == 53)
		exit(0);
	return (0);
}

static void	ft_lenx(t_lst *begin, t_mlx *smlx, int x)
{
	while (begin)
	{
		smlx->lenx = x;
		begin = begin->next_l;
	}
	smlx->ox = smlx->lenx / 2;
}

static void	ft_leny(t_lst *begin, t_mlx *smlx, int y)
{
	t_lst	*tmp;

	while (begin)
	{
		tmp = begin;
		while (tmp)
		{
			smlx->leny = y;
			tmp = tmp->next_l;
		}
		begin = begin->next_c;
	}
	smlx->oy = smlx->leny / 2;
}

void		ft_len(t_lst *begin, t_mlx *smlx)
{
	int		x;
	int		y;
	t_lst	*tmp;
	t_lst	*tmp2;

	y = 0;
	tmp = begin;
	while (tmp)
	{
		x = 0;
		tmp2 = tmp;
		while (tmp2)
		{
			if (smlx->lenz < tmp2->z)
				smlx->lenz = tmp2->z;
			tmp2 = tmp2->next_l;
			x++;
		}
		ft_lenx(tmp, smlx, x);
		y++;
		tmp = tmp->next_c;
	}
	ft_leny(begin, smlx, y);
	smlx->oz = smlx->lenz / 2;
}

void		ft_smlx(t_mlx *smlx)
{
	smlx->mlx = NULL;
	smlx->win = NULL;
	smlx->image = NULL;
	smlx->wlenx = 0;
	smlx->wleny = 0;
	smlx->lenx = 0;
	smlx->leny = 0;
	smlx->ox = 0;
	smlx->oy = 0;
	smlx->oz = 0;
	smlx->max_u = 0;
	smlx->min_u = 0;
	smlx->max_v = 0;
	smlx->min_v = 0;
}
