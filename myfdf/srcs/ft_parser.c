/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:41:56 by tfavart           #+#    #+#             */
/*   Updated: 2017/12/06 17:57:15 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_parser(char *map)
{
	int	fd;
	int	i;

	fd = open(map, O_RDONLY);
	map = NULL;
	while ((i = get_next_line(fd, &map)))
	{
		if (i == -1)
			return(0);
		
	}
	close(fd);
	return (map);
}
