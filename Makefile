#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 01:16:19 by smaksymy          #+#    #+#              #
#    Updated: 2017/10/31 05:05:49 by smaksymy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= RTv1

SRC    = src/main.c \
	src/make_im.c \
    src/scene3.c \
    src/scene2.c \
    src/scene1.c \
    src/scene4.c \
    src/scene5.c \
    src/tracing.c \
    src/check_rot.c \
    src/check_hit.c \
    src/norm.c \
    src/vector.c \
	src/sum.c \
	src/error.c \

SUBMAKE = ./libft

CD = cd ..

MAKE = make

OBJECT = $(SRC:.c=.o)

CC  = gcc

FLAGS   = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit

LIB = -L./libft -lft -I.

all : $(NAME)

$(NAME): $(OBJECT)
	cd $(SUBMAKE) && $(MAKE) && $(CD)
	$(CC) $(FLAGS) -o $(NAME) $(MLX_FLAGS) $(OBJECT) $(LIB)

clean :
	rm -rf src/*.o
	rm -rf libft/*.o

fclean : clean
	rm -rf RTv1
	rm -rf libft/libft.a

re : fclean all