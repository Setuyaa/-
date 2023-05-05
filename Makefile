NAME = compilator.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRCS= *.c 
STYLE=clang-format --style=google
FORMAT= *.c

test_memory: 
	$(CC) memory.c test_memory.c -o test1
	./test1

test_stack:
	$(CC) memory.c test_stack.c stack.c -o test2
	./test2

test_deque:
	$(CC) memory.c test_deque.c deque.c -o test3
	./test3
test_hash:
	$(CC) memory.c test_hash.c hash.c -o test4
	./test4

test_queue:
	$(CC) memory.c test_queue.c queue.c -o test2
	./test5

check_style:
	$(STYLE) -n $(FORMAT) $(TEST_SRC)

style:
	$(STYLE) -i $(FORMAT) $(TEST_SRC)

clean:
	rm -rf *.o *.a test?

rebuild : clean all
