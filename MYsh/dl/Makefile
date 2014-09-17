

NAME		= libdl.a

SRC		= list_init_destroy.c \
		list_tools.c \
		list_display.c \
		elem_del.c \
		elem_ins.c \
		elem_ins2.c

OBJ		= $(SRC:.c=.o)

CCLIB		= ar rc

ASSEMB		= ranlib

HFILE		= list.h

CC		= cc

CP		= cp

RM		= rm -f


all: $(NAME)

$(NAME): $(OBJ)
	$(CCLIB) $(NAME) $(OBJ)
	$(ASSEMB) $(NAME)
	$(CP) $(NAME) ../
	$(CP) $(HFILE) ../include/

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all
