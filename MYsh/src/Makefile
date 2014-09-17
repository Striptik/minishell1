NAME		= mysh

CC		= cc

CP		= cp

RM		= rm -f

SRC		= env_path.c \
		env_null.c \
		exec.c \
		tools.c \
		pars.c \
		create_word_tab.c \
		builtin1.c \
		minishell.c

OBJ		= $(SRC:.c=.o)

LIB		= -ldl -L../ -lmy -L../

HFILE		= mysh.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CP) $(HFILE) ../include/
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	$(CP)  $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all
