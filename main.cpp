#include "StudentManager.h"
#include <iostream>
#include <limits>
#include <string>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void displayHeader() {
    std::cout << "╔═══════════════════════════════════════════════════╗\n";
    std::cout << "║                                                   ║\n";
    std::cout << "║       STUDENT MANAGEMENT SYSTEM v1.0              ║\n";
    std::cout << "║                                                   ║\n";
    std::cout << "╚═══════════════════════════════════════════════════╝\n\n";
}

void displayMenu() {
    std::cout << "┌───────────────────────────────────────────────────┐\n";
    std::cout << "│                   MAIN MENU                       │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    std::cout << "│  1. Add New Student                               │\n";
    std::cout << "│  2. View All Students                             │\n";
    std::cout << "│  3. Search Student by ID                          │\n";
    std::cout << "│  4. Update Student Information                    │\n";
    std::cout << "│  5. Remove Student                                │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    std::cout << "│  6. Add Course to Student                         │\n";
    std::cout << "│  7. Add Grade to Student                          │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    std::cout << "│  8. Display Statistics                            │\n";
    std::cout << "│  9. Search Students by Name                       │\n";
    std::cout << "│ 10. View Students Above Average                   │\n";
    std::cout << "│ 11. View Students Below Average                   │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    std::cout << "│ 12. Save Data                                     │\n";
    std::cout << "│  0. Exit                                          │\n";
    std::cout << "└───────────────────────────────────────────────────┘\n\n";
    std::cout << "Enter your choice: ";
}

void handleAddStudent(StudentManager& manager) {
    clearScreen();
    displayHeader();
    std::cout << "═══════════════════════════════════════════════════\n";
    std::cout << "                 ADD NEW STUDENT                    \n";
    std::cout << "═══════════════════════════════════════════════════\n\n";
    
    std::string name;
    int age;
    
    std::cout << "Enter student name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    std::cout << "Enter student age: ";
    std::cin >> age;
    
    if (age < 1 || age > 100) {
        std::cout << "\n✗ Invalid age! Please enter a value between 1 and 100.\n";
        pauseScreen();
        return;
    }
    
    manager.addStudent(name, age);
    pauseScreen();
}

void handleViewAllStudents(StudentManager& manager) {
    clearScreen();
    displayHeader();
    manager.displayAllStudents();
    pauseScreen();
}

void handleSearchStudent(StudentManager& manager) {
    clearScreen();
    displayHeader();
    std::cout << "═══════════════════════════════════════════════════\n";
    std::cout << "                 SEARCH STUDENT                     \n";
    std::cout << "═══════════════════════════════════════════════════\n\n";
    
    int id;
    std::cout << "Enter student ID: ";
    std::cin >> id;
    
    Student* student = manager.findStudent(id);
    if (student) {
        std::cout << "\n";
        student->displayInfo();
    } else {
        std::cout << "\n✗ Student not found!\n";
    }
    
    pauseScreen();
}

void handleUpdateStudent(StudentManager& manager) {
    clearScreen();
    displayHeader();
    
    int id;
    std::cout << "Enter student ID to update: ";
    std::cin >> id;
    
    manager.updateStudent(id);
    pauseScreen();
}

void handleRemoveStudent(StudentManager& manager) {
    clearScreen();
    displayHeader();
    std::cout << "═══════════════════════════════════════════════════\n";
    std::cout << "                 REMOVE STUDENT                     \n";
    std::cout << "═══════════════════════════════════════════════════\n\n";
    
    int id;
    std::cout << "Enter student ID to remove: ";
    std::cin >> id;
    
    Student* student = manager.findStudent(id);
    if (student) {
        std::cout << "\nStudent to be removed:\n";
        student->displayInfo();
        
        char confirm;
        std::cout << "\nAre you sure you want to remove this student? (y/n): ";
        std::cin >> confirm;
        
        if (confirm == 'y' || confirm == 'Y') {
            manager.removeStudent(id);
        } else {
            std::cout << "\n✗ Operation cancelled.\n";
        }
    } else {
        std::cout << "\n✗ Student not found!\n";
    }
    
    pauseScreen();
}

void handleAddCourse(StudentManager& manager) {
    clearScreen();
    displayHeader();
    std::cout << "═══════════════════════════════════════════════════\n";
    std::cout << "                 ADD COURSE                         \n";
    std::cout << "═══════════════════════════════════════════════════\n\n";
    
    int id;
    std::string course;
    
    std::cout << "Enter student ID: ";
    std::cin >> id;
    
    std::cout << "Enter course name: ";
    std::cin.ignore();
    std::getline(std::cin, course);
    
    manager.addCourseToStudent(id, course);
    pauseScreen();
}

void handleAddGrade(StudentManager& manager) {
    clearScreen();
    displayHeader();
    std::cout << "═══════════════════════════════════════════════════\n";
    std::cout << "                 ADD GRADE                          \n";
    std::cout << "═══════════════════════════════════════════════════\n\n";
    
    int id;
    double grade;
    
    std::cout << "Enter student ID: ";
    std::cin >> id;
    
    std::cout << "Enter grade (0-100): ";
    std::cin >> grade;
    
    manager.addGradeToStudent(id, grade);
    pauseScreen();
}

void handleDisplayStatistics(StudentManager& manager) {
    clearScreen();
    displayHeader();
    manager.displayStatistics();
    pauseScreen();
}

void handleSearchByName(StudentManager& manager) {
    clearScreen();
    displayHeader();
    std::cout << "═══════════════════════════════════════════════════\n";
    std::cout << "               SEARCH BY NAME                       \n";
    std::cout << "═══════════════════════════════════════════════════\n\n";
    
    std::string name;
    std::cout << "Enter name to search: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    std::vector<Student*> results = manager.searchByName(name);
    
    if (results.empty()) {
        std::cout << "\n✗ No students found matching '" << name << "'.\n";
    } else {
        std::cout << "\nFound " << results.size() << " student(s):\n\n";
        for (auto* student : results) {
            student->displayInfo();
            std::cout << "\n";
        }
    }
    
    pauseScreen();
}

void handleAboveAverage(StudentManager& manager) {
    clearScreen();
    displayHeader();
    std::cout << "═══════════════════════════════════════════════════\n";
    std::cout << "           STUDENTS ABOVE AVERAGE                   \n";
    std::cout << "═══════════════════════════════════════════════════\n\n";
    
    std::vector<Student*> results = manager.getStudentsAboveAverage();
    
    if (results.empty()) {
        std::cout << "\n✗ No students found above class average.\n";
    } else {
        std::cout << "Found " << results.size() << " student(s) above average:\n\n";
        for (auto* student : results) {
            student->displayInfo();
            std::cout << "\n";
        }
    }
    
    pauseScreen();
}

void handleBelowAverage(StudentManager& manager) {
    clearScreen();
    displayHeader();
    std::cout << "═══════════════════════════════════════════════════\n";
    std::cout << "           STUDENTS BELOW AVERAGE                   \n";
    std::cout << "═══════════════════════════════════════════════════\n\n";
    
    std::vector<Student*> results = manager.getStudentsBelowAverage();
    
    if (results.empty()) {
        std::cout << "\n✗ No students found below class average.\n";
    } else {
        std::cout << "Found " << results.size() << " student(s) below average:\n\n";
        for (auto* student : results) {
            student->displayInfo();
            std::cout << "\n";
        }
    }
    
    pauseScreen();
}

void handleSaveData(StudentManager& manager) {
    clearScreen();
    displayHeader();
    std::cout << "═══════════════════════════════════════════════════\n";
    std::cout << "                 SAVE DATA                          \n";
    std::cout << "═══════════════════════════════════════════════════\n\n";
    
    manager.saveToFile();
    pauseScreen();
}

int main() {
    StudentManager manager("students.dat");
    int choice;
    
    do {
        clearScreen();
        displayHeader();
        displayMenu();
        
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n✗ Invalid input! Please enter a number.\n";
            pauseScreen();
            continue;
        }
        
        switch (choice) {
            case 1:
                handleAddStudent(manager);
                break;
            case 2:
                handleViewAllStudents(manager);
                break;
            case 3:
                handleSearchStudent(manager);
                break;
            case 4:
                handleUpdateStudent(manager);
                break;
            case 5:
                handleRemoveStudent(manager);
                break;
            case 6:
                handleAddCourse(manager);
                break;
            case 7:
                handleAddGrade(manager);
                break;
            case 8:
                handleDisplayStatistics(manager);
                break;
            case 9:
                handleSearchByName(manager);
                break;
            case 10:
                handleAboveAverage(manager);
                break;
            case 11:
                handleBelowAverage(manager);
                break;
            case 12:
                handleSaveData(manager);
                break;
            case 0:
                std::cout << "\n╔═══════════════════════════════════════════════════╗\n";
                std::cout << "║  Thank you for using Student Management System!  ║\n";
                std::cout << "║              Saving data...                       ║\n";
                std::cout << "╚═══════════════════════════════════════════════════╝\n\n";
                manager.saveToFile();
                break;
            default:
                std::cout << "\n✗ Invalid choice! Please try again.\n";
                pauseScreen();
        }
        
    } while (choice != 0);
    
    return 0;
}
