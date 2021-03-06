#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <sqlite3.h> 
	
#define PORT 5000
#define BUFSIZE 1024
//
#define id 9
char listeners[id];
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
//sockfd is the usual socket file descriptor from the socket() system call, its the number of connections allowed on the incoming queue
void connection_accept(fd_set *master, int *fdmax, int sockfd, struct sockaddr_in *client_addr)
{
	socklen_t addrlen;
	int newsockfd;
	char recv_buf[BUFSIZE];

	addrlen = sizeof(struct sockaddr_in);
	if((newsockfd = accept(sockfd, (struct sockaddr *)client_addr, &addrlen)) == -1)
	{
		perror("accept");
		exit(1);	
	} else {
		FD_SET(newsockfd, master);
		if (newsockfd > *fdmax) {
			*fdmax = newsockfd;
		}
		//recv(sockfd, recv_buf, BUFSIZE, 0);
		printf("new connection from %s on port %d \n", inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));
		//printf("%s \n",recv_buf);
	}
}
// The FD_ISSET function returns true if FD is in the set
void send_to_all(int j, int i, int sockfd, int nbytes_recvd, char *recv_buf, fd_set *master){
	if (FD_ISSET(j, master)){
		if (j != sockfd && j != i) {
			if (send(j, recv_buf, nbytes_recvd, 0) == -1){
				perror("send");
			}
		}
	}
}
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
void saveTo_dataBase(char *recv_buf)
{
	int k;
	char user_name[100] = " ";
	char message[BUFSIZE] = " ";

   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   //Split the recieve buff to user name and message
    for (k=0;k<strlen(recv_buf);k++){
		if (recv_buf[k] == ':'){
			strncpy(user_name,recv_buf,k);
			strncpy(message,&recv_buf[k+1],strlen(recv_buf)-k);
			break;
		}
	}

   /* Open database */
   rc = sqlite3_open("chat.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }/*else{
      fprintf(stderr, "Opened database successfully\n");
   } */

   /* Create SQL statement */
   // sql = "INSERT INTO CHATSESSION (NAME,MESSAGE)" \
   //       "VALUES ('%s', '%s');",user_name,message;
    sprintf(sql,"INSERT INTO CHATSESSION (NAME,MESSAGE) VALUES ('%s', '%s');",user_name,message);

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }/*else{
      fprintf(stdout, "Records created successfully\n");
   }*/
   sqlite3_close(db);
}
/*Added received time to the function, then each time it reiceive a message,
, it will send to all other clients, and also that message to database*/
void send_recv(int i, fd_set *master, int sockfd, int fdmax)
{
	int nbytes_recvd, j;
	char recv_buf[BUFSIZE] = " ";
	// time_t rawtime;
	// char recv_time[26];
	// struct tm * timeinfo;

	if ((nbytes_recvd = recv(i, recv_buf, BUFSIZE, 0)) <= 0){
		if (nbytes_recvd == 0){
			printf("socket %d hung up\n", i);
		} else {
			perror("recv");
		}
		close(i);
		FD_CLR(i, master);
	//set receive message time
	// time(&rawtime);
    //   	timeinfo = localtime(&rawtime); 
	// strftime(recv_time, 26, "%Y:%m:%d %H:%M:%S", timeinfo);
	} else {
		// recv_buf = ' ';
		printf("%s\n", recv_buf);
		saveTo_dataBase(&recv_buf);
		for(j = 0; j <= fdmax; j++){
			send_to_all(j, i, sockfd, nbytes_recvd, recv_buf, master);
		}
	}
//	printf("%s at %s",recv_buf,recv_time);
//	printf("%s",recv_time);
	
}
// void saveTo_dataBase(char recv_time[], char recv_buf[])
// {
// 	FILE *pFile;
// 	pFile = fopen("database.txt", "a");

// 	if (pFile != NULL){
// 	  fprintf(pFile, "%s:%s\n",recv_time,recv_buf);
// 	  fclose(pFile);
// 	}
// 	else
// 	{
// 	  printf("Could not open the file. \n");
// 	}

int main() {
	//fd stands for file description
		fd_set master; // declare master file descriptors
		fd_set read_fds; //// declare read socket descriptors
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
	//Add a descriptor sockfd to an fd_set (master)
		FD_SET(sockfd, &master);

		fdmax = sockfd;
		while(1){
			read_fds = master ;
			// wait for an activity on one of the sockets, timeout is NULL, so wait indefinitely
				if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1){
					perror("select");
					exit(4);
				}

				for (i = 0; i <= fdmax; i++){
					if (FD_ISSET(i, &read_fds)){
						//If something happened on the master socket, then its an incoming connection
							if (i == sockfd)
								connection_accept(&master, &fdmax, sockfd, &client_addr);
						//else its some IO operation on some other socket
							else
								send_recv(i, &master, sockfd, fdmax);
					}
				}
		}
	return 0;
}