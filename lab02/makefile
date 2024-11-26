# Nome do compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -Wextra -g

# Arquivos fonte e objetos
SRCS = main.c arvore.c fila.c pilha.c
OBJS = $(SRCS:.c=.o)

# Nome do executável
TARGET = main

# Regra padrão
all: $(TARGET)

# Compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilar arquivos .c para .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)

# Limpar, compilar tudo novamente
rebuild: clean all