NAME	= libmy_malloc.so

CC	= gcc

RM	= rm -f

SRCS	= ./malloc/malloc.c \
        ./free/free.c \
        ./calloc/calloc.c \
        ./realloc/realloc.c \
        ./reallocarray/reallocarray.c \

OBJS	= $(SRCS:.c=.o)

OBJSROOT    =

CFLAGS = -I ./malloc/ -I ./free/ -I ./calloc -I ./realloc -I ./reallocarray
CFLAGS += -Wall -Wextra -Werror -fPIC

all: $(NAME)

$(NAME): $(OBJS)
	 @ $(CC) -c $(CFLAGS) $(SRCS)
	 @ $(CC) -shared -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(shell find . -type f -name "*.o")

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
