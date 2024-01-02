NAME = pipex
NAME_BONUS = pipex_bonus
LIBFT = ./Libft/libft.a
CFLAGS = -Wall -Werror -Wextra -g3 -O0

OBJECTS_FOLDER = ./obj/

MANDATORY_FOLDER = ./mandatory/
MANDATORY_SOURCES = $(addprefix $(MANDATORY_FOLDER), main.c helpers.c error_handler.c)
MANDATORY_OBJECTS = $(subst $(MANDATORY_FOLDER),$(OBJECTS_FOLDER),$(MANDATORY_SOURCES:.c=.o))

BONUS_FOLDER = ./bonus/
BONUS_SOURCES = $(addprefix $(BONUS_FOLDER), main_bonus.c helpers_bonus.c open_files_bonus.c)
BONUS_OBJECTS = $(subst $(BONUS_FOLDER),$(OBJECTS_FOLDER),$(BONUS_SOURCES:.c=.o))

all: $(OBJECTS_FOLDER) $(NAME)

$(OBJECTS_FOLDER):
	mkdir $(OBJECTS_FOLDER)

$(NAME): $(LIBFT) $(MANDATORY_OBJECTS)
	cc $(CFLAGS) $(MANDATORY_OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C Libft

$(OBJECTS_FOLDER)%.o: $(MANDATORY_FOLDER)%.c $(MANDATORY_FOLDER)pipex.h
	cc $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(BONUS_OBJECTS)
	cc $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) -o $(NAME_BONUS)

$(OBJECTS_FOLDER)%.o: $(BONUS_FOLDER)%.c $(BONUS_FOLDER)pipex_bonus.h
	cc $(CFLAGS) -c $< -o $@

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes \
	--trace-children=yes --trace-children-skip=*/bin/*,*/sbin/*,./a.out \
	./pipex "/dev/urandom" cat "head -1" "out"

clean:
	rm -rf $(OBJECTS_FOLDER)*

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean re all valgrind
