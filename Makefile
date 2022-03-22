##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/sys/check_env.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-Wall -Werror

CPPFLAGS	=	-I ./include

CSFML	=	-l csfml-graphics -l csfml-audio -l csfml-system -l csfml-window

LDFLAGS	=	-L ./lib -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -lm -v

clean:
	make fclean -C lib/my
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY	=	all re fclean clean
