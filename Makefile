#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amovchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 19:31:33 by amovchan          #+#    #+#              #
#    Updated: 2017/06/21 16:50:24 by amovchan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_P = lem-in
NAME_C = visu-hex

G = gcc
FLAGS = -Wall -Wextra -Werror
GFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

SRC_PATH_P = ./src/
SRC_NAME_P =   main.c \
				ant_on_links.c \
				bfs_ant.c \
				ft_atoilong.c \
				ft_good_room.c \
				ft_links.c \
				ft_read_params.c \
				ft_search_links.c \
				ft_valid_links.c \
				ft_valid_room.c \
				get_params.c \
				intersection_way.c \
				intersection_way2.c \
				printmov.c \
				sortlink.c \
				stop_links.c \
				valid_finish_params.c

OBJ_PATH_P = ./src/
OBJ_NAME_P = $(SRC_NAME_P:.c=.o)
SRC_P = $(addprefix $(SRC_PATH_P), $(SRC_NAME_P))
OBJ_P = $(addprefix $(OBJ_PATH_P), $(OBJ_NAME_P))
GCFLAGS_P = -I./src/ -I./libft/
SRC_PATH_C = ./src_grafik/
SRC_NAME_C =	main.c \
				brezenhem.c \
				ft_atoilong.c \
				ft_links.c \
				ft_valid_links.c \
				ft_valid_room.c \
				max_params.c \
				mov_ant.c \
				mov_in_map.c \
				put_links.c \
				read_params.c

OBJ_PATH_C = ./src_grafik/
OBJ_NAME_C = $(SRC_NAME_C:.c=.o)
SRC_C = $(addprefix $(SRC_PATH_C), $(SRC_NAME_C))
OBJ_C = $(addprefix $(OBJ_PATH_C), $(OBJ_NAME_C))
GCFLAGS_C = -I./src_grafik/ -I./libft/
LIBFT = libft/libft.a
all: $(NAME_P) $(NAME_C)
$(NAME_P): $(OBJ_P)
	@make -C libft/
	@$(G) $(FLAGS) $(GCFLAGS_P) -o $@ $(OBJ_P) $(LIBFT)

$(NAME_C): $(OBJ_C)
	@$(G) $(GFLAGS) $(GCFLAGS_C) -o $@ $(OBJ_C) $(LIBFT)

$(OBJ_PATH_P)%.o: $(SRC_PATH_P)%.c
	@$(G) $(FLAGS) $(GCFLAGS_P) -o $@ -c $<

$(OBJ_PATH_C)%.o: $(SRC_PATH_C)%.c
	@$(G) $(FLAGS) $(GCFLAGS_C) -o $@ -c $<

%.o: %.c
	$(G) $(FLAGS) -c $< -o $@

clean:
	@make -C libft/ clean
	@rm -f $(OBJ_P)
	@rm -f $(OBJ_C)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME_P) $(NAME_C)

re: fclean all
	@make -C libft/ re
