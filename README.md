# 📚 Student Management System - RACHNA (C++)

A comprehensive C++ console-based student management system that enables administrators to manage student records, track academic performance, and generate statistics with an elegant UI.

---

## 🎯 Overview

**Student Management System - RACHNA** is a Windows-based console application designed for educational institutions to efficiently manage student data including personal information, course details, and academic marks.

The project focuses on **CRUD operations**, **data validation**, **file-based persistence**, **console UI engineering**, and **user authentication**.

---

## ✨ Key Features

| Feature | Description |
|---------|-------------|
| 🔐 **User Authentication** | Registration & login system with password masking |
| ➕ **Add Student Records** | Input validated student details and marks |
| 📋 **View All Records** | Display complete student database with pagination |
| 🔍 **Search Records** | Find students by roll number instantly |
| ✏️ **Update Records** | Modify existing student information |
| 🗑️ **Delete Records** | Remove student records with confirmation |
| 📊 **Statistics Dashboard** | View class statistics, pass/fail rates, top performers |
| 🎨 **Centered Console UI** | Dynamic centering adapts to console size |
| ⌨️ **Arrow Key Navigation** | Smooth menu navigation with visual highlighting |
| ✅ **Input Validation** | Comprehensive validation for all data fields |
| 🔊 **Sound Effects** | Audio feedback for actions and errors |
| 💾 **File Persistence** | All data saved to text files |

---

## 🛠️ Tech Stack

- **Language:** C++
- **Platform:** Windows API (Console Control)
- **Libraries:** 
  - `windows.h` - Console manipulation, cursor positioning & colors
  - `conio.h` - Real-time keyboard input
  - `fstream` - File handling for student data
  - `iomanip` - Formatted output for marksheets
- **Features:** 
  - File-based authentication & data persistence
  - Dynamic screen centering & responsive layout
  - Password masking for security
  - Object-Oriented Programming with inheritance

---

## 🎮 System Features

### Student Information Fields:
| Field | Validation |
|-------|-----------|
| 📝 Roll Number | 1-9999 (unique) |
| 👤 First Name | 2-20 letters only |
| 👤 Last Name | 2-20 letters only |
| 📖 Course | 2-20 alphanumeric (e.g., BSCS, BSSE) |
| 📅 Date of Birth | DD-MM-YYYY format |
| 📱 Mobile Number | 10-15 digits |
| 🏠 Address | Free text |
| 🌆 City | Letters only |
| 📧 Email | Valid email format (contains @ and .) |

### Subject Marks (0-100 each):
| Subject | Max Marks |
|---------|-----------|
| 💻 Programming Fundamentals | 100 |
| 🔢 Discrete Mathematics | 100 |
| 📝 English | 100 |
| 🧠 Psychology | 100 |
| 🖥️ ICT | 100 |
| 📐 Calculus | 100 |

### Grading System:
| Percentage | Grade | Remark |
|------------|-------|--------|
| 90%+ | A+ | Outstanding! |
| 80-89% | A | Excellent! |
| 70-79% | B+ | Very Good |
| 60-69% | B | Good |
| 50-59% | C | Average |
| 40-49% | D | Pass |
| Below 40% | F | Fail |

---

## 🚀 How to Run

### Option 1: Compile from Source
1. Open `PF project final.cpp` in any C++ IDE (Visual Studio, Code::Blocks, Dev-C++)
2. Build the project
3. Run the compiled executable

### Option 2: Command Line
```bash
g++ "PF project final.cpp" -o "StudentManagementSystem.exe"
./StudentManagementSystem.exe
```

---

## 🎛️ Controls

| Key | Action |
|-----|--------|
| ↑ ↓ | Navigate menu options |
| Enter | Select option / Confirm |
| ESC | Return to previous menu / Exit |

---

## 📁 Project Structure

```
Management System Project/
├── PF project final.cpp   # Main source code (1590+ lines)
├── students.txt           # Student records database
├── login.txt              # User credentials storage
└── README.md              # Project documentation
```

---

## 📸 Screenshots

### Main Menu:
```
╔══════════════════════════════════════════════════════════╗
║          STUDENT MANAGEMENT SYSTEM - RACHNA              ║
║     Developed by: Your Name | Session: 2024-2025         ║
╚══════════════════════════════════════════════════════════╝

                    Logged in as: admin

              ╔════════════════════════════════════════╗
              ║ >> Add New Student Record      <<      ║
              ║    Display All Records                 ║
              ║    Search Student by Roll No           ║
              ║    Update Student Record               ║
              ║    Delete Student Record               ║
              ║    View Statistics                     ║
              ║    Logout & Exit                       ║
              ╚════════════════════════════════════════╝

        [UP/DOWN: Navigate | ENTER: Select | ESC: Exit]
```

### Student Marksheet:
```
  ================= MARKSHEET =================
  Subject                          Max    Obtained
  ------------------------------------------------
  Programming Fundamentals         100        85
  Discrete Mathematics             100        78
  English                          100        92
  Psychology                       100        88
  ICT                              100        95
  Calculus                         100        82
  ------------------------------------------------
  Total                            600        520
  Percentage                                  86.67%

  Grade: A (Excellent!)
```

---

## 🎯 Application Flow

```
┌─────────────────┐
│  System Loading │
│   (Animated)    │
└────────┬────────┘
         ▼
┌─────────────────┐
│  Login/Register │
│     Portal      │
└────────┬────────┘
         ▼
┌─────────────────┐
│    MAIN MENU    │◄──────────────────┐
│                 │                   │
└────────┬────────┘                   │
         ▼                            │
┌─────────────────┐                   │
│ • Add Record    │───────────────────┤
│ • Display All   │───────────────────┤
│ • Search        │───────────────────┤
│ • Update        │───────────────────┤
│ • Delete        │───────────────────┤
│ • Statistics    │───────────────────┘
└────────┬────────┘
         ▼
┌─────────────────┐
│  Logout & Exit  │
│   (Goodbye!)    │
└─────────────────┘
```

---

## 📊 Statistics Dashboard

The system provides comprehensive statistics including:

| Statistic | Description |
|-----------|-------------|
| 📈 Total Students | Count of all registered students |
| 📊 Average Percentage | Class average performance |
| 🏆 Highest Percentage | Top performer with name |
| 📉 Lowest Percentage | Minimum score in class |
| ✅ Students Passed | Count (≥40% marks) |
| ❌ Students Failed | Count (<40% marks) |

---

## ⚠️ Requirements

- **OS:** Windows only (uses WinAPI)
- **Compiler:** Any C++ compiler supporting Windows headers
- **Console:** Windows Command Prompt or PowerShell
- **Sound:** System speaker for audio feedback

---

## 📚 Learning Outcomes

- ✅ Object-Oriented Programming (Classes & Inheritance)
- ✅ Console UI/UX design with dynamic centering
- ✅ File-based authentication system
- ✅ CRUD operations implementation
- ✅ Input validation techniques
- ✅ Arrow key input handling
- ✅ Data persistence with file I/O
- ✅ Modular function design
- ✅ Color-coded console output
- ✅ Sound effect integration
- ✅ Box drawing with Unicode characters

---

## 🎨 UI Features

| Feature | Implementation |
|---------|----------------|
| Colored Text | 10+ color combinations for different elements |
| Box Drawing | Unicode box characters (╔═╗║╚╝) for menus |
| Animated Loading | Progress bar with sound on startup |
| Password Masking | Asterisks (***) shown instead of password |
| Centered Layout | All content dynamically centered |
| Highlighted Selection | Inverted colors for selected menu item |
| Input Validation | Real-time error messages with sound |

---

## 🔐 Security Features

- **Password Masking:** Characters hidden during input
- **Username Validation:** 3-20 alphanumeric characters
- **Password Minimum Length:** 4 characters required
- **Password Confirmation:** Must match for registration
- **Duplicate Prevention:** Unique usernames enforced
- **Roll Number Uniqueness:** No duplicate student records

---

## 👨‍💻 Author

**Adil ur Rehman**  
Computer Science Undergraduate  
Session: 2024-2025

---

## 📄 License

This project is created for educational purposes as part of the **Programming Fundamentals** course 1st semester project.

---

*Made with ❤️ and C++*
