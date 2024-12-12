# Makefile para compilar e executar merges com client.c

CC = gcc
CFLAGS = -Wall -Wextra -O2
CLIENT = client
MERGES = merge_1 merge_2 merge_3 merge_4 merge_5 merge_6 merge_7
OBJECTS = $(CLIENT).o

all: $(MERGES)

$(CLIENT).o: $(CLIENT).c
	$(CC) $(CFLAGS) -c $(CLIENT).c -o $(CLIENT).o

merge_%: merge_%.c $(CLIENT).o
	$(CC) $(CFLAGS) $^ -o $@

run: all
	@for exe in $(MERGES); do \
	    echo "Executando $$exe"; \
	    ./executor_script.sh; \
	done

clean:
	rm -f $(MERGES) $(OBJECTS) temp_result.txt
