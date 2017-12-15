/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:27:06 by tfavart           #+#    #+#             */
/*   Updated: 2017/12/14 17:15:19 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_lst	*ft_create_lst(int x, int y, int z)
{
	t_lst		*new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->next_l = NULL;
	new->next_c = NULL;
	return (new);
}

static t_lst	*ft_lst_join(t_lst *begin, int y)
{
	t_lst		*tmp1;
	t_lst		*tmp2;
	int			i;

	tmp1 = begin;
	i = 2;
	while (i < y)
	{
		tmp1 = tmp1->next_c;
		i++;
	}
	tmp2 = tmp1->next_c;
	while (tmp1->next_l && tmp2->next_l)
	{
		tmp1 = tmp1->next_l;
		tmp2 = tmp2->next_l;
		tmp1->next_c = tmp2;
	}
	return (begin);
}

static t_lst	*ft_test_colon(t_lst *begin, int x, int y, int z)
{
	t_lst		*new;
	int			i;

	i = 2;
	if (y != 1)
	{
		while (i < y)
		{
			begin = begin->next_c;
			i++;
		}
		if (!(new = ft_create_lst(x, y, z)))
			return (NULL);
		begin->next_c = new;
		return (new);
	}
	return (begin);
}

static t_lst	*ft_lst(char **tab, t_lst *begin, int y)
{
	int			x;
	t_lst		*new;
	t_lst		*tmp;

	x = 1;
	if (begin == NULL)
		if (!(begin = ft_create_lst(x, y, ft_atoi(tab[x]))))
			return (NULL);
	if (!(tmp = ft_test_colon(begin, x, y, ft_atoi(tab[x]))))
		return (ft_free_lst(begin));
	x += 1;
	while (tab[x])
	{
		if (!(new = ft_create_lst(x, y, ft_atoi(tab[x]))))
			return (ft_free_lst(begin));
		tmp->next_l = new;
		tmp = new;
		x += 1;
	}
	if (y > 1)
		ft_lst_join(begin, y);
	return (begin);
}

t_lst			*ft_parser(char *map, t_lst *begin)
{
	int			fd;
	int			red;
	char		*line;
	char		**tab;
	int			y;

	if (!(fd = open(map, O_RDONLY)))
		return (NULL);
	y = 1;
	while ((red = get_next_line(fd, &line)) != 0)
	{
		if (red == -1)
			return (ft_free_lst(begin));
		tab = ft_strsplit(line, ' ');
		begin = ft_lst(tab, begin, y);
		ft_free_tab(tab);
		free(line);
		y += 1;
	}
	return (begin);
}
