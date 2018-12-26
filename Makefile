# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 15:20:06 by gedemais          #+#    #+#              #
#    Updated: 2018/11/27 15:43:09 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc

FLAGS = -Wall -Werror -Wextra

NAME = fillit

LIB = libft/libft.a

END =\033[0m
GRA =\033[1m
UND =\033[4m
BLI =\033[5m
BLA =\033[30m
RED =\033[31m
GRE =\033[32m
YEL =\033[33m
BLU =\033[34m
PUR =\033[35m
CYA =\033[36m
WHI =\033[37m

SRCS_NAME = ft_error.c \
			ft_list.c \
			ft_parsing.c \
			ft_parsing_2.c \
			ft_resolve.c \
			ft_resolve_2.c \
			ft_solve.c \
			ft_clear.c \
			main.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS = $(SRCS_NAME:.c=.o)

all : $(NAME) $(LIB) libft/libft.h

$(NAME) : $(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)
		@echo "$(GRE)Done !$(END)"

%.o : $(SRCS_PATH)%.c
		@echo "Making $(UND)$(GRA)Libft$(END) :"
		@make -C libft/
		@echo "Making $(UND)$(RED)Fillit$(END) :"
		@echo "Compiling $(CYA)sources files...$(END)"
		$(CC) $(FLAGS) -c $(SRCS)
	
clean :
		@make -C libft/ clean
		@rm -rf $(OBJS)

fclean : clean
		@make -C libft/ fclean
		@rm -rf $(NAME)

re : fclean all
