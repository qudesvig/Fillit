/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:26:19 by gedemais          #+#    #+#             */
/*   Updated: 2018/11/21 13:22:12 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(void)
{
	ft_putstr("usage : ./fillit [file_name]\n");
}

void	ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_SUCCESS);
}
