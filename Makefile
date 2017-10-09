# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 00:51:37 by eserebry          #+#    #+#              #
#    Updated: 2017/10/09 06:09:10 by eserebry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror -Ofast
CC = gcc

CMP = -L minilibx -lmlx -framework OpenGL -framework AppKit

SRC = 	main.c\
		usage.c\
		movement.c\
		draw_map.c

OBJ = $(SRCS:.c=.o)
 
SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = fractol.h

RM = rm -rf

GREEN = \033[32m
RED = \033[31m

all: $(NAME)


$(NAME): $(OBJ)
		@make -C libft/
		@$(CC) -o $(NAME) $(SRCS) $(CMP) $(FLAG) libft/libft.a 
		@echo "$(GREEN)fractol: creating object files"

clean: 
		@/bin/$(RM) $(OBJ)
		@make -C libft/ clean

fclean: clean
		@make -C libft/ fclean
		@/bin/$(RM) $(NAME)
		@echo "$(RED)fractol: deleting object files"

re: fclean all

.PHONY: all clean fclean re
.SUFFIXES: .c .o
