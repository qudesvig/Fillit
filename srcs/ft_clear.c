/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:36:08 by gedemais          #+#    #+#             */
/*   Updated: 2018/11/26 19:53:13 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tab_del(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_lstclr(void *content, size_t content_size)
{
	content_size = 0;
	ft_memdel(&content);
}
