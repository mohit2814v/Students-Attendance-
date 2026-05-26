#pragma once
#include "DatabaseManager.h"
#include <string>

class StudentService 
{
private:
    DatabaseManager& db;

public:
	StudentService(DatabaseManager& dbRef);
    void addStudent(int roll, std::string name, int age, std::string college, std::string dept);
    void updateStudent(int roll, std::string name, int age, std::string college, std::string dept);
    void showStudents();
    
};
