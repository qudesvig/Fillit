/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:27:57 by gedemais          #+#    #+#             */
/*   Updated: 2018/11/27 14:19:06 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_checkendl(int fd)
{
	int		i;
	int		j;
	char	c1;
	char	c2;

	i = 1;
	j = 1;
	c1 = 'g';
	c2 = 'q';
	while (i && j)
	{
		i = read(fd, &c1, 1);
		j = read(fd, &c2, 1);
	}
	close(fd);
	if (c1 == '\n' && c2 == '\n')
		ft_error();
}

size_t	ft_read_check(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) != 4)
		ft_error();
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#')
			ft_error();
		i++;
	}
	return (1);
}

size_t	ft_valid_check(char **tminos)
{
	size_t	nb_co;
	int		i;
	int		j;

	i = 0;
	nb_co = 0;
	if (ft_count_sharps(tminos) != 4)
		return (0);
	while (tminos[i])
	{
		j = 0;
		while (tminos[i][j])
		{
			if (tminos[i][j] == '#')
				nb_co += ft_count_co(tminos, i, j);
			j++;
		}
		i++;
	}
	if (nb_co < 6 || nb_co > 8)
		return (0);
	return (1);
}

char	**ft_parsing(int fd)
{
	static int	stop = 0;
	char		**tminos;
	char		*tmp;
	int			var[2];

	var[0] = -1;
	if (!(tminos = (char**)malloc(sizeof(char*) * 5)))
		ft_error();
	while (++var[0] < 5)
	{
		var[1] = get_next_line(fd, &tmp);
		if (var[1] == -1)
			ft_error();
		else if (var[1] == 0 && stop)
			return (tminos = NULL);
		if (var[0] < 4 && ft_read_check(tmp))
			tminos[var[0]] = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	tminos[4] = NULL;
	if (var[1] == 0)
		stop = 1;
	if (ft_valid_check(tminos) == 0)
		ft_error();
	return (tminos);
}
