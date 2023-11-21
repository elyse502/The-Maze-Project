# compiler to use
CC=gcc

# Flags to create object files with
CFLAGS=-g -Wall -Werror -Wextra -pedantic
# Flags to link the SDL2 library
SDL_FLAGS=-I/usr/local/include/SDL2 -L/usr/lib/x86_64-linux-gnu -lSDL2

# All C program files
SRC=create_maze.c create_world.c dist_checks.c draw.c event_handlers.c free_stuff.c init_instance.c main_maze.c movement.c win.c
# The names of all object files
OBJ=$(SRC:.c=.o)
# Executable name
NAME=maze

# Removal command
RM=rm

# Compile all files into the executable
# CFLAGS will only be used when creating object files
# SDL_FLAGS includes necessary libraries to link
all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(SDL_FLAGS)

# Remove all Emacs temp files (~)
clean:
	$(RM) -f *~

# Remove all object files (.o)
oclean:
	$(RM) -f $(OBJ)

# Remove temp files, object files, and executable
fclean: clean oclean
	$(RM) -f $(NAME)

# Run full clean and recompile all files
re: fclean all
