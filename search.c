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
#define ANSI_COLOR_RED     "\x1b[7;91m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
char *zErrMsg = 0;
sqlite3 *db;
int rc;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
void executeDb(char *cmd){
	rc = sqlite3_exec(db, cmd, callback, 0, &zErrMsg);
   	if( rc != SQLITE_OK ){
     	fprintf(stderr, "SQL error: %s\n", zErrMsg);
    	sqlite3_free(zErrMsg);
  	}
}
void searchByName(char *name){
	printf("%s",ANSI_COLOR_YELLOW);
	char cmd[256] = "SELECT * FROM CHATSESSION WHERE NAME like '\%";
    strcat(cmd,name);
    strcat(cmd,"\%'");
    executeDb(&cmd);
    printf("%s",ANSI_COLOR_RESET);
    
}
void searchByMsg(char *msg){
	printf("%s",ANSI_COLOR_YELLOW);
	char cmd[256] = "SELECT * FROM CHATSESSION WHERE MESSAGE like '\%";
    strcat(cmd,msg);
    strcat(cmd,"\%'");
    executeDb(&cmd);
    printf("%s",ANSI_COLOR_RESET);
}
void searchByNameAndMsg(char *name, char *msg){
	printf("%s",ANSI_COLOR_YELLOW);
	char cmd[256] = "SELECT * FROM CHATSESSION WHERE NAME like '\%";
    strcat(cmd,name);
    strcat(cmd,"\%' AND MESSAGE like '\%");
    strcat(cmd,msg);
    strcat(cmd,"\%'");
    executeDb(&cmd);
    printf("%s",ANSI_COLOR_RESET);
}

void openDatabase(){
	
	rc = sqlite3_open("chat.db", &db);
	if( rc ){
    	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    	exit(0);
	}
}
int main(){
	openDatabase();
	char choice;
	int checkLoop;
	while(1){
		checkLoop = 1;
		char name[128],message[512];
		printf("\n%sSEARCH IN DATABASE\n",ANSI_COLOR_CYAN);
		printf("  1. Search by name\n");
		printf("  2. Search by message content\n");
		printf("  3. Search by both name and message content\n");
		printf("  4. Exit\n");
		while (checkLoop==1){
			printf("Enter your choice: %s",ANSI_COLOR_RESET);
			scanf("%s",&choice);
			getchar();
			switch (choice) {
				case '1':	
					printf("Enter name: ");
					scanf("%s",name);
					searchByName(&name);
					checkLoop=0;
					break;
				case '2':	
					printf("Enter message: ");
					scanf("%s",message);
					searchByMsg(&message);
					checkLoop=0;
					break;
				case '3':	
					printf("Enter name: ");
					scanf("%s",name);
					printf("Enter message: ");
					scanf("%s",message);
					searchByNameAndMsg(&name,&message);
					checkLoop=0;					
					break;
				case '4':
					exit(0);
					break;
				default:
					printf("%sPlease enter a valid choice!%s\n",ANSI_COLOR_RED,ANSI_COLOR_RESET);
			}
	}
	}
	sqlite3_close(db);
}