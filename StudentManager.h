#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.h"
#include <vector>
#include <string>
#include <map>

class StudentManager {
private:
    std::vector<Student> students;
    int nextID;
    std::string dataFile;

public:
    StudentManager();
    explicit StudentManager(const std::string& filename);

    // CRUD Operations
    void addStudent(const std::string& name, int age);
    bool removeStudent(int studentID);
    Student* findStudent(int studentID);
    void updateStudent(int studentID);
    void displayAllStudents() const;

    // Grade and Course Management
    void addGradeToStudent(int studentID, double grade);
    void addCourseToStudent(int studentID, const std::string& course);

    // Statistics
    void displayStatistics() const;
    double calculateClassAverage() const;
    Student* findHighestScorer() const;
    Student* findLowestScorer() const;
    int getTotalStudents() const { return students.size(); }

    // File Operations
    void saveToFile() const;
    void loadFromFile();
    
    // Search and Filter
    std::vector<Student*> searchByName(const std::string& name);
    std::vector<Student*> getStudentsAboveAverage();
    std::vector<Student*> getStudentsBelowAverage();
};

#endif
