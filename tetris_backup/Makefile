##
## Makefile for Makefile in /home/ouranos27/my_desktop/PSU/PSU_2016_my_sokoban
## 
## Made by philippe kam
## Login   <philippe.kam@epitech.eu>
## 
## Started on  Tue Dec 13 17:17:37 2016 philippe kam
## Last update Mon Feb 27 11:29:54 2017 philippe kam
##

CFLAGS	+= -Wall -Wextra -Werror -I./include -L./lib/ -lmy

SRC	=	main.c		\
		usage.c		\
		my_strcmp.c	\
		my_putstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -g $(SRC) $(CFLAGS) -o $(NAME) -lncurses

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		re fclean all
