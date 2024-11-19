# Nome do executável
EXEC = programa

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Arquivos fonte e objetos
SRC = main.c pilha.c
OBJ = main.o pilha.o

# Regra principal para criar o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Regras para compilar os arquivos .o a partir dos .c
main.o: main.c pilha.h
	$(CC) $(CFLAGS) -c main.c

pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c pilha.c

# Limpeza dos arquivos objeto e executável
clean:
	rm -f $(OBJ) $(EXEC)

# Limpeza dos arquivos objeto
clean_obj:
	rm -f $(OBJ)

# Recompilar tudo
rebuild: clean $(EXEC)