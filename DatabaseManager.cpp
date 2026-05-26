#include "DatabaseManager.h"
#include <iostream>
#include <fstream>    // Add this line right here!
#include <string>


    DatabaseManager::DatabaseManager() 
{
    conn = mysql_init(NULL);
    //initializes Mysql connection object as NULL
}
    bool DatabaseManager::connect() {
    // 1. Prepare variables to hold the credentials
    std::string host, user, pass, dbName;
    
    // 2. Open the configuration file
    std::ifstream configFile("db_config.txt");
    
    // 3. Safety Check: Did the file open correctly?
    if (!configFile.is_open()) {
        std::cerr << "CRITICAL ERROR: Could not find db_config.txt!" << std::endl;
        std::cerr << "Ensure the file exists in the same folder as the executable." << std::endl;
        return false; 
    }

    // 4. Read the credentials line by line
    std::getline(configFile, host);
    std::getline(configFile, user);
    std::getline(configFile, pass);
    std::getline(configFile, dbName);
    
    configFile.close();

    // 5. Initialize MySQL
    MYSQL* conn = mysql_init(0);
    if (!conn) {
        std::cerr << "ERROR: MySQL initialization failed." << std::endl;
        return false;
    }

    // 6. Connect using the variables we just read from the file
    // Notice the use of .c_str() to convert std::string to const char* required by MySQL
    conn = mysql_real_connect(conn, host.c_str(), user.c_str(), pass.c_str(), dbName.c_str(), 3306, NULL, 0);
    
    if (conn) {
        std::cout << "Successfully connected to the database securely!" << std::endl;
        return true;
    } else {
        std::cerr << "Database Connection Failed: " << mysql_error(conn) << std::endl;
        return false;
    }
}


bool DatabaseManager::execute(const std::string& query) {
    if (conn == NULL) {
        std::cout << "No database connection\n";
        return false;
    }

    if (mysql_query(conn, query.c_str())) {
        std::cout << "Query Failed: " << mysql_error(conn) << std::endl;
        return false;
    }

    return true;
}


MYSQL_RES* DatabaseManager::fetch(const std::string& query) {
    if (conn == NULL) {
        std::cout << "No database connection\n";
        return NULL;
    }

    if (mysql_query(conn, query.c_str())) {
        std::cout << "Query Failed: " << mysql_error(conn) << std::endl;
        return NULL;
    }

    return mysql_store_result(conn);
}


// connecting mysql with c++ with initializing mysql_init() and establising connection using mysql_real_connect(passing myql object , details)
