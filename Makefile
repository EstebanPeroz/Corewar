##
## EPITECH PROJECT, 2025
## stumper
## File description:
## Makefile
##

CC	= gcc

NAME 		=	corewar

TEST_NAME	=	unit_tests

SRC 		= 	src/main.c							\
				src/parse_args.c					\
				src/help.c							\
				src/get_champs.c					\
				src/check_magic.c					\

OBJ 		= 	$(SRC:.c=.o)

TESTS =	tests/tests_error_handling.c				\

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

tests_run:
	make unit_tests
	./$(TEST_NAME)
	gcovr --exclude tests

clean:
	make clean -C lib
	rm -f $(OBJ)
	rm -rf $(TEST_OBJ)
	rm -rf $(TEST_GCNO)
	rm -rf $(TEST_GCDA)

fclean: clean
	make fclean -C lib
	rm -f $(NAME)
	rm -f $(TEST_NAME)

##functional_test:

re: 	fclean all

.PHONY: all clean fclean re unit_tests tests_run
