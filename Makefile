##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

ifndef VERBOSE
.SILENT:
endif

SRC_BUTTON				=	button/init_buttons.c \
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
							button/create_and_set_buttons.c \
							button/clicked/clicked_state_game.c \
							button/clicked/clicked_state_save.c \
							button/clicked/clicked_state_keybind.c \
							button/clicked/clicked_state_help.c \
							button/clicked/clicked_state_settings.c \
							button/clicked/clicked_state_main.c \
							button/clicked/clicked_state_lose.c \
							button/clicked/clicked_state_win.c \
							button/clicked/clicked_state_pause.c

SRC_SCENES_DISPLAY 		=	scenes/display/display_main_menu.c \
							scenes/display/display_save.c \
							scenes/display/display_help.c \
							scenes/display/display_game.c \
							scenes/display/display_pause.c \
							scenes/display/display_skin_cus.c \
							scenes/display/display_keybind.c \
							scenes/display/display_lose.c \
							scenes/display/display_win.c \
							scenes/display/display_settings.c

SRC_SCENES_BUTTON_POS	=	scenes/button_pos/button_pos_menu.c \
							scenes/button_pos/button_pos_game.c \
							scenes/button_pos/button_pos_save.c \
							scenes/button_pos/button_pos_help.c \
							scenes/button_pos/button_pos_pause.c \
							scenes/button_pos/button_pos_lose.c \
							scenes/button_pos/button_pos_keybind.c \
							scenes/button_pos/button_pos_settings.c \
							scenes/button_pos/button_pos_skin_cus.c \
							scenes/button_pos/resize_all_buttons.c \
							scenes/button_pos/resize_big_buttons.c \
							scenes/button_pos/resize_mid_buttons.c \
							scenes/button_pos/resize_sml_buttons.c

SRC_SCENES_CREATE		=	scenes/create/create_scenes.c \
							scenes/create/init_scenes.c

SRC_SCENES_SETTINGS 	=	scenes/instance/settings/volume_settings.c \
							scenes/instance/settings/screen_settings.c

SRC_SCN_START			=	starting_scene/starting_game_scene.c \
							starting_scene/starting_help_scene.c \
							starting_scene/starting_keybind_scene.c \
							starting_scene/starting_main_menu_scene.c \
							starting_scene/starting_pause_scene.c \
							starting_scene/starting_save_scene.c \
							starting_scene/starting_settings_scene.c \
							starting_scene/starting_lose_scene.c \
							starting_scene/starting_win_scene.c \
							starting_scene/starting_skin_custom_scene.c

SRC_SCN_INST			=	manage_scenes.c \
							pause_scene.c \
							game_scene.c \
							save_scene.c \
							keybind_scene.c \
							settings_scene.c \
							skin_custom_scene.c \
							lose_scene.c \
							win_scene.c \
							help_scene.c \
							main_menu_scene.c

SRC_SCENES 				=	$(SRC_SCENES_DISPLAY) \
							$(SRC_SCENES_BUTTON_POS) \
							$(SRC_SCENES_CREATE) \
							$(SRC_SCENES_SETTINGS) \
							$(addprefix scenes/instance/, $(SRC_SCN_START)) \
							$(addprefix scenes/instance/, $(SRC_SCN_INST))

SRC_ANIMATIONS			=	animations/player_animations.c \
							animations/player_animations_features.c \
							animations/change_color_skin_left.c \
							animations/change_color_skin_right.c \
							animations/move_player.c \
							animations/anim_particle.c \
							animations/anim_artific.c

SRC_EVENT				=	events/get_event.c \
							events/player_collision.c \
							events/event_inventory.c \
							events/event_zoom.c \
							events/event_close.c \
							events/event_skin_choice.c

SRC_INIT				=	init/init_clock.c \
							init/init_game.c \
							init/init_help.c \
							init/init_inventory.c \
							init/init_settings.c \
							init/init_volume.c \
							init/init_skin_custom.c \
							init/init_map.c \
							init/init_player.c \
							init/init_life_bar_player.c \
							init/create_dust.c \
							init/init_mob.c \
							init/init_spe_obstacle.c \
							init/init_obstacle.c \
							init/init_window.c \
							init/create_particle.c \
							init/init_keys.c		\
							init/init_help_keys.c 	\

SRC_ERROR 				=	error/error.c \
							error/help.c

SRC_FREE				=	free/free_game_struct.c \
							free/free_player.c \
							free/free_button.c \
							free/free_a_particle.c \
							free/free_menu.c	\
							free/free_text.c

SRC_EP					= 	src_ep/game_test.c \
							src_ep/main.c \
							src_ep/node.c \
							src_ep/obstacle.c \
							src_ep/open_file.c \
							src_ep/pos.c \
							src_ep/tab.c

SRC_MENU				=	menu/init_menus.c \
							menu/create_menu.c \
							menu/display_menu.c \
							menu/display_game.c

SRC_MAP					=	map/game_test.c 		\
							map/node.c 				\
							map/obstacle.c 			\
							map/player_damage.c 	\
							map/display_mob_life.c	\
							map/set_tree_hitbox.c 	\
							map/open_file.c 		\
							map/pos.c 				\
							map/tab.c 				\
							map/mob.c 				\
							map/slime.c 			\
							map/skeleton.c 			\
							map/hasbulla.c			\
							map/display_slime.c 	\
							map/display_skeleton.c 	\
							map/display_hasbulla.c	\
							map/spe_obstacle.c 		\
							map/move.c

SRC_SAVE				=	save/saving/open_file.c \
							save/saving/save_settings.c \
							save/load/load_settings.c \
							save/load/load_tools.c

SRC_KEYS				=	keybinding/resolve_keys.c 	\


SRC_SYS					=	sys/check_env.c \
							sys/check_ressources.c \
							sys/check_game_assets.c

SRC 					=	$(SRC_BUTTON) \
							$(SRC_INIT) \
							$(SRC_FREE) \
							$(SRC_EVENT) \
							$(SRC_SCENES) \
							$(SRC_ANIMATIONS) \
							$(SRC_MAP) \
							$(SRC_SAVE) \
							$(SRC_KEYS)	\
							$(SRC_SYS)	\
							main.c	\
							rpg.c

OBJ						=	$(addprefix src/, $(SRC:.c=.o))

NAME					=	my_rpg

CPPFLAGS				=	-I ./include -g -Werror -Wall -Wextra

CSFML					=	-l csfml-graphics -l csfml-audio -l csfml-system \
							-l csfml-window

LDFLAGS					=	-L ./lib/ -lmy

all:	$(NAME)

PREBUILD:
	@echo -e "\e[92mCompiling sources : \e[34m$(NAME)\e[5m . \e[0m\e[5m . \
	\e[34m . \e[0m"

$(NAME):	PREBUILD $(OBJ)
	@echo -e "\e[92mBuilding librairy : \e[34mmy\e[5m . \e[0m\e[5m . \e[34m \
	. \e[0m"
	@make -C lib/my > /dev/null
	@echo -e "\e[92mBuilding sources : \e[34m$(NAME)\e[5m . \e[0m\e[5m . \
	\e[34m . \e[0m"
	@$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CSFML) -lm
	@echo -e "\e[92m\e[1mBuild successfull !\e[0m"

clean:
	@echo -e "\e[95mCleaning librairy : \e[34mmy\e[0m"
	@make fclean -C lib/my &> /dev/null
	@echo -e "\e[95mCleaning sources : \e[34m$(NAME)\e[0m"
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY	=	all re fclean clean
