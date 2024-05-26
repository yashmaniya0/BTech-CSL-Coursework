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

        // char tableName[256] = "salesman";
        char query[256];
int createTableStatus ;
        // A
        snprintf(query,256,"SELECT * from product where month = (SELECT min(month) from product)");
        snprintf(query,256,"SELECT product.*,pantry.num_items FROM product,pantry WHERE month = (SELECT min(month) from pantry) AND product.pid=pantry.pid");
        createTableStatus = mysql_query(conn, query);

        //B
        snprintf(query,256,"SELECT * from product where month = 8");
        snprintf(query,256,"SELECT product.*,pantry.num_items FROM product,pantry WHERE month = 8 AND product.pid=pantry.pid");
        createTableStatus = mysql_query(conn, query);

        //C
        snprintf(query,256,"SELECT * from product where month = 9 and num_items=0");
        snprintf(query,256,"SELECT product.*,pantry.num_items FROM product,pantry WHERE month = 9 AND pantry.num_items=0");
        createTableStatus = mysql_query(conn, query);

        //D
        snprintf(query,256,"SELECT * from product where month = 9 and num_items>0");
        // snprintf(query,256,"SELECT * from product where month = (SELECT min(month) from product)");
        snprintf(query,256,"SELECT product.*,pantry.num_items FROM product,pantry WHERE month = 9 AND pantry.num_items>0");
        createTableStatus = mysql_query(conn, query);

        //E
        snprintf(query,256,"SELECT * from product where month = 9 and num_items<=10");
        snprintf(query,256,"SELECT product.*,pantry.num_items FROM product,pantry WHERE month = 9 AND pantry.num_items<=10");
        createTableStatus = mysql_query(conn, query);
        

        //F
        snprintf(query,256,"SELECT * from product where month >= (SELECT max(month) from product)-3");
        snprintf(query,256,"SELECT product.*,pantry.num_items FROM product,pantry WHERE month >= (SELECT max(month) from product)-3)");
        createTableStatus = mysql_query(conn, query);



        // snprintf(query,256,"SELECT * from product where month = (SELECT min(month) from product)");


        // int createTableStatus = mysql_query(conn, query);
        // snprintf(query,256,"ALTER TABLE salesman ADD date_of_release varchar(255)");
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