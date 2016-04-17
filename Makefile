##
## Makefile for Makefile in /home/roig_a/GAME
## 
## Made by Antoine Roig
## Login   <roig_a@epitech.net>
## 
## Started on  Fri Jan 29 19:59:03 2016 Antoine Roig
## Last update Sat Apr 16 14:45:53 2016 Antoine Roig
##

NAME            =               fround

CFLAGS		=		-Iinclude

LDFLAGS         =               -lncurses -lSDL -lSDL_ttf -lSDL_image -lm

SRC             =               sources/main.c		\
				sources/get_map.c	\
				sources/mouvement.c	\
				sources/create_map.c

OBJ             =               $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		cc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : clean all

.PHONY : all re clean fclean
