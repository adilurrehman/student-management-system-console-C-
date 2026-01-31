#include "StudentManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

StudentManager::StudentManager() : nextID(1001), dataFile("students.dat") {}

StudentManager::StudentManager(const std::string& filename) 
    : nextID(1001), dataFile(filename) {
    loadFromFile();
}

void StudentManager::addStudent(const std::string& name, int age) {
    Student newStudent(nextID++, name, age);
    students.push_back(newStudent);
    std::cout << "\n✓ Student added successfully! ID: " << (nextID - 1) << "\n";
}

bool StudentManager::removeStudent(int studentID) {
    auto it = std::find_if(students.begin(), students.end(),
        [studentID](const Student& s) { return s.getStudentID() == studentID; });
    
    if (it != students.end()) {
        students.erase(it);
        std::cout << "\n✓ Student removed successfully!\n";
        return true;
    }
    std::cout << "\n✗ Student not found!\n";
    return false;
}

Student* StudentManager::findStudent(int studentID) {
    for (auto& student : students) {
        if (student.getStudentID() == studentID) {
            return &student;
        }
    }
    return nullptr;
}

void StudentManager::updateStudent(int studentID) {
    Student* student = findStudent(studentID);
    if (!student) {
        std::cout << "\n✗ Student not found!\n";
        return;
    }

    std::cout << "\n═══════════════════════════════════════════════════\n";
    std::cout << "            UPDATE STUDENT INFORMATION             \n";
    std::cout << "═══════════════════════════════════════════════════\n";
    
    std::string newName;
    int newAge;
    
    std::cout << "Current Name: " << student->getName() << "\n";
    std::cout << "Enter new name (or press Enter to keep current): ";
    std::cin.ignore();
    std::getline(std::cin, newName);
    if (!newName.empty()) {
        student->setName(newName);
    }
    
    std::cout << "Current Age: " << student->getAge() << "\n";
    std::cout << "Enter new age (or 0 to keep current): ";
    std::cin >> newAge;
    if (newAge > 0) {
        student->setAge(newAge);
    }
    
    std::cout << "\n✓ Student updated successfully!\n";
}

void StudentManager::displayAllStudents() const {
    if (students.empty()) {
        std::cout << "\n╔═══════════════════════════════════════════════════╗\n";
        std::cout << "║           No students in the system!              ║\n";
        std::cout << "╚═══════════════════════════════════════════════════╝\n";
        return;
    }

    std::cout << "\n╔═══════════════════════════════════════════════════╗\n";
    std::cout << "║              ALL STUDENT RECORDS                  ║\n";
    std::cout << "╠═══════════════════════════════════════════════════╣\n";
    std::cout << "║ Total Students: " << std::setw(32) << std::left << students.size() << "║\n";
    std::cout << "╚═══════════════════════════════════════════════════╝\n\n";

    for (const auto& student : students) {
        student.displayInfo();
        std::cout << "\n";
    }
}

void StudentManager::addGradeToStudent(int studentID, double grade) {
    Student* student = findStudent(studentID);
    if (student) {
        if (grade >= 0.0 && grade <= 100.0) {
            student->addGrade(grade);
            std::cout << "\n✓ Grade added successfully!\n";
        } else {
            std::cout << "\n✗ Invalid grade! Must be between 0 and 100.\n";
        }
    } else {
        std::cout << "\n✗ Student not found!\n";
    }
}

void StudentManager::addCourseToStudent(int studentID, const std::string& course) {
    Student* student = findStudent(studentID);
    if (student) {
        student->addCourse(course);
        std::cout << "\n✓ Course added successfully!\n";
    } else {
        std::cout << "\n✗ Student not found!\n";
    }
}

void StudentManager::displayStatistics() const {
    if (students.empty()) {
        std::cout << "\n✗ No students in the system!\n";
        return;
    }

    std::cout << "\n╔═══════════════════════════════════════════════════╗\n";
    std::cout << "║              SYSTEM STATISTICS                    ║\n";
    std::cout << "╚═══════════════════════════════════════════════════╝\n\n";

    std::cout << "┌─────────────────────────────────────────────────────┐\n";
    std::cout << "│ Total Students:     " << std::setw(28) << std::left << students.size() << "│\n";
    std::cout << "│ Class Average:      " << std::fixed << std::setprecision(2) 
              << std::setw(28) << std::left << calculateClassAverage() << "│\n";

    Student* highest = findHighestScorer();
    if (highest && !highest->getGrades().empty()) {
        std::cout << "│ Highest Scorer:     " << std::setw(28) << std::left 
                  << highest->getName() << "│\n";
        std::cout << "│   Score:            " << std::fixed << std::setprecision(2) 
                  << std::setw(28) << std::left << highest->calculateAverage() << "│\n";
    }

    Student* lowest = findLowestScorer();
    if (lowest && !lowest->getGrades().empty()) {
        std::cout << "│ Lowest Scorer:      " << std::setw(28) << std::left 
                  << lowest->getName() << "│\n";
        std::cout << "│   Score:            " << std::fixed << std::setprecision(2) 
                  << std::setw(28) << std::left << lowest->calculateAverage() << "│\n";
    }

    // Count students with grades
    int studentsWithGrades = 0;
    int studentsAbove70 = 0;
    int studentsAbove80 = 0;
    int studentsAbove90 = 0;
    
    for (const auto& student : students) {
        if (!student.getGrades().empty()) {
            studentsWithGrades++;
            double avg = student.calculateAverage();
            if (avg >= 90) studentsAbove90++;
            else if (avg >= 80) studentsAbove80++;
            else if (avg >= 70) studentsAbove70++;
        }
    }

    std::cout << "├─────────────────────────────────────────────────────┤\n";
    std::cout << "│ Students with grades: " << std::setw(26) << std::left << studentsWithGrades << "│\n";
    std::cout << "│ Grade A (90-100):     " << std::setw(26) << std::left << studentsAbove90 << "│\n";
    std::cout << "│ Grade B (80-89):      " << std::setw(26) << std::left << studentsAbove80 << "│\n";
    std::cout << "│ Grade C (70-79):      " << std::setw(26) << std::left << studentsAbove70 << "│\n";
    std::cout << "└─────────────────────────────────────────────────────┘\n";
}

double StudentManager::calculateClassAverage() const {
    if (students.empty()) return 0.0;
    
    double sum = 0.0;
    int count = 0;
    
    for (const auto& student : students) {
        if (!student.getGrades().empty()) {
            sum += student.calculateAverage();
            count++;
        }
    }
    
    return count > 0 ? sum / count : 0.0;
}

Student* StudentManager::findHighestScorer() const {
    if (students.empty()) return nullptr;
    
    Student* highest = nullptr;
    double maxAverage = -1.0;
    
    for (const auto& student : students) {
        if (!student.getGrades().empty()) {
            double avg = student.calculateAverage();
            if (avg > maxAverage) {
                maxAverage = avg;
                highest = const_cast<Student*>(&student);
            }
        }
    }
    
    return highest;
}

Student* StudentManager::findLowestScorer() const {
    if (students.empty()) return nullptr;
    
    Student* lowest = nullptr;
    double minAverage = 101.0;
    
    for (const auto& student : students) {
        if (!student.getGrades().empty()) {
            double avg = student.calculateAverage();
            if (avg < minAverage) {
                minAverage = avg;
                lowest = const_cast<Student*>(&student);
            }
        }
    }
    
    return lowest;
}

void StudentManager::saveToFile() const {
    std::ofstream file(dataFile);
    if (!file) {
        std::cout << "\n✗ Error saving to file!\n";
        return;
    }

    file << students.size() << "\n";
    for (const auto& student : students) {
        student.serialize(file);
    }
    file << nextID << "\n";
    
    file.close();
    std::cout << "\n✓ Data saved successfully!\n";
}

void StudentManager::loadFromFile() {
    std::ifstream file(dataFile);
    if (!file) {
        return; // File doesn't exist yet, that's okay
    }

    students.clear();
    size_t count;
    file >> count;
    
    for (size_t i = 0; i < count; ++i) {
        Student student;
        student.deserialize(file);
        students.push_back(student);
    }
    
    file >> nextID;
    file.close();
}

std::vector<Student*> StudentManager::searchByName(const std::string& name) {
    std::vector<Student*> results;
    std::string lowerName = name;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    
    for (auto& student : students) {
        std::string studentName = student.getName();
        std::transform(studentName.begin(), studentName.end(), studentName.begin(), ::tolower);
        if (studentName.find(lowerName) != std::string::npos) {
            results.push_back(&student);
        }
    }
    
    return results;
}

std::vector<Student*> StudentManager::getStudentsAboveAverage() {
    std::vector<Student*> results;
    double classAvg = calculateClassAverage();
    
    for (auto& student : students) {
        if (!student.getGrades().empty() && student.calculateAverage() > classAvg) {
            results.push_back(&student);
        }
    }
    
    return results;
}

std::vector<Student*> StudentManager::getStudentsBelowAverage() {
    std::vector<Student*> results;
    double classAvg = calculateClassAverage();
    
    for (auto& student : students) {
        if (!student.getGrades().empty() && student.calculateAverage() < classAvg) {
            results.push_back(&student);
        }
    }
    
    return results;
}
