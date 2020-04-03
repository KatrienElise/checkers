
NAME_1 = push_swap
NAME_2 = checkers
FLAGS = -Wall -Wextra -Werror
#GCC = gcc
FUNCS = src/input_check_store.c src/store.c src/error.c src/test.c src/heart.c \
src/steps_choose.c #src/heart_push.c
OBJ = $(FUNCS:.c =.o)
L_C = libft/*.c
L_O = $(L_C:.c = .o)
#INCL = includes/swap.h

# target: dependencies
#	action

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ) main.o
	gcc $(FLAGS) -o $(NAME_1) $(OBJ) main.o $(L_O)
$(NAME_2): $(OBJ) main.o
	gcc $(FLAGS) -o $(NAME_2) $(OBJ) main.o $(L_O)
$(OBJ): $(FUNCS) main.c $(L_C)
	gcc $(FLAGS) -I includes/ -c $(FUNCS) main.c
	make -C libft/
clean:
	rm -f *.o main.o $(NAME_1) $(NAME_2)
re: clean all
