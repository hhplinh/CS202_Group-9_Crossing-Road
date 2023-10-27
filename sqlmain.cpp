#include "sqlmain.hpp"

void a()
{
   std::cerr << "a() called" << std::endl;
}

void loadLibSQL()
{
   HMODULE sqlite3DLL = LoadLibrary("sqlite3.dll");
    if (!sqlite3DLL) {
        // Handle the error
        std::cerr << "Error loading sqlite3.dll" << std::endl;
    }
}

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

// typedef int (*sqlite3_callback)(
//    void*,    /* Data provided in the 4th argument of sqlite3_exec() */
//    int,      /* The number of columns in row */
//    char**,   /* An array of strings representing fields in the row */
//    char**    /* An array of strings representing column names */
// );

// Callback function called: ID = 1
// NAME = Paul
// AGE = 32
// ADDRESS = California
// SALARY = 20000.0


void run() {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      // return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "SELECT * from COMPANY";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);
}