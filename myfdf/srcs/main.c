/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:03:55 by tfavart           #+#    #+#             */
/*   Updated: 2017/12/06 15:41:28 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(void)
{
	t_mlx	smlx;

	smlx.mlx = mlx_init();
	smlx.win = mlx_new_window(smlx.mlx, 400, 400, "test");
	mlx_key_hook(smlx.win, &ft_key_hook, &smlx);
	mlx_loop(smlx.mlx);
	return (0);
}
