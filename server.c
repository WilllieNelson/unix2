#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
	
#define PORT 5000
#define BUFSIZE 1024
//
void connect_request(int *sockfd, struct sockaddr_in *my_addr)
{
		int yes = 1; // value in setsockopt function to
	//create a master socket
		if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
			perror("Failed initial Socket");
			exit(1);
		}

		my_addr->sin_family = AF_INET; // address family (AF_INET is for IPv4)
		my_addr->sin_port = htons(5000); // port number
		my_addr->sin_addr.s_addr = INADDR_ANY; // INADDR_ANY will use your current IP address
		memset(my_addr->sin_zero, '\0', sizeof my_addr->sin_zero); //set all the values to zero
	//enable master socket to allow multiple connections return 0 if success (the setsockopt is used to set socket option)
		if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
			perror("Failed set sock option(setsockopt)");
			exit(1);
		}
	//bind the socket to localhost port
		if (bind(*sockfd, (struct sockaddr *)my_addr, sizeof(struct sockaddr)) == -1) {
			perror("Unable to bind");
			exit(1);
		}
	//try to specify maximum of 10 pending connections for the master socket
	if (listen(*sockfd, 10) == -1) {
		perror("Listeners reach limit");
		exit(1);
	}
		printf("\nTCPServer Waiting for client on port 5000\n");
		fflush(stdout);

}

int main() {
	//fd stands for file description
		fd_set master; // declare master file descriptors
		fd_set read_fds; //// declare read socket descriptiors
	//set addr
		int fdmax, i;
		int sockfd = 0;
		struct sockaddr_in my_addr, client_addr;

	//Clear entries from the master set
		FD_ZERO(&master);
	//Clear entries from read socket set
		FD_ZERO(&read_fds);
	//Run connect request function
		connect_request(&sockfd, &my_addr);

	return 0;
}