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
    if (mysql_real_connect(conn, "localhost", "yashM", "admin","lab3", 3306, NULL, 0)) {

        cout<<"Connected Successfully!"<<endl;


        char tableName[256] = "product";
        char query[256];
        snprintf(query, 256, "CREATE TABLE `%s` (`pid` int NOT NULL, `name` varchar(255), `price` float, `brand` varchar(255), `category` varchar(255), `num_items` int, `date` int, `month` int, PRIMARY KEY (`pid`, `date`, `month`));", tableName); 
        int createTableStatus = mysql_query(conn, query);
        if (createTableStatus != 0) {
            cout<<"Error while creating table: "<<mysql_error(conn)<<endl;
        }




        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('1','Milk','Amul','25','7','Dairy Products', '2', '6')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('2','Eggs','NA','10','25','Eggs', '3', '6')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('3','Hide and Seek','Parle','10','16','Cookies', '1', '6')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('4','Carrots','NA','20','3','Vegetables', '12', '6')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('5','Oranges','NA','35','4','Fruits', '18', '6')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('6','Bhujiya','Balaji','60','8','Snacks', '14', '6')");   
        createTableStatus = mysql_query(conn, query);



        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('1','Milk','Amul','25','23','Dairy Products', '22', '7')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('2','Eggs','NA','10','10','Eggs', '13', '7')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('3','Hide and Seek','Parle','10','21','Cookies', '12', '7')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('4','Carrots','NA','20','6','Vegetables', '3', '7')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('5','Oranges','NA','35','2','Fruits', '8', '7')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('6','Bhujiya','Balaji','60','10','Snacks', '24', '7')");   
        createTableStatus = mysql_query(conn, query);



        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('1','Milk','Amul','25','12','Dairy Products', '29', '8')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('2','Eggs','NA','10','21','Eggs', '13', '8')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('3','Hide and Seek','Parle','10','10','Cookies', '11', '8')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('4','Carrots','NA','20','9','Vegetables', '2', '8')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('5','Oranges','NA','35','12','Fruits', '28', '8')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('6','Bhujiya','Balaji','60','4','Snacks', '4', '8')");   
        createTableStatus = mysql_query(conn, query);



        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('1','Milk','Amul','25','10','Dairy Products', '21', '9')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('2','Eggs','NA','10','35','Eggs', '30', '9')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('3','Hide and Seek','Parle','10','50','Cookies', '15', '9')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('4','Carrots','NA','20','12','Vegetables', '7', '9')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('5','Oranges','NA','35','14','Fruits', '4', '9')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('6','Bhujiya','Balaji','60','20','Snacks', '14', '9')");   
        createTableStatus = mysql_query(conn, query);



        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('1','Milk','Amul','25','1','Dairy Products', '22', '10')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('2','Eggs','NA','10','3','Eggs', '1', '10')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('3','Hide and Seek','Parle','10','5','Cookies', '19', '10')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('4','Carrots','NA','20','3','Vegetables', '15', '10')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('5','Oranges','NA','35','4','Fruits', '28', '10')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `product`(`pid`, `name`,`brand`, `price`, `num_items`,`category`,`date`,`month`) VALUES ('6','Bhujiya','Balaji','60','6','Snacks', '24', '10')");   
        createTableStatus = mysql_query(conn, query);

        // // -----------------------------------------------------------------------------------------------------------------------------
        
        // snprintf(query, 256, "INSERT INTO `month`(`month`, `total_amount`, `total_items`) VALUES ('1','0','0')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `month`(`month`, `total_amount`, `total_items`) VALUES ('2','0','0')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `month`(`month`, `total_amount`, `total_items`) VALUES ('3','0','0')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `month`(`month`, `total_amount`, `total_items`) VALUES ('4','0','0')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `month`(`month`, `total_amount`, `total_items`) VALUES ('5','0','0')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `month`(`month`, `total_amount`, `total_items`) VALUES ('6','0','0')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `month`(`month`, `total_amount`, `total_items`) VALUES ('7','0','0')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `month`(`month`, `total_amount`, `total_items`) VALUES ('8','0','0')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `month`(`month`, `total_amount`, `total_items`) VALUES ('9','0','0')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `month`(`month`, `total_amount`, `total_items`) VALUES ('10','0','0')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `month`(`month`, `total_amount`, `total_items`) VALUES ('11','0','0')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `month`(`month`, `total_amount`, `total_items`) VALUES ('12','0','0')");        
        // createTableStatus = mysql_query(conn, query);

        // // -----------------------------------------------------------------------------------------------------------------------------
        
        // snprintf(query, 256, "INSERT INTO `pantry`(`month`, `pid`, `total_items`) VALUES ('1','1','3')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `pantry`(`month`, `pid`, `total_items`) VALUES ('1','2','4')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `pantry`(`month`, `pid`, `total_items`) VALUES ('1','4','1')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `pantry`(`month`, `pid`, `total_items`) VALUES ('2','3','2')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `pantry`(`month`, `pid`, `total_items`) VALUES ('4','5','4')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `pantry`(`month`, `pid`, `total_items`) VALUES ('4','2','1')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `pantry`(`month`, `pid`, `total_items`) VALUES ('6','1','6')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `pantry`(`month`, `pid`, `total_items`) VALUES ('6','2','4')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `pantry`(`month`, `pid`, `total_items`) VALUES ('6','4','12')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `pantry`(`month`, `pid`, `total_items`) VALUES ('6','6','1')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `pantry`(`month`, `pid`, `total_items`) VALUES ('7','5','7')");        
        // createTableStatus = mysql_query(conn, query);

        // snprintf(query, 256, "INSERT INTO `pantry`(`month`, `pid`, `total_items`) VALUES ('8','3','16')");        
        // createTableStatus = mysql_query(conn, query);


        if (createTableStatus != 0) {
            cout<<"Error while creating table: "<<mysql_error(conn)<<endl;
        }

    } 
    else {
        cout<<"Error while connecting!"<<endl;
    }

    
    return 0;
}