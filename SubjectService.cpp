#include "SubjectService.h"
#include <sstream>
#include<iostream>
SubjectService::SubjectService(DatabaseManager& dbRef) : db(dbRef) {}



void SubjectService::addsubject(int subject_id, std::string subject_name) 
{

    //  Check duplicate subject_id
    std::stringstream checkId;
    checkId << "SELECT * FROM subjectdata WHERE Subject_Id = " << subject_id;

    MYSQL_RES* res1 = db.fetch(checkId.str());

    if (res1 && mysql_num_rows(res1) > 0) {
        std::cout << "\n Duplicate Subject ID\n";
        mysql_free_result(res1);
        return;
    }
    mysql_free_result(res1);

    //  Check duplicate subject_name
    std::stringstream checkName;
    checkName << "SELECT * FROM subjectdata WHERE Subjects_Name = '"
              << subject_name << "'";

    MYSQL_RES* res2 = db.fetch(checkName.str());

    if (res2 && mysql_num_rows(res2) > 0) {
        std::cout << "\n Duplicate Subject Name\n";
        mysql_free_result(res2);
        return;
    }
    mysql_free_result(res2);

    //  Insert subject
    std::stringstream insertQuery;

    insertQuery << "INSERT INTO subjectdata (Subject_Id, Subjects_Name) VALUES ("
                << subject_id << ", '"
                << subject_name << "')";

    db.execute(insertQuery.str());

    std::cout << "\n Subject added successfully\n";
}
