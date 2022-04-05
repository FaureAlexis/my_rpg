##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/rpg.c	\
		src/sys/check_env.c	\
		src/scenes/manage_scenes.c	\
		src/scenes/pause_scene.c	\
		src/init/init_game.c	\
		src/init/init_player.c	\
		src/init/init_window.c	\
		src/free/free_game_struct.c	\
		src/events/get_event.c	\
		src/events/event_close.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-Wall -Werror

CPPFLAGS	=	-I ./include

CSFML	=	-l csfml-graphics -l csfml-audio -l csfml-system -l csfml-window

LDFLAGS	=	-L ./lib -lmy

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
