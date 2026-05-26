# 📊 C++ Student Attendance Management System

A robust, console-based Attendance Management application built in C++ that integrates seamlessly with a MySQL database. This project focuses on secure data handling, clean architecture, and practical CRUD operations.

## 🚀 Key Features
* **Student Record Management:** Add, update, and securely store student details.
* **Daily Attendance Tracking:** Record and retrieve attendance data linked to specific students and subjects.
* **Secure Database Architecture:** Utilizes a file-stream configuration approach to keep sensitive database credentials completely out of the source code and version control.
* **Modular Design:** Separation of concerns using dedicated service classes (`StudentService`, `AttendanceService`, `SubjectService`, `DatabaseManager`).

## 🛠️ Technology Stack
* **Language:** C++
* **Database:** MySQL (via `mysql.h` connector API)
* **Environment:** Dev-C++ 
* **Version Control:** Git / GitHub

## 🔐 Security Highlight
Hardcoding database credentials is a major security vulnerability. This project solves this by employing a `.gitignore` strategy combined with the standard `<fstream>` library. The application reads from a local `db_config.txt` file at runtime, ensuring passwords are never pushed to the public repository.

## ⚙️ Local Setup and Installation

### 1. Prerequisites
* Dev-C++ IDE installed.
* MySQL Server running locally (default port 3306).
* MySQL C++ Connector libraries linked in your compiler settings.

### 2. Database Configuration
Run the following SQL script in your MySQL environment to set up the necessary schema:
```sql
CREATE DATABASE IF NOT EXISTS AttendanceDB;
USE AttendanceDB;

CREATE TABLE Students (
    RollNumber INT PRIMARY KEY,
    Name VARCHAR(100) NOT NULL
);

-- Add your other CREATE TABLE statements here (Subjects, Attendance, etc.)
