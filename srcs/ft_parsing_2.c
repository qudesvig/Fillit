/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:19:49 by gedemais          #+#    #+#             */
/*   Updated: 2018/11/27 12:32:26 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_count_sharps(char **tminos)
{
	unsigned int	i;
	unsigned int	j;
	size_t			nb_sharps;

	i = 0;
	nb_sharps = 0;
	while (tminos[i])
	{
		j = 0;
		while (tminos[i][j])
		{
			if (tminos[i][j] == '#')
				nb_sharps++;
			j++;
		}
		if (j > 4)
			ft_error();
		i++;
	}
	return (nb_sharps);
}

size_t	ft_count_co(char **tminos, int i, int j)
{
	int		nb_co;

	nb_co = 0;
	if (j)
		if (tminos[i][j - 1] == '#')
			nb_co++;
	if (j < 3)
		if (tminos[i][j + 1] == '#')
			nb_co++;
	if (i)
		if (tminos[i - 1][j] == '#')
			nb_co++;
	if (i < 3)
		if (tminos[i + 1][j] == '#')
			nb_co++;
	return (nb_co);
}

size_t	ft_minsq(int nb)
{
	if (nb == 1)
		return (2);
	else if (nb == 2)
		return (3);
	else if (nb == 3 || nb == 4)
		return (4);
	else if (nb == 5 || nb == 6)
		return (5);
	else if (nb == 7 || nb == 8 || nb == 9)
		return (6);
	else if (nb == 10 || nb == 11 || nb == 12)
		return (7);
	else if (nb == 13 || nb == 14 || nb == 15 || nb == 16)
		return (8);
	else if (nb == 17 || nb == 18 || nb == 19 || nb == 20)
		return (9);
	else if (nb == 21 || nb == 22 || nb == 23 || nb == 24 || nb == 25)
		return (10);
	else if (nb == 26)
		return (11);
	else
		return (0);
}

void	ft_reduct_x(t_tetris *lst)
{
	int		c1;
	int		c2;
	int		c3;
	int		c4;

	c1 = lst->x1;
	c2 = lst->x2;
	c3 = lst->x3;
	c4 = lst->x4;
	while (c1 > 0 && c2 > 0 && c3 > 0 && c4 > 0)
	{
		c1--;
		c2--;
		c3--;
		c4--;
	}
	lst->x1 = c1;
	lst->x2 = c2;
	lst->x3 = c3;
	lst->x4 = c4;
}

void	ft_reduct_y(t_tetris *lst)
{
	int		c1;
	int		c2;
	int		c3;
	int		c4;

	c1 = lst->y1;
	c2 = lst->y2;
	c3 = lst->y3;
	c4 = lst->y4;
	while (c1 > 0 && c2 > 0 && c3 > 0 && c4 > 0)
	{
		c1--;
		c2--;
		c3--;
		c4--;
	}
	lst->y1 = c1;
	lst->y2 = c2;
	lst->y3 = c3;
	lst->y4 = c4;
}
