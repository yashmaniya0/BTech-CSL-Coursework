//Command to Compile: g++ demo.cpp -o demo.exe -lmysql

#include <iostream>
#include <windows.h>
#include <mysql.h>
// #include <float.h>

using namespace std;

MYSQL *conn;
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

        char tableName[256] = "t1";
        char query[256];
        int createTableStatus;
        // snprintf(query,256,"ALTER TABLE salesman DROP COLUMN date_of_employment");
        // // cout<<"yee"<<endl;

        // // snprintf(query, 256, "CREATE TABLE `%s` (`salesman_id` int NOT NULL PRIMARY KEY, `name` varchar(255), `address_city` varchar(255), `coverage_city_commission` varchar(255));",tableName);
        snprintf(query, 256, "CREATE TABLE `%s` (`salesman_id` int NOT NULL PRIMARY KEY, `name` varchar(255), `address_city` varchar(255),`date_of_employement` varchar(255),`date_of_release` varchar(255));",tableName);
        
        createTableStatus = mysql_query(conn, query);
        // snprintf(query,256,"ALTER TABLE salesman DROP COLUMN date_of_release");
        // createTableStatus = mysql_query(conn, query);
        char tableName1[256] = "t2";
        snprintf(query,256,"CREATE TABLE `%s` (`salesman_id` int, `coverage_city` varchar(255),`commission` int,PRIMARY KEY(`salesman_id`,`coverage_city`));",tableName1);
        createTableStatus = mysql_query(conn, query);

        snprintf(query,256,"INSERT INTO t1(salesman_id,name,address_city,date_of_employement,date_of_release) SELECT DISTINCT salesman_id,name,address_city,date_of_employement,date_of_release FROM salesman");
        createTableStatus = mysql_query(conn, query);

        snprintf(query,256,"INSERT INTO t2(salesman_id,name,coverage_city,commission) SELECT DISTINCT salesman_id,coverage_city,commission FROM salesman");
        createTableStatus = mysql_query(conn, query);


        if (createTableStatus != 0) {
            cout<<"Error while creating table: "<<mysql_error(conn)<<endl;
        }


        res =  mysql_store_result(conn);

        int num_fields = mysql_num_fields(res);
        // Fetch all rows from the result
        while ((row = mysql_fetch_row(res)))
        {
        // Print all columns
        for(int i = 0; i < num_fields; i++)
        {
            // Make sure row[i] is valid!
            if(row[i] != NULL)
                    cout << row[i] << " ";
            else
                    cout << "NULL" << endl;

            // Also, you can use ternary operator here instead of if-else
            // cout << row[i] ? row[i] : "NULL" << endl;
        }
        cout<<endl;
        }
        
        


    } 
    else {
        cout<<"Error while connecting!"<<endl;
    }

    
    return 0;
}