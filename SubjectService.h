#pragma once
#include "DatabaseManager.h"
#include <string>

class SubjectService {
private:
    DatabaseManager& db;

public:
    SubjectService(DatabaseManager& dbRef);
	void addsubject(int subject_id, std::string subject_name);
    
};
