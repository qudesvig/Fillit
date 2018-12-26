/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:21:31 by gedemais          #+#    #+#             */
/*   Updated: 2018/12/11 16:19:13 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define PATH ((t_tetris*)(liste->content))
# define PATHTMP ((t_tetris*)(tmp->content))
# define PATHT ((t_tetris*)(tminos->content))

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct		s_tetris
{
	char			lettre;
	unsigned int	x1;
	unsigned int	y1;
	unsigned int	x2;
	unsigned int	y2;
	unsigned int	x3;
	unsigned int	y3;
	unsigned int	x4;
	unsigned int	y4;
	unsigned int	length;
	unsigned int	height;
	unsigned int	pos_x;
	unsigned int	pos_y;
	char			ls;
}					t_tetris;

void				ft_tab_del(char **tab);
void				ft_lstclr(void *content, size_t content_size);

void				ft_usage(void);
void				ft_error(void);

size_t				ft_valid_check(char **tminos);
size_t				ft_read_check(char *str);
void				ft_checkendl(int fd);
char				**ft_parsing(int fd);

size_t				ft_count_sharps(char **tminos);
size_t				ft_count_co(char **tminos, int i, int j);
size_t				ft_minsq(int nb);
void				ft_reduct_x(t_tetris *lst);
void				ft_reduct_y(t_tetris *lst);

void				ft_lstpush_back(t_list **lst, t_list *new);
void				ft_get_coords(t_tetris *tminos, int x, int y, int z);
void				ft_collect_coords(t_tetris *tminos, char **tab);
t_list				*ft_construct_list(int fd);

size_t				ft_cp(t_list *tminos);
char				**ft_init_tab(t_list *lst);
char				**ft_resize(char **tab, int sq_size, int size);
int					ft_solve(t_list *tminos, char **tab, int sq_size);

void				ft_place_piece(char **tab, int x, int y, t_tetris *tminos);
void				ft_del_piece(char **tab, int x, int y, t_tetris *tminos);
int					ft_can_i(char **tab, int x, int y, t_tetris *tminos);
void				ft_getsize(unsigned int *length,
					unsigned int *height, t_tetris *tminos);

int					ft_coords_cmp(t_tetris *l1, t_tetris *l2);
int					ft_glx(char **tab, char lettre);
int					ft_gly(char **tab, char lettre);

#endif
