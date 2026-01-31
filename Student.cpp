#include "Student.h"
#include <iomanip>
#include <numeric>

Student::Student() : studentID(0), name(""), age(0) {}

Student::Student(int id, const std::string& name, int age) 
    : studentID(id), name(name), age(age) {}

void Student::addGrade(double grade) {
    if (grade >= 0.0 && grade <= 100.0) {
        grades.push_back(grade);
    }
}

void Student::addCourse(const std::string& course) {
    courses.push_back(course);
}

double Student::calculateAverage() const {
    if (grades.empty()) return 0.0;
    double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
    return sum / grades.size();
}

double Student::calculateGPA() const {
    if (grades.empty()) return 0.0;
    double avg = calculateAverage();
    // Convert percentage to GPA (0-4 scale)
    if (avg >= 90) return 4.0;
    else if (avg >= 80) return 3.0;
    else if (avg >= 70) return 2.0;
    else if (avg >= 60) return 1.0;
    else return 0.0;
}

void Student::displayInfo() const {
    std::cout << "┌─────────────────────────────────────────────────────┐\n";
    std::cout << "│ Student ID: " << std::setw(37) << std::left << studentID << "│\n";
    std::cout << "│ Name:       " << std::setw(37) << std::left << name << "│\n";
    std::cout << "│ Age:        " << std::setw(37) << std::left << age << "│\n";
    std::cout << "├─────────────────────────────────────────────────────┤\n";
    
    if (!courses.empty()) {
        std::cout << "│ Courses:                                            │\n";
        for (size_t i = 0; i < courses.size(); ++i) {
            std::cout << "│   " << i + 1 << ". " << std::setw(45) << std::left << courses[i] << "│\n";
        }
    }
    
    if (!grades.empty()) {
        std::cout << "├─────────────────────────────────────────────────────┤\n";
        std::cout << "│ Grades:                                             │\n";
        for (size_t i = 0; i < grades.size(); ++i) {
            std::cout << "│   " << std::setw(47) << std::left 
                      << (courses.size() > i ? courses[i] : "Course " + std::to_string(i + 1)) 
                      << "│\n";
            std::cout << "│     Score: " << std::fixed << std::setprecision(2) 
                      << std::setw(38) << std::left << grades[i] << "│\n";
        }
        std::cout << "├─────────────────────────────────────────────────────┤\n";
        std::cout << "│ Average: " << std::fixed << std::setprecision(2) 
                  << std::setw(41) << std::left << calculateAverage() << "│\n";
        std::cout << "│ GPA:     " << std::fixed << std::setprecision(2) 
                  << std::setw(41) << std::left << calculateGPA() << "│\n";
    }
    
    std::cout << "└─────────────────────────────────────────────────────┘\n";
}

void Student::serialize(std::ostream& out) const {
    out << studentID << "\n";
    out << name << "\n";
    out << age << "\n";
    out << grades.size() << "\n";
    for (double grade : grades) {
        out << grade << "\n";
    }
    out << courses.size() << "\n";
    for (const std::string& course : courses) {
        out << course << "\n";
    }
}

void Student::deserialize(std::istream& in) {
    in >> studentID;
    in.ignore();
    std::getline(in, name);
    in >> age;
    
    size_t gradeCount;
    in >> gradeCount;
    grades.clear();
    for (size_t i = 0; i < gradeCount; ++i) {
        double grade;
        in >> grade;
        grades.push_back(grade);
    }
    
    size_t courseCount;
    in >> courseCount;
    in.ignore();
    courses.clear();
    for (size_t i = 0; i < courseCount; ++i) {
        std::string course;
        std::getline(in, course);
        courses.push_back(course);
    }
}
