#include "StudentService.h"
#include <sstream>
#include<iostream>
StudentService::StudentService(DatabaseManager& dbRef) : db(dbRef) {}
void StudentService::addStudent(int roll, std::string name, int age, std::string college, std::string dept) {

    std::stringstream query;

    query << "INSERT INTO studentdata (roll_no, name, age, college, department) VALUES ("
          << roll << ", '"
          << name << "', "
          << age << ", '"
          << college << "', '"
          << dept << "')";

    db.execute(query.str());
}

#include "StudentService.h"
#include <iostream>
#include <iomanip>   // for formatting

void StudentService::showStudents()
{

    std::string query = "SELECT * FROM studentdata";

    MYSQL_RES* res = db.fetch(query);

    if (res == NULL) {
        std::cout << "\n Failed to fetch data\n";
        return;
    }

    int num_rows = mysql_num_rows(res);

    if (num_rows == 0) {
        std::cout << "\n No student records found\n";
        mysql_free_result(res);
        return;
    }

    std::cout << "\n========== STUDENT DATA ==========\n\n";

    // Header
    std::cout << std::left
              << std::setw(12) << "Roll No"
              << std::setw(20) << "Name"
              << std::setw(8)  << "Age"
              << std::setw(20) << "College"
              << std::setw(15) << "Department"
              << "\n";

    std::cout << "------------------------------------------------------------------------\n";

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res))) {
        std::cout << std::left
                  << std::setw(12) << row[0]
                  << std::setw(20) << row[1]
                  << std::setw(8)  << row[2]
                  << std::setw(20) << row[3]
                  << std::setw(15) << row[4]
                  << "\n";
    }

    std::cout << "\n=======================================================================\n";

    mysql_free_result(res);
}






#include<limits>
void StudentService::updateStudent(int roll, std::string name, int age, std::string college, std::string dept) {

    //  Check if student exists
    std::stringstream checkQuery;
    checkQuery << "SELECT * FROM studentdata WHERE roll_no = " << roll;

    MYSQL_RES* res = db.fetch(checkQuery.str());

    if (res && mysql_num_rows(res) == 0) {
        std::cout << "\n Student not found\n";
        mysql_free_result(res);
        return;
    }

    mysql_free_result(res);

    //  Update query
    std::stringstream updateQuery;

    updateQuery << "UPDATE studentdata SET "
                << "name = '" << name << "', "
                << "age = " << age << ", "
                << "college = '" << college << "', "
                << "department = '" << dept << "' "
                << "WHERE roll_no = " << roll;

    if (db.execute(updateQuery.str())) {
        std::cout << "\n Student updated successfully\n";
    } else {
        std::cout << "\n Update failed\n";
    }
}


