# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/30 14:21:44 by mmervoye          #+#    #+#              #
#    Updated: 2018/10/30 14:21:48 by mmervoye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mmervoye.filler

SRCS = ./srcs/algo.c\
	   ./srcs/exec.c\
	   ./srcs/filler_loop.c\
	   ./srcs/get_player.c\
	   ./srcs/main.c\
	   ./srcs/misc.c\
	   ./srcs/pieces.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -O3 -Iincludes -Ilibft/includes
FLAGS = -Wall -Wextra -Werror -O3 -Iincludes -Ilibft/includes -Llibft -lft 

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@gcc $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@make clean -C libft/
	rm -rf $(OBJS)

fclean: clean
	@make fclean -C libft/
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
