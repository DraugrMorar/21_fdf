# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/27 15:11:29 by dmorar            #+#    #+#              #
#    Updated: 2019/02/14 14:09:38 by dmorar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

OBJ = $(patsubst %.c, %.o, $(SRC))

SRC = ./src/main.c ./src/draw.c ./src/color.c ./src/read_write.c ./src/key.c ./src/data.c

INC = fdf.h

LIB = ./libft/libft.a

FLAGS = 
# -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -g $(FLAGS) -o $(NAME) $^ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIB) -I $(INC) 

%.o:%.c
	gcc $(FLAGS) -c $^ -o $@ -I $(INC)

run: 
	gcc -g $(SRC) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIB) -I $(INC) -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./libft 
	/bin/rm -f $(NAME)

re: fclean all
