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

        char tableName[256] = "Staff";
        char query[256];

        // Authorization
        snprintf(query, 256, "INSERT INTO `authorization`(`user_id`, `password`,`librarian_id`) VALUES ('user_1','abcd0','1')");        
        int createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `authorization`(`user_id`, `password`,`librarian_id`) VALUES ('user_2','abcd1','2')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `authorization`(`user_id`, `password`,`librarian_id`) VALUES ('user_3','abcd2','3')");        
        createTableStatus = mysql_query(conn, query);


        // Books
        snprintf(query,256,"INSERT INTO `books`(`ISBN`, `Author_name`, `title`, `price`, `Reader_id`, `publisher_id`, `librarian_id`) VALUES ('123456789','JK Rowling','Harry Potter','400','1','1','1')");
        createTableStatus = mysql_query(conn,query);

        snprintf(query,256,"INSERT INTO `books`(`ISBN`, `Author_name`, `title`, `price`, `Reader_id`, `publisher_id`, `librarian_id`) VALUES ('1234567890','Yash Maniya','Flying Kites','500','1','2','1')");
        createTableStatus = mysql_query(conn,query);

        snprintf(query,256,"INSERT INTO `books`(`ISBN`, `Author_name`, `title`, `price`, `Reader_id`, `publisher_id`, `librarian_id`) VALUES ('1234567899','Yash Maniya','The Jungle Book','400','2','3','2')");
        createTableStatus = mysql_query(conn,query);

        snprintf(query,256,"INSERT INTO `books`(`ISBN`, `Author_name`, `title`, `price`, `Reader_id`, `publisher_id`, `librarian_id`) VALUES ('123456788','Tatvam','Verity','599','3','4','3')");
        createTableStatus = mysql_query(conn,query);

        snprintf(query,256,"INSERT INTO `books`(`ISBN`, `Author_name`, `title`, `price`, `Reader_id`, `publisher_id`, `librarian_id`) VALUES ('1234567897','Ruthvik K.','Lagaan','399','2','5','3')");
        createTableStatus = mysql_query(conn,query);

        snprintf(query,256,"INSERT INTO `books`(`ISBN`, `Author_name`, `title`, `price`, `Reader_id`, `publisher_id`, `librarian_id`) VALUES ('1234567896','Ruthvik K.','Samson and Hues','349','4','6','3')");
        createTableStatus = mysql_query(conn,query);

        // Data Entry

        snprintf(query,256,"INSERT INTO `data entry`(`Entry_no.`, `ISBN`, `user_id`, `issue_date`, `return_date`, `librarian_id`) VALUES ('1','1234567896','1','12th august','-','1')");
        createTableStatus = mysql_query(conn,query);

        snprintf(query,256,"INSERT INTO `data entry`(`Entry_no.`, `ISBN`, `user_id`, `issue_date`, `return_date`, `librarian_id`) VALUES ('2','1234567897','1','14th august','-','1')");
        createTableStatus = mysql_query(conn,query);

        snprintf(query,256,"INSERT INTO `data entry`(`Entry_no.`, `ISBN`, `user_id`, `issue_date`, `return_date`, `librarian_id`) VALUES ('3','1234567897','1','-','21st august','2')");
        createTableStatus = mysql_query(conn,query);

        snprintf(query,256,"INSERT INTO `data entry`(`Entry_no.`, `ISBN`, `user_id`, `issue_date`, `return_date`, `librarian_id`) VALUES ('3','1234567892','4','15th august','-','1')");
        createTableStatus = mysql_query(conn,query);

        // Librarian
        snprintf(query,256,"INSERT INTO `librarian`(`Librarian_id`, `name`) VALUES ('1','khushi majmudar')");
        createTableStatus = mysql_query(conn,query);

        snprintf(query,256,"INSERT INTO `librarian`(`Librarian_id`, `name`) VALUES ('2','yukta soni')");
        createTableStatus = mysql_query(conn,query);

        snprintf(query,256,"INSERT INTO `librarian`(`Librarian_id`, `name`) VALUES ('3','ramu kaderi')");
        createTableStatus = mysql_query(conn,query);

        snprintf(query,256,"INSERT INTO `librarian`(`Librarian_id`, `name`) VALUES ('4','manu maniya')");
        createTableStatus = mysql_query(conn,query);

        // Pubisher

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

        // Reader-----------------------------------------------------------------------------------------------------------------------------
        
        snprintf(query, 256, "INSERT INTO `reader`(`reader_id`, `email`, `name`, `address`) VALUES ('1','abc@gmail.com','abc', '45 - Huston appt., NY - 105436')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `reader`(`reader_id`, `email`, `name`, `address`) VALUES ('2','aaa@gmail.com','aaa', '23 - James appt., NY - 165402')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `reader`(`reader_id`, `email`, `name`, `address`) VALUES ('3','ccc@gmail.com','ccc', '158 - Pittsberg soc., NY - 189765')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `reader`(`reader_id`, `email`, `name`, `address`) VALUES ('4','xyz@gmail.com','xyz', '244 - Riverden soc., NY - 845412')");        
        createTableStatus = mysql_query(conn, query);

        // Monitors-----------------------------------------------------------------------------------------------------------------------------
        
        snprintf(query, 256, "INSERT INTO `monitors`(`reader_id`, `librarian_id`) VALUES ('1','1')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `monitors`(`reader_id`, `librarian_id`) VALUES ('2','2')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `monitors`(`reader_id`, `librarian_id`) VALUES ('3','3')");        
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256, "INSERT INTO `monitors`(`reader_id`, `librarian_id`) VALUES ('4','3')");        
        createTableStatus = mysql_query(conn, query);

        // phone no.

        snprintf(query, 256,"INSERT INTO `phone_no.`(`Reader_ID`, `Phone_No`) VALUES ('1','9988776655')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256,"INSERT INTO `phone_no.`(`Reader_ID`, `Phone_No`) VALUES ('1','9988776654')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256,"INSERT INTO `phone_no.`(`Reader_ID`, `Phone_No`) VALUES ('2','9988776255')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256,"INSERT INTO `phone_no.`(`Reader_ID`, `Phone_No`) VALUES ('3','9988771655')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256,"INSERT INTO `phone_no.`(`Reader_ID`, `Phone_No`) VALUES ('3','9988176655')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query, 256,"INSERT INTO `phone_no.`(`Reader_ID`, `Phone_No`) VALUES ('3','9188776655')");
        createTableStatus = mysql_query(conn, query);

        //publisher_name
        snprintf(query,256,"INSERT INTO `publisher_name`(`Publisher_id`, `Publisher_name`) VALUES ('1','ram shyam publication')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query,256,"INSERT INTO `publisher_name`(`Publisher_id`, `Publisher_name`) VALUES ('2','ramesh publication')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query,256,"INSERT INTO `publisher_name`(`Publisher_id`, `Publisher_name`) VALUES ('3','shyamesh publication')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query,256,"INSERT INTO `publisher_name`(`Publisher_id`, `Publisher_name`) VALUES ('4','ruthvik publication')");
        createTableStatus = mysql_query(conn, query);

        //genre

        snprintf(query,256,"INSERT INTO `genre`(`ISBN`, `Genre`) VALUES ('1','horror')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query,256,"INSERT INTO `genre`(`ISBN`, `Genre`) VALUES ('1','kids')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query,256,"INSERT INTO `genre`(`ISBN`, `Genre`) VALUES ('2','thriller')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query,256,"INSERT INTO `genre`(`ISBN`, `Genre`) VALUES ('3','romance')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query,256,"INSERT INTO `genre`(`ISBN`, `Genre`) VALUES ('3','horror')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query,256,"INSERT INTO `genre`(`ISBN`, `Genre`) VALUES ('4','kids')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query,256,"INSERT INTO `genre`(`ISBN`, `Genre`) VALUES ('5','romance')");
        createTableStatus = mysql_query(conn, query);

        snprintf(query,256,"INSERT INTO `genre`(`ISBN`, `Genre`) VALUES ('6','fantasy')");
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