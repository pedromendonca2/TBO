# Compilador e flags
CC = gcc
CFLAGS = -Wall -O2

# Arquivo cliente
CLIENT = client.c

# Algoritmos de ordenação
ALGORITHMS = select_sort insert_sort bubble_sort shaker_sort

# Gerar os executáveis a partir das combinações cliente + algoritmo
TARGETS = $(ALGORITHMS:%=%_client)

all: $(TARGETS)

# Regra para compilar cada executável
%_client: $(CLIENT) %.c
	$(CC) $(CFLAGS) -o $@ $(CLIENT) $*.c

clean:
	rm -f $(TARGETS)