# Definir o compilador e as flags de compilação
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Arquivos fonte
SRC1 = josefo_1.c
SRC2 = josefo_2.c

# Nomes dos executáveis
EXEC1 = josefo1
EXEC2 = josefo2

# Alvo padrão para construir ambos os executáveis
all: $(EXEC1) $(EXEC2)

# Regras para compilar josefo1
$(EXEC1): $(SRC1)
	$(CC) $(CFLAGS) -o $(EXEC1) $(SRC1)

# Regras para compilar josefo2
$(EXEC2): $(SRC2)
	$(CC) $(CFLAGS) -o $(EXEC2) $(SRC2)

# Limpeza dos executáveis
clean:
	rm -f $(EXEC1) $(EXEC2)