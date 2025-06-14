##
## EPITECH PROJECT, 2025
## stumper
## File description:
## Makefile
##

CC	= gcc

NAME 		=	corewar

TEST_NAME	=	unit_tests

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

OBJ 		= 	$(SRC:.c=.o)

TESTS   	=	tests/tests_error_handling.c 				\
				tests/place_champions_tests.c 				\
				tests/test_loop.c 							\
				tests/func_tests.c 							\
				tests/test_dump.c 							\
				tests/tests_byte_manips.c 					\
				tests/test_zjmp.c 							\
				tests/test_ld.c 							\
				tests/test_fork.c 							\
				tests/tests_add.c 							\
				tests/tests_st.c 							\
				tests/tests_sti.c 							\
				tests/tests_and.c 							\
				tests/test_aff.c 							\
				tests/tests_sub.c 							\
				tests/tests_or.c 							\
				tests/tests_xor.c 							\

TESTS += $(filter-out src/main.c, $(SRC))
TEST_OBJ	=	$(TESTS:.c=.o)
TEST_GCDA	=	$(TESTS:.c=.gcda)
TEST_GCNO	=	$(TESTS:.c=.gcno)

INCLUDES	=	-I ./include

CFLAGS 		= -Wall -Wextra -Wshadow $(INCLUDES)

LDFLAGS		= -Llib -lmy

all:	$(NAME)

lib/libmy.a:
	make -C lib/

$(NAME): $(OBJ) lib/libmy.a
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

unit_tests: CFLAGS += --coverage
unit_tests: LDFLAGS += -lcriterion --coverage
unit_tests:	$(TEST_OBJ) lib/libmy.a
		$(CC) -o $(TEST_NAME) $(TEST_OBJ) $(LDFLAGS)

tests_run: fclean unit_tests
	./$(TEST_NAME)
	gcovr --exclude tests

clean:
	make clean -C lib
	$(RM) -rf $(TEST_OBJ)
	$(RM) -rf $(OBJ)
	$(RM) -rf $(TEST_GCNO)
	$(RM) -rf $(TEST_GCDA)

fclean: clean
	make fclean -C lib
	$(RM) -f $(NAME)
	$(RM) -f $(TEST_NAME)

re: 	fclean all

.PHONY: all clean fclean re unit_tests tests_run
