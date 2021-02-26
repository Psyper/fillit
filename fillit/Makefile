

NAME = fillit
HEADER = fillit.h
COMPILERC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES  =  fillit.c getinput.c ft_putstr.c ft_putchar.c ft_create.c map.c solve.c figure_functions.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(COMPILERC) -o $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
	$(COMPILERC) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
