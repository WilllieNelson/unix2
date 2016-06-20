CC=gcc

CFLAGS=-c -Wall

SQ= -l sqlite3

all: 
	$(CC) server.c $(SQ) -o server.out
	$(CC) client.c -o client.out
server: server.c
	$(CC) server.c $(SQ) -o server.out
client: client.c
	$(CC) client.c -o client.out
createdb:
	$(CC) createdb.c $(SQ) -o createdb.out
Son:
	./client.out -s 192.168.100.2:5000 -p 5000 -n Son
SnoopDogg:
	./client.out -s 192.168.100.2:5000 -p 5000 -n Snoop
Hardwell:
	./client.out -s 192.168.100.2:5000 -p 5000 -n Hardwell
clean:
	rm -rf *.out
