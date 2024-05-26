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
    if (mysql_real_connect(conn, "localhost", "dbms_demo", "dbms_demo1#","lab1", 3306, NULL, 0)) {

        cout<<"Connected Successfully!"<<endl;
        // char query[256];
        // snprintf(query,256,"DROP TABLE Report");
        char tableName[256] = "Librarian";
        char query[256];

        snprintf(query, 256, "CREATE TABLE `%s` (`Librarian_id` int NOT NULL PRIMARY KEY, `name` varchar(255));",tableName);
        
        int createTableStatus = mysql_query(conn, query);


        char tableName1[256] = "Data Entry";
        snprintf(query, 256, "CREATE TABLE `%s` (`Entry_no.` int NOT NULL PRIMARY KEY, `ISBN` int,`user_id` int,`issue_date` varchar(255),`return_date` varchar(255),`librarian_id` int);",tableName1);
        
        createTableStatus = mysql_query(conn, query);

        char tableName2[256] = "Books";
        snprintf(query, 256, "CREATE TABLE `%s` (`ISBN` int NOT NULL PRIMARY KEY, `Author_name` varchar(255),`title` varchar(255),`price` int,`Reader_id` int,`publisher_id` varchar(255),`librarian_id` int);",tableName2);
        
        createTableStatus = mysql_query(conn, query);

        if (createTableStatus != 0) {
            cout<<"Error while creating table: "<<mysql_error(conn)<<endl;
        }
        
        char tableName3[256] = "Authorization";
        snprintf(query, 256, "CREATE TABLE `%s` (`user_id` varchar(255) NOT NULL PRIMARY KEY, `password` varchar(255),`librarian_id` int);",tableName3);
        
        createTableStatus = mysql_query(conn, query);

        char tableName4[256] = "Publisher";
        snprintf(query, 256, "CREATE TABLE `%s` (`publisher_id` int NOT NULL PRIMARY KEY, `book_name` varchar(255),`Year` int);",tableName4);
        
        createTableStatus = mysql_query(conn, query);
        
        char tableName5[256] = "Reader";
        snprintf(query, 256, "CREATE TABLE `%s` (`reader_id` int NOT NULL PRIMARY KEY, `email` varchar(255),`name` varchar(255),`address` varchar(255));",tableName5);
        
        createTableStatus = mysql_query(conn, query);

        char tableName6[256] = "Monitors";
        snprintf(query, 256, "CREATE TABLE `%s` (`reader_id` int,`librarian_id` int);",tableName6);
        
        createTableStatus = mysql_query(conn, query);

        char tableName8[256] = "phone_no.";
        snprintf(query, 256, "CREATE TABLE `%s` (`Reader_ID` int, `Phone_No` varchar(255));", tableName8); 
        createTableStatus = mysql_query(conn, query);

        char tableName7[256] = "Genre";
        snprintf(query, 256, "CREATE TABLE `%s` (`ISBN` int, `Genre` varchar(255));", tableName7); 
        createTableStatus = mysql_query(conn, query);

        char tableName9[256] = "Publisher_name";
        snprintf(query, 256, "CREATE TABLE `%s` (`Publisher_id` int, `Publisher_name` varchar(255));", tableName9); 
        createTableStatus = mysql_query(conn, query);

        if (createTableStatus != 0) {
            cout<<"Error while creating table: "<<mysql_error(conn)<<endl;
        }



    } 
    else {
        cout<<"Error while connecting!"<<endl;
    }

    
    return 0;
}