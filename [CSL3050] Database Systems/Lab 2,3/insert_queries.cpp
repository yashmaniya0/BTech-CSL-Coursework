//Command to Compile: g++ demo.cpp -o demo.exe -lmysql

#include <iostream>
#include <windows.h>
#include <mysql.h>
// #include <float.h>

using namespace std;

MYSQL *conn;
MYSQL_RES res;
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
    if (mysql_real_connect(conn, "localhost", "yashM", "admin","lab1", 3306, NULL, 0)) {

        cout<<"Connected Successfully!"<<endl;

        char tableName[256] = "Staff";
        char query[256];

        int createTableStatus;

        snprintf(query, 256, "INSERT INTO `publisher`(`publisher_id`, `book_name`,`Year`) VALUES ('1','Harry Potter','2003')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `publisher`(`publisher_id`, `book_name`,`Year`) VALUES ('2','The Jungle Book','2008')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `publisher`(`publisher_id`, `book_name`,`Year`) VALUES ('3','Verity','2013')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `publisher`(`publisher_id`, `book_name`,`Year`) VALUES ('4','Lagaan','2001')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `publisher`(`publisher_id`, `book_name`,`Year`) VALUES ('5','Flying Kites','2015')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `publisher`(`publisher_id`, `book_name`,`Year`) VALUES ('6','Samson and Hues','2018')");   
        createTableStatus = mysql_query(conn, query);

        // -----------------------------------------------------------------------------------------------------------------------------
        
        snprintf(query, 256, "INSERT INTO `reader`(`reader_id`, `email`, `name`, `address`) VALUES ('1','abc@gmail.com','abc', '45 - Huston appt., NY - 105436')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `reader`(`reader_id`, `email`, `name`, `address`) VALUES ('2','aaa@gmail.com','aaa', '23 - James appt., NY - 165402')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `reader`(`reader_id`, `email`, `name`, `address`) VALUES ('3','ccc@gmail.com','ccc', '158 - Pittsberg soc., NY - 189765')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `reader`(`reader_id`, `email`, `name`, `address`) VALUES ('4','xyz@gmail.com','xyz', '244 - Riverden soc., NY - 845412')");        
        createTableStatus = mysql_query(conn, query);

        // -----------------------------------------------------------------------------------------------------------------------------
        
        snprintf(query, 256, "INSERT INTO `monitors`(`reader_id`, `librarian_id`) VALUES ('10','11')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `monitors`(`reader_id`, `librarian_id`) VALUES ('20','21')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `monitors`(`reader_id`, `librarian_id`) VALUES ('30','31')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `monitors`(`reader_id`, `librarian_id`) VALUES ('40','41')");        
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