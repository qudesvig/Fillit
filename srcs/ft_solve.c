/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:48:23 by gedemais          #+#    #+#             */
/*   Updated: 2018/11/27 16:41:06 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_cp(t_list *tminos)
{
	t_list	*tmp;
	size_t	nb;

	nb = 0;
	if (!tminos)
		return (0);
	tmp = tminos;
	while (tmp->next)
	{
		tmp = tmp->next;
		nb++;
	}
	nb++;
	if (nb > 26)
		ft_error();
	return (nb);
}

char	**ft_init_tab(t_list *liste)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	size;

	i = -1;
	size = ft_minsq(ft_cp(liste));
	if (size == 2 || size == 3)
		size = (PATH->length > PATH->height) ? PATH->length : PATH->height;
	if (!(tab = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (++i < size)
	{
		j = -1;
		if (!(tab[i] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		while (++j < size)
			tab[i][j] = '.';
		tab[i][j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_resize(char **tab, int sq_size, int size)
{
	char	**new;
	int		x;
	int		y;

	y = 0;
	ft_tab_del(tab);
	if (!(new = (char**)malloc(sizeof(char*) * (sq_size + size + 2))))
		return (NULL);
	while (y <= sq_size + size)
	{
		x = 0;
		if (!(new[y] = (char*)malloc(sizeof(char) * (sq_size + size + 1))))
			return (NULL);
		while (x <= sq_size + size)
		{
			new[y][x] = '.';
			x++;
		}
		new[y][x] = '\0';
		y++;
	}
	new[y] = 0;
	return (new);
}

int		ft_solve_2(t_list *tminos, char **tab, int sq_size, int *cd)
{
	ft_place_piece(tab, cd[0], cd[1], PATHT);
	if (tminos->next)
	{
		if (ft_solve(tminos->next, tab, sq_size))
			return (1);
	}
	else
	{
		ft_pctab(tab);
		return (1);
	}
	ft_del_piece(tab, cd[0], cd[1], PATHT);
	return (0);
}

int		ft_solve(t_list *tminos, char **tab, int sq_size)
{
	int		cd[2];

	cd[0] = 0;
	cd[1] = 0;
	if (PATHT->ls >= 'A' && PATHT->ls <= 'Z')
	{
		cd[0] = ft_glx(tab, PATHT->ls) - PATHT->length;
		cd[1] = ft_gly(tab, PATHT->ls) - PATHT->height;
		cd[0] = (cd[0] >= 0) ? cd[0] : 0;
		cd[1] = (cd[1] >= 0) ? cd[1] : 0;
	}
	while ((unsigned int)cd[1] <= (sq_size - PATHT->height) + 1)
	{
		while ((unsigned int)cd[0] <= (sq_size - PATHT->length) + 1)
		{
			if (ft_can_i(tab, cd[0], cd[1], PATHT))
				if (ft_solve_2(tminos, tab, sq_size, cd))
					return (1);
			cd[0]++;
		}
		cd[0] = 0;
		cd[1]++;
	}
	return (0);
}
