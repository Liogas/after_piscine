CC=gcc
CFLAGS=-Wall -Werror -Wextra
PROG=ft_tail
FILES=*.c

all:
	$(CC) $(CFLAGS) -g -o $(PROG) $(FILES)

run:
	./$(PROG) -c 75 test.txt test2.txt

run_val:
	valgrind -s ./$(PROG) -c 75 test.txt test2.txt

.PHONY: clean fclean

clean:
	rm $(PROG)

fclean:
	rm $(PROG)