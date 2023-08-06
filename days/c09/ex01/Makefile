CC=gcc
CFLAGS=-Wall -Wextra -Werror
AR=@ar -rv
SRCS=srcs/*.c
LIBFT=libft.a


all : $(LIBFT)

re:
		rm srcs/*.o ./libft.a
		$(CC) $(CFLAGS) -c $(SRCS)
		mv *.o srcs/
		$(AR) libft.a srcs/*.o

.PHONY: clean fclean libft.a

libft.a:
	$(CC) $(CFLAGS) -c $(SRCS)
	mv *.o srcs/
	$(AR) libft.a srcs/*.o

clean:
		rm -rf srcs/*.o

fclean:
		rm srcs/*.o ./libft.a


