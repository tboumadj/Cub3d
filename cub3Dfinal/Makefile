# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 17:59:20 by tboumadj          #+#    #+#              #
#    Updated: 2023/02/21 00:07:38 by tboumadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRCS = main.c \
		src/error.c \
		src/parse.c \
		src/print_map.c \
		src/free.c \
		src/init.c \
		src/close.c \
		src/utils.c \
		src/action_ray.c \
		src/raycast.c \
		src/color.c \
		src/action.c \
		src/print.c \
		src/texture.c \
		src/utils_algo.c
CC = gcc
FLAGS = -Wall -Wextra -Werror -Ofast ##-march=native ##-Wno-deprecated
MLX	= -Lmlx -lmlx -framework OpenGl -framework AppKit
RM = rm -f
CHECK = -fsanitize=address
HEADER = cube.h
OBJS = $(SRCS:.c=.o)

# Couleurs
_RED    =   $'\x1b[31m
_GREEN  =   $'\x1b[32m

.c.o:
	@$(CC) $(FLAGS) -Imlx -c $< -o $(<:c=o)

$(NAME): $(OBJS) 
	@$(MAKE) -C libft/
	@$(MAKE) -C mlx/
	@$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME) $(MLX)
	echo "$(_RED)Compilation Cub3d en cours...$(_END)"
	echo "$(_GREEN)$(_BOLD)Fin de la compilation!$(_END)"

.SILENT : $(NAME) $(OBJS)

all     :   $(NAME)

clean   :
			$(MAKE) clean -C libft/
			$(RM) $(OBJS)
fclean  :	clean
			$(MAKE) fclean -C libft/ 
			$(MAKE) clean -C mlx/
			$(RM) libmlx.a $(NAME)
re      :   fclean all
.PHONY  :   all clean fclean re
