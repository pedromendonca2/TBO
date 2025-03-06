CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = bst.o client.o
DEPS = bst.h key.h

all: client

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

client: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o client