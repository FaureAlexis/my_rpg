##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC_BUTTON		=	button/init_buttons.c \
					button/create/create_big_buttons.c \
					button/create/create_mid_buttons.c \
					button/create/create_small_buttons.c \
					button/hover/hover_big_buttons.c \
					button/hover/hover_medium_buttons.c \
					button/hover/hover_small_buttons.c \
					button/hover/hover_buttons.c \
					button/set_rect/set_rect_big_buttons.c \
					button/set_rect/set_rect_mid_buttons.c \
					button/set_rect/set_rect_small_buttons.c \
					button/create_and_set_buttons.c

SRC_SCENES =		scenes/display/display_main_menu.c \
					scenes/display/display_help.c \
					scenes/display/display_game.c \
					scenes/display/display_pause.c \
					scenes/display/display_settings.c \
					scenes/button_pos/button_pos_menu.c \
					scenes/create/create_scenes.c \
					scenes/create/init_scenes.c \
					scenes/instance/manage_scenes.c \
					scenes/instance/pause_scene.c \
					scenes/instance/game_scene.c \
					scenes/instance/settings_scene.c \
					scenes/instance/help_scene.c \
					scenes/instance/volume_settings.c \
					scenes/instance/main_menu_scene.c


SRC_EVENT		=	events/get_event.c \
					events/event_close.c

SRC_INIT		=	init/init_game.c \
					init/init_player.c \
					init/init_window.c

SRC_ERROR 		=	error/error.c \
					error/help.c

SRC_FREE		=	free/free_game_struct.c

SRC_EP			= 	src_ep/game_test.c 	\
					src_ep/main.c 	   	\
					src_ep/node.c 		\
					src_ep/obstacle.c 	\
					src_ep/open_file.c 	\
					src_ep/pos.c 		\
					src_ep/tab.c

SRC_MENU		=	menu/init_menus.c \
					menu/create_menu.c \
					menu/display_menu.c \
					menu/display_game.c

SRC_EP			= 	src_ep/game_test.c 	\
					src_ep/main.c 	   	\
					src_ep/node.c 		\
					src_ep/obstacle.c 	\
					src_ep/open_file.c 	\
					src_ep/pos.c 		\
					src_ep/tab.c

SRC 			=	$(SRC_BUTTON) \
					$(SRC_INIT) \
					$(SRC_FREE) \
					$(SRC_EVENT) \
					$(SRC_SCENES) \
					sys/check_env.c \
					main.c	\
					rpg.c

OBJ				=    $(addprefix src/, $(SRC:.c=.o))
#OBJ 				=	$(SRC_EP:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-I ./include -L ./lib -lmy

CSFML	=	-l csfml-graphics -l csfml-audio -l csfml-system -l csfml-window

LDFLAGS	=	 -I ./include -L ./lib -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML) -lm

clean:
	make fclean -C lib/my
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY	=	all re fclean clean
