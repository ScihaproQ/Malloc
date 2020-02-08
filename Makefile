NAME	= libmy_malloc.so

CC	= gcc

RM	= rm -f

SRCS	= ./malloc/malloc.c \
        ./free/free.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./malloc/ -I ./free/
CFLAGS += -Wall -Wextra -Werror -fPIC

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) -c $(CFLAGS) $(SRCS)
	 $(CC) -shared -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
