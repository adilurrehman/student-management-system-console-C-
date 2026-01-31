# Student Management System (C++)

A comprehensive C++ console-based student management system that enables administrators to manage student records, track academic performance, and generate statistics with an elegant UI.

## Features

### Student Management
- ✅ **Add New Students** - Register students with ID, name, and age
- ✅ **View All Students** - Display complete list with details
- ✅ **Search Students** - Find by ID or name
- ✅ **Update Information** - Modify student details
- ✅ **Remove Students** - Delete student records with confirmation

### Academic Tracking
- 📚 **Course Management** - Add courses to students
- 📊 **Grade Management** - Record grades (0-100 scale)
- 🎯 **GPA Calculation** - Automatic GPA computation (0-4 scale)
- 📈 **Average Calculation** - Track student averages

### Statistics & Analytics
- 📉 **Class Statistics** - Overall performance metrics
- 🏆 **Top Performers** - Identify highest scorers
- ⚠️ **Low Performers** - Track students needing help
- 📊 **Grade Distribution** - View A/B/C grade counts
- 🔍 **Above/Below Average** - Filter students by performance

### Data Persistence
- 💾 **Save to File** - Persist data between sessions
- 📂 **Auto-load** - Automatically load previous data
- 🔒 **Data Integrity** - Safe file operations

### User Interface
- 🎨 **Elegant Console UI** - Beautiful box-drawing characters
- 📱 **Intuitive Menus** - Easy navigation
- ✓/✗ **Visual Feedback** - Clear success/error indicators
- 📋 **Formatted Output** - Professional data display

## Requirements

- C++ compiler with C++11 support (g++, clang++, etc.)
- Linux, macOS, or Windows
- Make (optional, for using Makefile)

## Installation

### Using Make (Recommended)

```bash
# Clone the repository
git clone https://github.com/adilurrehman/student-management-system-console-C-.git
cd student-management-system-console-C-

# Build the project
make

# Run the program
./student_management
```

### Manual Compilation

```bash
# Compile all source files
g++ -std=c++11 -Wall -o student_management main.cpp Student.cpp StudentManager.cpp

# Run the program
./student_management
```

## Usage

### Main Menu Options

1. **Add New Student** - Register a new student
2. **View All Students** - Display all registered students
3. **Search Student by ID** - Find a specific student
4. **Update Student Information** - Modify student details
5. **Remove Student** - Delete a student record
6. **Add Course to Student** - Enroll student in a course
7. **Add Grade to Student** - Record a grade for a student
8. **Display Statistics** - View system-wide analytics
9. **Search Students by Name** - Find students by name pattern
10. **View Students Above Average** - See top performers
11. **View Students Below Average** - Identify struggling students
12. **Save Data** - Manually save data to file
0. **Exit** - Exit the system (auto-saves)

### Example Workflow

```
1. Add a new student (Name: John Doe, Age: 20)
   → Student receives ID: 1001

2. Add courses to student 1001
   → Add: "Mathematics"
   → Add: "Physics"
   → Add: "Computer Science"

3. Add grades to student 1001
   → Mathematics: 95
   → Physics: 88
   → Computer Science: 92

4. View student details
   → See all information, average (91.67), and GPA (4.0)

5. Display statistics
   → View class average, highest/lowest scorers, grade distribution

6. Exit (data automatically saved)
```

## File Structure

```
student-management-system-console-C-/
│
├── Student.h              # Student class declaration
├── Student.cpp            # Student class implementation
├── StudentManager.h       # Manager class declaration
├── StudentManager.cpp     # Manager class implementation
├── main.cpp               # Main program with UI
├── Makefile               # Build configuration
├── .gitignore             # Git ignore rules
├── README.md              # Documentation
└── students.dat           # Data file (created at runtime)
```

## Data Storage

Student data is stored in `students.dat` file with the following format:
- Automatic save on exit
- Manual save option available
- Data persists between program runs
- Safe file I/O with error handling

## Grading Scale

### Percentage to GPA Conversion
- **90-100%** → GPA 4.0 (Grade A)
- **80-89%**  → GPA 3.0 (Grade B)
- **70-79%**  → GPA 2.0 (Grade C)
- **60-69%**  → GPA 1.0 (Grade D)
- **0-59%**   → GPA 0.0 (Grade F)

## Features in Detail

### Student Class
- Stores student information (ID, name, age)
- Manages courses and grades
- Calculates averages and GPA
- Provides formatted display
- Handles serialization for file storage

### StudentManager Class
- CRUD operations for students
- Grade and course management
- Statistical analysis
- File persistence
- Search and filter capabilities

### Main Program
- Interactive menu system
- Input validation
- Error handling
- Elegant UI with box-drawing characters
- Clear user feedback

## Error Handling

- ✓ Input validation for all user inputs
- ✓ Grade range validation (0-100)
- ✓ Age range validation (1-100)
- ✓ File I/O error handling
- ✓ Student not found handling
- ✓ Empty system handling

## Building from Source

```bash
# Clean previous builds
make clean

# Build the project
make

# Build and run
make run
```

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is open source and available for educational purposes.

## Author

Adil Ur Rehman

## Version

Version 1.0 - January 2026
