//Command to Compile: g++ demo.cpp -o demo.exe -lmysql

#include <iostream>
#include <windows.h>
#include <mysql.h>
// #include <float.h>

using namespace std;

MYSQL *conn;
// MYSQL *conn;
 MYSQL_RES *res; /* holds the result set */
    MYSQL_ROW row;


int main()
{

    conn = mysql_init(NULL);

    if (conn == NULL) {
        cout<<"Error: "<<mysql_error(conn)<<endl;
        exit(1);
    }

    // mysql_real_connect(Connection Instance, Username, Password,
    // Database, Port, Unix Socket, Client Flag)
    if (mysql_real_connect(conn, "localhost", "dbms_demo", "dbms_demo1#","lab2_q3", 3306, NULL, 0)) {

        cout<<"Connected Successfully!"<<endl;

        char tableName[256] = "salesman";
        char query[256];

        snprintf(query, 256, "CREATE TABLE `%s` (`salesman_id` int NOT NULL PRIMARY KEY, `name` varchar(255), `address_city` varchar(255), `coverage_city` varchar(255),`commission` int);",tableName);
        
        int createTableStatus = mysql_query(conn, query);
        
        if (createTableStatus != 0) {
            cout<<"Error while creating table: "<<mysql_error(conn)<<endl;
        }



    } 
    else {
        cout<<"Error while connecting!"<<endl;
    }

    
    return 0;
}