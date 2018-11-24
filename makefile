# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clingier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 07:44:16 by clingier          #+#    #+#              #
#    Updated: 2018/11/16 14:15:32 by clingier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

SRC = src/*.c

$(NAME):
	@gcc -I includes/ -I libft/ -L libft/ -lft $(FLAGS) $(SRC) -o ft_ls

all: $(NAME)
clean:
	rm -f ft_ls
re: clean $(NAME)
