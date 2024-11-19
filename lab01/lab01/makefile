# Definir o compilador e as flags de compilação
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Arquivo cabeçalho
HEADER = erastotenes.h

# Arquivos fonte e executáveis correspondentes
SRC_INT = int.c
SRC_BIT = bit.c
SRC_BOOL = bool.c

EXEC_INT = int
EXEC_BIT = bit
EXEC_BOOL = bool

# Alvo padrão para construir todos os executáveis
all: $(EXEC_INT) $(EXEC_BIT) $(EXEC_BOOL)

# Regra para compilar o executável int
$(EXEC_INT): $(SRC_INT) $(HEADER)
	$(CC) $(CFLAGS) -o $(EXEC_INT) $(SRC_INT)

# Regra para compilar o executável bit
$(EXEC_BIT): $(SRC_BIT) $(HEADER)
	$(CC) $(CFLAGS) -o $(EXEC_BIT) $(SRC_BIT)

# Regra para compilar o executável bool
$(EXEC_BOOL): $(SRC_BOOL) $(HEADER)
	$(CC) $(CFLAGS) -o $(EXEC_BOOL) $(SRC_BOOL)

# Limpeza dos executáveis
clean:
	rm -f $(EXEC_INT) $(EXEC_BIT) $(EXEC_BOOL)
