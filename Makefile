CC=gcc

CFLAGS=-c -Wall

all: 
	$(CC) server.c -o server.out
	$(CC) client.c -o client.out
server:
	$(CC) server.c -o server.out
client:
	$(CC) client.c -o client.out
clean:
	rm -rf *.out
