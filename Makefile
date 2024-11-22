# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femorell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 09:59:34 by femorell          #+#    #+#              #
#    Updated: 2023/01/25 09:59:37 by femorell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = cc
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(FLAGS) server.c $(LIBFT) -o server
	$(CC) $(FLAGS) client.c $(LIBFT) -o client

re: fclean all

clean:
	make clean -C libft

fclean:
	make fclean -C libft
	rm -rf server
	rm -rf client

bonus:
	make -C libft
	$(CC) $(FLAGS) server_bonus.c $(LIBFT) -o server
	$(CC) $(FLAGS) client_bonus.c $(LIBFT) -o client
	
.PHONY: all re clean fclean bonus

.SILENT:
