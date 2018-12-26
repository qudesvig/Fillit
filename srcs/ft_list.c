/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:31:14 by qudesvig          #+#    #+#             */
/*   Updated: 2018/11/27 15:53:34 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstpush_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_get_coords(t_tetris *tminos, int x, int y, int z)
{
	if (z == 1)
	{
		tminos->x1 = x;
		tminos->y1 = y;
	}
	else if (z == 2)
	{
		tminos->x2 = x;
		tminos->y2 = y;
	}
	else if (z == 3)
	{
		tminos->x3 = x;
		tminos->y3 = y;
	}
	else if (z == 4)
	{
		tminos->x4 = x;
		tminos->y4 = y;
	}
	else
		ft_error();
}

void	ft_collect_coords(t_tetris *tminos, char **tab)
{
	int		x;
	int		y;
	int		z;

	x = 0;
	y = 0;
	z = 1;
	if (!tab)
		return ;
	while (y < 4)
	{
		while (x < 4)
		{
			if (tab[y][x] == '#')
			{
				ft_get_coords(tminos, x, y, z);
				z++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_get_lasts(t_list *lst, t_tetris *tminos)
{
	t_list	*tmp;

	tmp = lst;
	tminos->ls = -1;
	while (tmp->next && PATHTMP->lettre != tminos->lettre)
	{
		if (ft_coords_cmp(PATHTMP, tminos))
			tminos->ls = PATHTMP->lettre;
		tmp = tmp->next;
	}
}

t_list	*ft_construct_list(int fd)
{
	t_list		*lst;
	t_tetris	tminos;
	char		lettre;
	char		**tab;

	lettre = 'A';
	lst = NULL;
	while ((tab = ft_parsing(fd)))
	{
		ft_collect_coords(&tminos, tab);
		tminos.lettre = lettre;
		ft_reduct_x(&tminos);
		ft_reduct_y(&tminos);
		ft_getsize(&(tminos.length), &(tminos.height), &tminos);
		if (lettre == 'A')
			lst = ft_lstnew(&tminos, sizeof(t_tetris));
		else
			ft_lstpush_back(&lst, ft_lstnew(&tminos, sizeof(t_tetris)));
		ft_get_lasts(lst, &tminos);
		lettre++;
		ft_tab_del(tab);
	}
	return (lst);
}
