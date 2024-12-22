# Variáveis
CC = gcc
CFLAGS = -I.
SOURCES = client.c
TARGETS = quick_1 quick_2 quick_3 quick_4 quick_5 quick_6 quick_7

.PHONY: all clean

all: $(TARGETS)

quick_%: quick_%.c $(SOURCES)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(TARGETS)