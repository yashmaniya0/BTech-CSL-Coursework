//Command to Compile: g++ demo.cpp -o demo.exe -lmysql

#include <bits/stdc++.h>
#include <windows.h>
#include <chrono>
#include <mysql.h>
#include <ctime>
// #include <float.h>

using namespace std;

MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;


int main()
{
    conn = mysql_init(NULL);

    if (conn == NULL) {
        cout<<"Error: "<<mysql_error(conn)<<endl;
        exit(1);
    }

    vector<long long> va;
    vector<long long> vb;

    // mysql_real_connect(Connection Instance, Username, Password,
    // Database, Port, Unix Socket, Client Flag)
    if (mysql_real_connect(conn, "localhost", "yashM", "admin","lab3 norm", 3306, NULL, 0)) {

        cout<<"Connected Successfully!"<<endl;

        int createTableStatus;
        char query[256];

        auto start = std::chrono::high_resolution_clock::now();

        snprintf(query, 256, "SELECT product.*, pantry.num_items FROM product,pantry WHERE month = 6 AND product.pid = pantry.pid;");

        createTableStatus = mysql_query(conn, query);

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
        cout<<endl;

        // time(&end);
        // long double time_taken = (long double)(end-start); 

        auto elapsed = std::chrono::high_resolution_clock::now() - start;

        long long time_taken = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

        cout<<"Time taken by query 1 in normalised tables : "<<time_taken<<" microseconds"<<endl;



        start = std::chrono::high_resolution_clock::now();

        elapsed = std::chrono::high_resolution_clock::now() - start;

        time_taken = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

        cout<<"Time taken by query 1 in normalised tables : "<<time_taken<<" microseconds"<<endl;




        if (createTableStatus != 0) {
            cout<<"Error while creating table: "<<mysql_error(conn)<<endl;
        }

    }
    else {
        cout<<"Error while connecting!"<<endl;
    }

    
    return 0;
}