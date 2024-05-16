CC = gcc
CFLAGS = -Wall -g
all: main
main: main.c arquivo.c solucao.c
	$(CC) $(CFLAGS) -o main main.c arquivo.c solucao.c
clean:
	rm -f main