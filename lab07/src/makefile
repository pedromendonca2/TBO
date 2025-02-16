CC = gcc
CFLAGS = -Wall -Wextra -O2
OBJ = main.o msd.o str.o
TARGET = a.out

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c msd.h str.h
	$(CC) $(CFLAGS) -c main.c

msd.o: msd.c msd.h str.h
	$(CC) $(CFLAGS) -c msd.c

str.o: str.c str.h
	$(CC) $(CFLAGS) -c str.c

clean:
	rm -f $(OBJ) $(TARGET)
