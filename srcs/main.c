/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:36:34 by gedemais          #+#    #+#             */
/*   Updated: 2018/11/27 15:43:27 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit(char *file_name)
{
	t_list	*liste;
	char	**square;
	int		fd;
	int		sq_size;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		ft_error();
	fd = open(file_name, O_RDONLY);
	liste = ft_construct_list(fd);
	if (!(square = ft_init_tab(liste)))
		ft_error();
	sq_size = ft_strlen(square[0]) - 1;
	while (ft_solve(liste, square, sq_size) == 0)
	{
		square = ft_resize(square, sq_size, 1);
		sq_size++;
	}
	ft_tab_del(square);
	ft_lstdel(&liste, &ft_lstclr);
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_fillit(argv[1]);
	else
		ft_usage();
	return (0);
}
