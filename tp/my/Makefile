##
## Makefile for Makefile in /home/loisel_k/rendu/Piscine-C-lib/my
## 
## Made by loisel_k
## Login   <loisel_k@epitech.net>
## 
## Started on  Mon Oct 21 12:23:10 2013 loisel_k
## Last update Tue Nov 19 14:33:10 2013 kevin loiseleur
##

CC	= gcc -c

CCLIB	= ar rc

ASSEMB	= ranlib

RM	= rm -f

CP	= cp

NAME	= libmy.a

SRCS	= my_find_prime_sup.c \
	my_putstr.c \
        my_strcmp.c \
	my_strlen.c \
	my_nblen.c \
	my_getnbr.c \
	my_revstr.c \
	my_strcpy.c \
	my_strlowcase.c \
	my_isneg.c \
	my_showmem.c \
	my_str_isalpha.c \
	my_strncat.c \
	my_is_prime.c \
	my_showstr.c \
	my_str_islower.c \
	my_strncmp.c \
	my_power_rec.c \
	my_sort_int_tab.c \
	my_str_isnum.c \
	my_strncpy.c \
	my_putchar.c \
	my_square_root.c \
	my_str_isprintable.c \
	my_strstr.c \
	my_put_nbr.c \
	my_put_nbr_base.c \
	my_strcapitalize.c \
	my_str_isupper.c \
	my_strupcase.c \
	my_put_nbr_rec.c \
	my_strcat.c \
	my_strlcat.c \
	my_swap.c \
	my_alloc.c \
	my_printf.c \
	my_printf_flags_char.c \
	my_printf_flags_int.c \
	my_printf_flags_convers.c

HFILE	= my.h \
	my_printf.h

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CCLIB) $(NAME) $(OBJS)
	$(ASSEMB) $(NAME)
	$(CP) $(NAME) ../
	$(CP) $(HFILE) ../include/

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
