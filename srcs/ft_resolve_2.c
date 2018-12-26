/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:40:05 by gedemais          #+#    #+#             */
/*   Updated: 2018/11/27 16:11:52 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_coords_cmp(t_tetris *l1, t_tetris *l2)
{
	if (l1->x1 != l2->x1 || l1->y1 != l2->y1)
		return (0);
	else if (l1->x2 != l2->x2 || l1->y2 != l2->y2)
		return (0);
	else if (l1->x3 != l2->x3 || l1->y3 != l2->y3)
		return (0);
	else if (l1->x4 != l2->x4 || l1->y4 != l2->y4)
		return (0);
	return (1);
}

int		ft_glx(char **tab, char lettre)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == lettre)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_gly(char **tab, char lettre)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == lettre)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_can_i(char **tab, int x, int y, t_tetris *tminos)
{
	if (tab[y + tminos->y1][x + tminos->x1] != '.')
		return (0);
	if (tab[y + tminos->y2][x + tminos->x2] != '.')
		return (0);
	if (tab[y + tminos->y3][x + tminos->x3] != '.')
		return (0);
	if (tab[y + tminos->y4][x + tminos->x4] != '.')
		return (0);
	return (1);
}
