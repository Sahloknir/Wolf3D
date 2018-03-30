# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axbal <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 14:54:13 by axbal             #+#    #+#              #
#    Updated: 2018/03/29 17:42:25 by axbal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRCDIR = sources
SRCS = main.c		\
	   utility.c	\
	   init.c		\
	   map.c		\

OBJDIR = obj
OBJS = $(SRCS:.c=.o)

SRC = $(addprefix $(SRCDIR)/,$(SRCS))
OBJ = $(addprefix $(OBJDIR)/,$(OBJS))

FLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGl -framework AppKit

LIBFT = ./Libft/libft.a
MLX = ./mlx/libmlx.a

INCLUDE = -Iincludes

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	cc -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(FRAMEWORK)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	cc $(FLAGS) $(INCLUDE) -o $@ -c $<

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

clean:
	make -C libft clean
	@rm -rf $(OBJDIR) 2> /dev/null || true

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean
	make -C mlx clean

re: fclean all