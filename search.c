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
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
int main(){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
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
    //sprintf(sql,"INSERT INTO CHATSESSION (NAME,MESSAGE) VALUES ('%s', '%s');",user_name,message);
    sprintf(sql,"SELECT * FROM CHATSESSION");
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