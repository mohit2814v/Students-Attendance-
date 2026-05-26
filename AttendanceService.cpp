#include "DatabaseManager.h"
#include "AttendanceService.h"
#include<mysql.h>
#include <sstream>
#include<iostream>
AttendanceService::AttendanceService(DatabaseManager& dbRef) : db(dbRef) {}
void AttendanceService::updateattendance(int roll,int subject,std::string date, std::string status )
{
	 std::stringstream query;

    query << "UPDATE attendance SET status = '"
      << status
      << "' WHERE roll_no = "
      << roll
      << " AND subject_id = "
      << subject
      << " AND date = '"
      << date
      << "'";  

    db.execute(query.str());
}



void AttendanceService::markAttendance(int roll, int subject, std::string date, std::string status) {

    std::stringstream checkQuery;

    checkQuery << "SELECT * FROM attendance WHERE roll_no = "
               << roll << " AND subject_id = "
               << subject << " AND date = '"
               << date << "'";

    MYSQL_RES* res = db.fetch(checkQuery.str());

    if (res && mysql_num_rows(res) > 0) {
        std::cout << "\n Attendance already marked:\n";

        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            std::cout << "Roll: " << row[1]
                      << " | Subject: " << row[2]
                      << " | Date: " << row[3]
                      << " | Status: " << row[4] << std::endl;
        }

        mysql_free_result(res);
        return;
    }

    mysql_free_result(res);

    // Insert new record
    std::stringstream insertQuery;

    insertQuery << "INSERT INTO attendance (roll_no, subject_id, date, status) VALUES ("
                << roll << ", "
                << subject << ", '"
                << date << "', '"
                << status << "')";

    db.execute(insertQuery.str());

    std::cout << "---Attendance marked successfully---\n";
}


#include <iomanip>


void AttendanceService::viewattendance() {

    std::string query =
        "SELECT a.date, s.roll_no, s.name, sub.subject_id, a.status "
        "FROM attendance a "
        "JOIN studentdata s ON a.roll_no = s.roll_no "
        "JOIN subjectdata sub ON a.subject_id = sub.subject_id "
        "ORDER BY a.date, a.roll_no";

    MYSQL_RES* res = db.fetch(query);

    if (res == NULL) {
        std::cout << "\n Failed to fetch attendance\n";
        return;
    }

    if (mysql_num_rows(res) == 0) {
        std::cout << "\n No attendance records found\n";
        mysql_free_result(res);
        return;
    }

    MYSQL_ROW row;
    std::string currentDate = "";

    std::cout << "\n========== ATTENDANCE ==========\n";

    while ((row = mysql_fetch_row(res))) {

        std::string date = row[0];

        // ?? New Date Section
        if (date != currentDate) {
            currentDate = date;

            std::cout << "\n\nDate: " << currentDate << "\n";
            std::cout << "----------------------------------------------------------\n";

            std::cout << std::left
                      << std::setw(12) << "Roll No"
                      << std::setw(20) << "Name"
                      << std::setw(15) << "Subject"
                      << std::setw(10) << "Status"
                      << "\n";
        }

        std::cout << std::left
                  << std::setw(12) << row[1]   // roll_no
                  << std::setw(20) << row[2]   // name
                  << std::setw(15) << row[3]   // subject
                  << std::setw(10) << row[4]   // status
                  << "\n";
    }

    std::cout << "\n================================\n";

    mysql_free_result(res);
}
