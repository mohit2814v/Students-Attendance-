#pragma once
#include <mysql.h>
#include <string>

class DatabaseManager {
private:
    MYSQL* conn; //connection object 
    // live connection to Mysql server
public:
    DatabaseManager();
    bool connect();
    bool execute(const std::string& query);//Used for insert / update / delete
    //return true or false
    
    MYSQL_RES* fetch(const std::string& query);//for select queries
    
};
