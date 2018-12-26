/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:24:30 by gedemais          #+#    #+#             */
/*   Updated: 2018/11/27 15:52:53 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place_piece(char **tab, int x, int y, t_tetris *tminos)
{
	tab[y + tminos->y1][x + tminos->x1] = tminos->lettre;
	tab[y + tminos->y2][x + tminos->x2] = tminos->lettre;
	tab[y + tminos->y3][x + tminos->x3] = tminos->lettre;
	tab[y + tminos->y4][x + tminos->x4] = tminos->lettre;
	tminos->pos_x = x;
	tminos->pos_y = y;
}

void	ft_del_piece(char **tab, int x, int y, t_tetris *tminos)
{
	tab[y + tminos->y1][x + tminos->x1] = '.';
	tab[y + tminos->y2][x + tminos->x2] = '.';
	tab[y + tminos->y3][x + tminos->x3] = '.';
	tab[y + tminos->y4][x + tminos->x4] = '.';
}

int		ft_max(int *tab)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < 4)
	{
		if (tab[i] > ret)
			ret = tab[i];
		i++;
	}
	return (ret);
}

int		ft_min(int *tab)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < 4)
	{
		if (tab[i] < ret)
			ret = tab[i];
		i++;
	}
	return (ret);
}

void	ft_getsize(unsigned int *length, unsigned int *height, t_tetris *tminos)
{
	int		tab[2][4];
	int		mins[2];
	int		maxs[2];
	int		i;

	i = 0;
	tab[0][0] = tminos->x1;
	tab[0][1] = tminos->x2;
	tab[0][2] = tminos->x3;
	tab[0][3] = tminos->x4;
	tab[1][0] = tminos->y1;
	tab[1][1] = tminos->y2;
	tab[1][2] = tminos->y3;
	tab[1][3] = tminos->y4;
	mins[0] = ft_min(tab[0]);
	mins[1] = ft_min(tab[1]);
	maxs[0] = ft_max(tab[0]);
	maxs[1] = ft_max(tab[1]);
	*length = maxs[0] - mins[0] + 1;
	*height = maxs[1] - mins[1] + 1;
}
