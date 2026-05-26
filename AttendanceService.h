#pragma once
#include <mysql.h>
#include <string>

class AttendanceService 
{
private:
    DatabaseManager& db;

public:
	AttendanceService(DatabaseManager& dbRef);
    void updateattendance(int roll, int subject , std::string date , std::string status);
    void markAttendance(int roll, int subject, std::string date, std::string status);
    void viewattendance();
};
