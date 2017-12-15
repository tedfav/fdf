/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:11:14 by tfavart           #+#    #+#             */
/*   Updated: 2017/12/15 13:55:52 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(char *str)
{
	ft_putstr(str);
	exit(0);
}

void		*ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void		*ft_free_lst(t_lst *begin)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	while (begin)
	{
		tmp1 = begin->next_l;
		while (tmp1)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next_l;
			free(tmp2);
		}
		tmp2 = begin;
		begin = begin->next_c;
		free(tmp2);
	}
	free(begin);
	return (NULL);
}
