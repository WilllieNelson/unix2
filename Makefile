CC=gcc

CFLAGS=-c -Wall

SQ=-l sqlite3
all: 
	$(CC) server.c -o server.out
	$(CC) client.c -o client.out
server:
	$(CC) server.c -o server.out
client:
	$(CC) client.c -o client.out
createdb:
	$(CC) createdb.c $(SQ) -o createdb.out
clean:
	rm -rf *.out
