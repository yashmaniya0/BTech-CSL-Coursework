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
    if (mysql_real_connect(conn, "localhost", "yashM", "admin","lab3 norm", 3306, NULL, 0)) {

        cout<<"Connected Successfully!"<<endl;


        // string tableName = "product";
        char query[256];
        snprintf(query, 256, "CREATE TABLE `product` (`pid` int NOT NULL, `name` varchar(255), `price` float, `brand` varchar(255), `category` varchar(255), PRIMARY KEY (`pid`));"); 
        int createTableStatus = mysql_query(conn, query);
        if (createTableStatus != 0) {
            cout<<"Error while creating table: "<<mysql_error(conn)<<endl;
        }




        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`, `brand`, `price`, `category`) VALUES ('1','Milk','Amul','25','Dairy Products')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`, `brand`, `price`, `category`) VALUES ('2','Eggs','NA','10','Eggs')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`, `brand`, `price`, `category`) VALUES ('3','Hide and Seek','Parle','10','Cookies')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`, `brand`, `price`, `category`) VALUES ('4','Carrots','NA','20','Vegetables')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`, `brand`, `price`, `category`) VALUES ('5','Oranges','NA','35','Fruits')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`, `brand`, `price`, `category`) VALUES ('6','Bhujiya','Balaji','60','Snacks')");   
        createTableStatus = mysql_query(conn, query);



        // ---------------------------------------------------------------------------------------------------------------------------


        snprintf(query, 256, "CREATE TABLE `pantry` (`pid` int NOT NULL, `num_items` int, `date` int, `month` int, PRIMARY KEY (`pid`, `date`, `month`));"); 
        int createTableStatus = mysql_query(conn, query);
        if (createTableStatus != 0) {
            cout<<"Error while creating table: "<<mysql_error(conn)<<endl;
        }


        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('1', '7', '2', '6')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('2','25', '3', '6')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('3','16', '1', '6')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('4','0', '12', '6')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('5','4', '18', '6')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('6','8', '14', '6')");   
        createTableStatus = mysql_query(conn, query);



        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('1','23', '22', '7')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('2','10', '13', '7')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('3','21','12', '7')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('4','6', '3', '7')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('5','0', '8', '7')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('6','0', '24', '7')");   
        createTableStatus = mysql_query(conn, query);



        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('1','12', '29', '8')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('2','21', '13', '8')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('3','0', '11', '8')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('4','9', '2', '8')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('5','12', '28', '8')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('6','0', '4', '8')");   
        createTableStatus = mysql_query(conn, query);



        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('1','10', '21', '9')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('2','0','30', '9')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('3','50', '15', '9')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('4','12', '7', '9')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('5','14','4', '9')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('6','20','14', '9')");   
        createTableStatus = mysql_query(conn, query);



        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('1','1', '22', '10')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('2','0', '1', '10')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('3','5','19', '10')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('4','3','15', '10')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('5','0', '28', '10')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `pantry`(`pid`, `num_items`,`date`,`month`) VALUES ('6','6', '24', '10')");   
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "FOREIGN KEY (pid) REFERENCES product(pid)");
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