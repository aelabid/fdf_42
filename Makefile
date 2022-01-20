# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 20:39:47 by aelabid           #+#    #+#              #
#    Updated: 2022/01/10 13:14:46 by aelabid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = atoi.c bresenham.c convert_color.c create_line.c create_matrix.c \
		draw_map.c get_next_line.c get_next_line_utils.c handle_input.c \
		isometric.c main.c openfd.c put_pixel.c split.c zoom.c 
	
OBJ = $(SRC:.c=.o)

CC_FLAGS = -Wall -Wextra -Werror
CC = cc

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
MATH_FLAGS = -lm

NAME = fdf
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ) -o $@
	
%.o: %.c 
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm -rf $(OBJ)
		
fclean: clean
	rm -rf $(NAME)

re: fclean all