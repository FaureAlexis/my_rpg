##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	incomplete_func/my_find_prime_sup.c	\
		incomplete_func/my_is_prime.c	\
		incomplete_func/my_showmem.c	\
		incomplete_func/my_showstr.c	\
		incomplete_func/my_sort_int_array.c	\
		incomplete_func/my_strcapitalize.c	\
		my_funcs/my_atoi.c	\
		my_funcs/my_compute_power_rec.c	\
		my_funcs/my_compute_square_root.c	\
		my_funcs/my_getnbr_base.c	\
		my_funcs/my_getnbr.c	\
		my_funcs/my_int_to_str.c	\
		my_funcs/my_isneg.c	\
		my_funcs/my_revstr.c	\
		my_funcs/my_str_isalpha.c	\
		my_funcs/my_str_islower.c	\
		my_funcs/my_str_isnum.c	\
		my_funcs/my_str_isprintable.c	\
		my_funcs/my_str_isupper.c	\
		my_funcs/my_strcat.c	\
		my_funcs/my_strcmp.c	\
		my_funcs/my_strcpy.c	\
		my_funcs/my_strdup.c	\
		my_funcs/my_strlowcase.c	\
		my_funcs/my_strncat.c	\
		my_funcs/my_strncmp.c	\
		my_funcs/my_strncpy.c	\
		my_funcs/my_strndup.c	\
		my_funcs/my_strstr.c	\
		my_funcs/my_strupcase.c	\
		my_funcs/my_swap.c	\
		my_printf/basic_flags.c	\
		my_printf/features.c	\
		my_printf/my_printf.c	\
		my_printf/my_put_nbr.c	\
		my_printf/my_put_ul.c	\
		my_printf/my_putchar.c	\
		my_printf/my_putnbr_base.c	\
		my_printf/my_putstr.c	\
		my_printf/my_str_to_oct.c	\
		my_printf/my_strlen.c	\
		others_funcs/check_sign.c	\
		others_funcs/counter_sign.c	\
		others_funcs/return_index.c	\
		others_funcs/reverse_opp_numb.c	\
		ll_lib/basic_func_llc.c	\
		ll_lib/basic_func_lli.c	\
		ll_lib/general_func.c	\
		ll_lib/get_from_nodec.c	\
		ll_lib/get_from_nodei.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS =	-I ./include

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..
	cp -r include ../..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all

.PHONY	=	all clean fclean re
