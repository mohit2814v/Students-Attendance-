#include "StudentService.h"
#include "SubjectService.h"
#include "AttendanceService.h"
#include <iostream>
#include <limits>

void addstudent();
int main() {
   std::string name, college, dept;
   
   std::string subject_name;
   
   std::string date , status;
   DatabaseManager db;

   if (!db.connect()) 
{
    std::cout << "DB connection failed\n";
    return 0;
}
   
   
   StudentService studentservice(db);
   AttendanceService attendanceservice(db);
   SubjectService subjectservice(db);
   
   int roll ,subject;
   int age;
   int subject_id;
   
   
   
   
   int choice;

do {
    std::cout << "\n===== ATTENDANCE SYSTEM =====\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Update Student\n";
    std::cout << "3. Add Subject\n";
    std::cout << "4. Mark/ Check Attendance\n";
    std::cout << "5. Update Attendance\n";
    std::cout << "6. Show StudentsData\n";
    std::cout << "7. Show AttendanceData\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            //ADD STUDENT FUNCTION
    
    
    
    std::cout << "\n--- Add Student ---\n\n";
    std::cout << "Enter Roll No: ";
    std::cin >> roll;

    std::cout << "Enter Age: ";
    std::cin >> age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter College: ";
    std::getline(std::cin, college);

    std::cout << "Enter Department: ";
    std::getline(std::cin, dept);

    studentservice.addStudent(roll, name, age, college, dept);
    std::cout << "\nOperation completed.\n";
    break;
    
    
        case 2:
            
	
	
	
	std::cout << "\n--- Update Student ---\n\n";

	std::cout << "Enter Roll Number: ";
	std::cin >> roll;
	
	std::cout << "Enter New Age: ";
	std::cin >> age;
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter New Name: ";
	std::getline(std::cin, name);
	
	std::cout << "Enter New College: ";
	std::getline(std::cin, college);

	std::cout << "Enter New Department: ";
	std::getline(std::cin, dept);

	studentservice.updateStudent(roll, name, age, college, dept);
    break;
    
    
        case 3:
    
    
	

	std::cout << "\n--- Add Subject ---\n\n";

	std::cout << "Enter Subject ID: ";
	std::cin >> subject_id;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter Subject Name: ";
	std::getline(std::cin, subject_name);

	subjectservice.addsubject(subject_id, subject_name);
	std::cout << "\nOperation completed.\n";
            break;
            
            
            
        case 4:
            
     
     
     std::cout << "\n--- Mark Attednace  ---\n\n";
     
     std::cout<<"Enter Roll Number : ";
	 std::cin >> roll; 
     
     std::cout << "Enter Subject ID: ";
	 std::cin >> subject;
	 
	 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     
     std::cout << "Enter Date (YYYY-MM-DD): ";
	 std::getline(std::cin, date);
	 
	 
	 

	 std::cout << "Enter Status (Present/Absent): ";
	 std::getline(std::cin, status);
	 
	 
	 attendanceservice.markAttendance(roll,subject,date,status);
            break;
            
            
            
            
        case 5:
           
	
	
	
	std::cout << "\n--- Update Attendance ---\n\n";

	std::cout << "Enter Roll Number: ";
	std::cin >> roll;

	std::cout << "Enter Subject ID: ";
	std::cin >> subject;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter Date (YYYY-MM-DD): ";
	std::getline(std::cin, date);

	std::cout << "Enter Status (Present/Absent): ";
	std::getline(std::cin, status);

	attendanceservice.updateattendance(roll, subject, date, status);

	std::cout << "\nOperation completed.\n";
            break;
            
            
            
        case 6:
        	
        	
     //SHOW STUDENTSDATA
	
     studentservice.showStudents();
     break;
     
       case 7:
    //Show Attendance
      
      attendanceservice.viewattendance();
      break;
        	
    	case 8:
    std::cout << "----------Exiting---------\n";
    return 0;    
    
    default:
    std::cout << "--------Invalid choice----------\n";
    }

} 
while(choice != 9);
    
	     
    system("pause");
    return 0;
}
