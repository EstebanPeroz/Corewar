##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

OBJ	=	$(SRC:.c=.o)

SRC = 	my_str_to_word_array.c	\
		my_getnbr.c				\
		my_strlen.c				\
		my_strdup.c				\
		my_strcmp.c				\
		my_put_map.c			\
		my_putstr.c				\
		my_puterr.c				\
		get_str_between.c		\
		str_paste.c				\
		str_contain.c			\
		array_manip.c			\
		my_strstrcat.c			\
		bytes_to_int.c			\
		my_put_nbr.c			\

NAME	=	libmy.a

CFLAGS = -I../include -Wextra -Wall -Wshadow

all:	$(NAME)


$(NAME):	$(OBJ)
	$(AR) cr $(NAME) $(OBJ)

clean:
	$(RM) -f $(OBJ)

fclean:	clean
	$(RM) -f $(NAME)

re:	fclean all
