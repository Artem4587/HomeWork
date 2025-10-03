#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>


using namespace std;

int main() {
    try {
        // Создаем драйвер для подключения к MySQL
        sql::mysql::MySQL_Driver* driver;
        driver = sql::mysql::get_mysql_driver_instance();

        // Устанавливаем соединение с базой данных
        sql::Connection* con;
        con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
        con->setSchema("ContactsDB");

        // Создаем объект для выполнения SQL-запросов
        sql::Statement* stmt;
        stmt = con->createStatement();

        // Выполняем SQL-запрос для создания таблицы ContactGroups
        stmt->execute("CREATE TABLE IF NOT EXISTS ContactGroups ("
            "id INT AUTO_INCREMENT PRIMARY KEY,"
            "group_name VARCHAR(50) NOT NULL)");

        // Выполняем SQL-запрос для создания таблицы Contacts
        stmt->execute("CREATE TABLE IF NOT EXISTS Contacts ("
            "id INT AUTO_INCREMENT PRIMARY KEY,"
            "first_name VARCHAR(50) NOT NULL,"
            "last_name VARCHAR(50) NOT NULL,"
            "phone_number VARCHAR(20) NOT NULL,"
            "email VARCHAR(100),"
            "address VARCHAR(200),"
            "group_id INT,"
            "FOREIGN KEY (group_id) REFERENCES ContactGroups(id))");

        // Выполняем SQL-запрос для вставки данных в таблицу ContactGroups
        stmt->execute("INSERT INTO ContactGroups (group_name) VALUES ('Family')");
        stmt->execute("INSERT INTO ContactGroups (group_name) VALUES ('Friends')");
        stmt->execute("INSERT INTO ContactGroups (group_name) VALUES ('Work')");

        // Выполняем SQL-запрос для вставки данных в таблицу Contacts
        stmt->execute("INSERT INTO Contacts (first_name, last_name, phone_number, email, address, group_id) "
            "VALUES ('Artem', 'Nakanovsky', '+7234567890', 'Artem.nakano@gmail.com', '123 Main St', 1)");
        stmt->execute("INSERT INTO Contacts (first_name, last_name, phone_number, email, address, group_id) "
            "VALUES ('Aleksandr', 'Fadeev', '+1555555555', 'Aleksandr.fad@gmail.com', '456 Oak Ave', 2)");
        stmt->execute("INSERT INTO Contacts (first_name, last_name, phone_number, email, address, group_id) "
            "VALUES ('Alice', 'Johnson', '+1122334455', 'alice.j@example.com', '789 Pine Rd', 3)");

        // Выполняем SQL-запрос для выборки данных из таблицы Contacts
        sql::ResultSet* res;
        res = stmt->executeQuery("SELECT * FROM Contacts");

        // Выводим результаты запроса
        while (res->next()) {
            cout << "ID: " << res->getInt("id") << endl;
            cout << "First Name: " << res->getString("first_name") << endl;
            cout << "Last Name: " << res->getString("last_name") << endl;
            cout << "Phone Number: " << res->getString("phone_number") << endl;
            cout << "Email: " << res->getString("email") << endl;
            cout << "Address: " << res->getString("address") << endl;
            cout << "Group ID: " << res->getInt("group_id") << endl;
            cout << "-----------------------------" << endl;
        }

        // Освобождаем ресурсы
        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}