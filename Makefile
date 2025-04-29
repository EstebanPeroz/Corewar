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
				src/parsing/parse_args.c					\
				src/help.c									\
				src/struct/init_champs_struct.c				\
				src/parsing/check_magic.c					\
				src/struct/init_vm_struct.c 				\
				src/struct/free_champions.c 				\
				src/struct/free_vm.c 						\
				src/parsing/fill_champions.c 				\
				src/parsing/handle_options.c 				\
				src/parsing/reverse_endian.c 				\

OBJ 		= 	$(SRC:.c=.o)

TESTS =	tests/tests_error_handling.c
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

tests_run: unit_tests
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
