# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 21:56:01 by yessemna          #+#    #+#              #
#    Updated: 2024/02/11 21:59:33 by yessemna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_B = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f

SRC =	./Mandatory/get_next_line.c ./Mandatory/extra_check_map.c ./Mandatory/check_map.c ./Mandatory/ft_itoa.c\
		./Mandatory/ft_bzero.c ./Mandatory/ft_calloc.c ./Mandatory/ft_memset.c ./Mandatory/ft_putendl_fd.c\
		./Mandatory/ft_split.c  ./Mandatory/ft_strchr.c ./Mandatory/ft_strjoin.c ./Mandatory/ft_strlen.c ./Mandatory/message.c\
		./Mandatory/ft_substr.c ./Mandatory/init.c ./Mandatory/load_map.c ./Mandatory/set_items.c ./Mandatory/so_long.c\
		./Mandatory/ft_putnbr_fd.c ./Mandatory/ft_putchar_fd.c ./Mandatory/sltools.c\
		
SRC_B =	./Bonus/get_next_line_bonus.c ./Bonus/extra_check_map_bonus.c ./Bonus/check_map_bonus.c ./Bonus/ft_itoa_bonus.c\
		./Bonus/ft_bzero_bonus.c ./Bonus/ft_calloc_bonus.c ./Bonus/ft_memset_bonus.c ./Bonus/ft_putendl_fd_bonus.c ./Bonus/animation_bonus.c\
		./Bonus/ft_split_bonus.c  ./Bonus/ft_strchr_bonus.c ./Bonus/ft_strjoin_bonus.c ./Bonus/ft_strlen_bonus.c ./Bonus/message_bonus.c\
		./Bonus/ft_substr_bonus.c ./Bonus/init_bonus.c ./Bonus/load_map_bonus.c ./Bonus/set_items_bonus.c ./Bonus/so_long_bonus.c ./Bonus/finder.c\
		./Bonus/sltools_bonus.c\

OBJ = $(SRC:%.c=%.o)
OBJ_B = $(SRC_B:%.c=%.o)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

$(NAME_B): $(OBJ_B)
	@$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B) -lmlx -framework OpenGL -framework AppKit

./Mandatory/%.o: ./Mandatory/%.c ./Mandatory/so_long.h
	@$(CC) $(CFLAGS) -o $@ -c $<
	
./Bonus/%.o: ./Bonus/%.c ./Bonus/so_long_bonus.h
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

bonus : $(NAME_B)

clean:
	@$(RM)	$(OBJ)	$(OBJ_B)

fclean:	clean
	@$(RM)	$(NAME)	$(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus