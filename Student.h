#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>

class Student {
private:
    int studentID;
    std::string name;
    int age;
    std::vector<double> grades;
    std::vector<std::string> courses;

public:
    // Constructors
    Student();
    Student(int id, const std::string& name, int age);

    // Getters
    int getStudentID() const { return studentID; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::vector<double> getGrades() const { return grades; }
    std::vector<std::string> getCourses() const { return courses; }

    // Setters
    void setStudentID(int id) { studentID = id; }
    void setName(const std::string& n) { name = n; }
    void setAge(int a) { age = a; }

    // Methods
    void addGrade(double grade);
    void addCourse(const std::string& course);
    double calculateAverage() const;
    double calculateGPA() const;
    void displayInfo() const;

    // File I/O
    void serialize(std::ostream& out) const;
    void deserialize(std::istream& in);
};

#endif
