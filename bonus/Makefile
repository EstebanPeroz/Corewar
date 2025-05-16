##
## EPITECH PROJECT, 2025
## stumper
## File description:
## Makefile
##

CC	= gcc

NAME 		=	corewar

SRC 		= 	src/main.c									\
				src/corewar.c								\
				src/help.c									\
				src/struct/create_champions.c				\
				src/parsing/check_magic.c					\
				src/struct/init_vm_struct.c 				\
				src/struct/free_champions.c 				\
				src/struct/free_vm.c 						\
				src/champions/fill_champions.c 				\
				src/parsing/handle_options.c 				\
				src/parsing/reverse_endian.c 				\
				src/champions/sort_champs.c 				\
				src/champions/manage_address.c 				\
				src/parsing/parse_dump.c 					\
				src/vm/fill_vm.c 							\
				src/vm/dump.c								\
				src/vm/vm_loop.c 							\
				src/vm/check_cooldown.c						\
				src/vm/get_alive_champs.c 					\
				src/vm/get_winner.c							\
				src/champions/place_champions.c				\
				src/champions/find_largest_free_space.c		\
				src/op.c									\
				src/instructions/handle_live.c				\
				src/instructions/handle_fork.c				\
				src/instructions/handle_lfork.c				\
				src/instructions/handle_zjmp.c				\
				src/instructions/handle_ld.c				\
				src/instructions/handle_add.c 				\
				src/instructions/handle_st.c				\
				src/instructions/handle_sti.c				\
				src/instructions/handle_and.c				\
				src/instructions/handle_aff.c 				\
				src/instructions/handle_sub.c				\
				src/instructions/handle_or.c 				\
				src/instructions/handle_xor.c				\
				src/champions/set_cycle_to_wait.c			\
				src/vm/get_instructions.c 					\
				src/struct/instructions_struct_process.c	\
				src/vm/moove_prog_counter.c					\
				src/vm/is_valid_register.c 					\
				src/vm/write_into_arena.c					\
				src/bonus/draw_arena.c 						\
				src/bonus/analyse_events.c 						\
				src/bonus/init_display.c 						\

OBJ 		= 	$(SRC:.c=.o)

INCLUDES	=	-I ./include

CFLAGS 		= -Wall -Wextra -Wshadow $(INCLUDES)

LDFLAGS		= -Llib -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

lib/libmy.a:
	make -C lib/

$(NAME): $(OBJ) lib/libmy.a
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -C lib
	$(RM) -rf $(OBJ)

fclean: clean
	make fclean -C lib
	$(RM) -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
