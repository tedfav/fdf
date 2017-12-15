/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:03:55 by tfavart           #+#    #+#             */
/*   Updated: 2017/12/15 15:17:13 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_mlx	smlx;
	t_lst	*begin;
	int		a;

	if (ac < 2)
		error("no argument\n");
	a = 1;
	ft_smlx(&smlx);
	if (!(begin = ft_parser(av[a], NULL)))
	{
		ft_free_lst(begin);
		ft_putstr("parser down\n");
		return (0);
	}
	ft_len(begin, &smlx);
	ft_init_coord(begin, &smlx);
	smlx.wlenx = (smlx.max_u - smlx.min_u) + 100;
	smlx.wleny = (smlx.max_v - smlx.min_v) + 100;
	smlx.mlx = mlx_init();
	smlx.win = mlx_new_window(smlx.mlx, smlx.wlenx, smlx.wleny, "test");
	smlx.img.ptr = mlx_new_image(smlx.mlx, smlx.wlenx, smlx.wleny);
	smlx.img.str = mlx_get_data_addr(smlx.img.ptr, &(smlx.img.bpp),
			&(smlx.img.size_l), &(smlx.img.endian));
	ft_draw(begin, &smlx);
	mlx_put_image_to_window(smlx.mlx, smlx.win, smlx.img.ptr, 0, 0);
	ft_free_lst(begin);
	mlx_key_hook(smlx.win, &ft_key_hook, &smlx);
	mlx_loop(smlx.mlx);
	return (0);
}
