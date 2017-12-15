NAME = ft_ls

SRC =	ft_ls.c parsing.c file_rights.c \

SRCO = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c ft_ls.h
	gcc $(CFLAGS) -c $<

$(NAME)	:	$(OBJS)
			gcc $(CFLAGS) -c $(SRC)
			gcc $(CFLAGS) -o $(NAME) $(SRCO) libft/libft.a

clean:
	rm -f $(SRCO)

fclean:
	rm -f $(NAME)
	rm -f $(SRCO)

re: fclean $(NAME) 
