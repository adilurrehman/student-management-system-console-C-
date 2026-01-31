#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include <sstream>
#include <ctime>
#include <algorithm>
using namespace std;

// Screen dimensions
int screenWidth = 80;
int screenHeight = 25;
int centerX = 40;
int centerY = 12;

// Arrow key codes
const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_ENTER = 13;
const int KEY_ESC = 27;

// Current logged in user
string current_user = "";
int total_records = 0;

// Function prototypes
void gotoxy(int x, int y);
void setConsoleSize();
void getScreenDimensions();
void clearScreen();
void hideConsoleCursor();
void showConsoleCursor();
void setConsoleColor(int color);
void printCentered(string text, int y);
void printBox(int x, int y, int width, int height);
void playSound(int frequency, int duration);
void printheadermenu();
void printDeveloperHeader();
void printloginmenu();
void loginn();
void registerr();
int navigateMenu(string options[], int numOptions, string title);
void mainMenu();

// Console helper functions
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideConsoleCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void showConsoleCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void getScreenDimensions() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    screenHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    centerX = screenWidth / 2;
    centerY = screenHeight / 2;
}

void setConsoleSize() {
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE);
    Sleep(100);
    getScreenDimensions();
}

void clearScreen() {
    system("CLS");
    getScreenDimensions();
}

void printCentered(string text, int y) {
    int x = centerX - (text.length() / 2);
    if (x < 0) x = 0;
    gotoxy(x, y);
    cout << text;
}

void printBox(int x, int y, int width, int height) {
    setConsoleColor(11); // Cyan
    gotoxy(x, y);
    cout << char(201);
    for (int i = 0; i < width - 2; i++) cout << char(205);
    cout << char(187);
    
    for (int i = 1; i < height - 1; i++) {
        gotoxy(x, y + i);
        cout << char(186);
        gotoxy(x + width - 1, y + i);
        cout << char(186);
    }
    
    gotoxy(x, y + height - 1);
    cout << char(200);
    for (int i = 0; i < width - 2; i++) cout << char(205);
    cout << char(188);
    setConsoleColor(7);
}

void playSound(int frequency, int duration) {
    Beep(frequency, duration);
}

void printDeveloperHeader() {
    getScreenDimensions();
    int boxWidth = 60;
    int startX = centerX - boxWidth / 2;
    
    setConsoleColor(14); // Yellow
    printBox(startX, 0, boxWidth, 4);
    setConsoleColor(15); // Bright White
    printCentered("STUDENT MANAGEMENT SYSTEM - RACHNA", 1);
    setConsoleColor(10); // Green
    printCentered("Developed by: Your Name | Session: 2024-2025", 2);
    setConsoleColor(7);
}

void printheadermenu() {
    clearScreen();
    getScreenDimensions();
    
    int boxWidth = 60;
    int startX = centerX - boxWidth / 2;
    int startY = centerY - 8;
    
    setConsoleColor(14); // Yellow
    printBox(startX, startY, boxWidth, 10);
    
    setConsoleColor(15); // Bright White
    printCentered("**********************************************************", startY + 1);
    setConsoleColor(11); // Cyan
    printCentered("*        STUDENT MANAGEMENT SYSTEM - RACHNA             *", startY + 2);
    setConsoleColor(10); // Green
    printCentered("*              Programming Fundamentals                 *", startY + 3);
    printCentered("*                 Final Semester Project                *", startY + 4);
    setConsoleColor(14);
    printCentered("*                   Session: 2024-2025                  *", startY + 5);
    setConsoleColor(15);
    printCentered("**********************************************************", startY + 6);
    
    setConsoleColor(12); // Red
    printCentered("System Loading", startY + 10);
    
    // Animated loading bar
    int barWidth = 40;
    int barX = centerX - barWidth / 2;
    gotoxy(barX, startY + 11);
    setConsoleColor(8);
    cout << "[";
    for (int i = 0; i < barWidth - 2; i++) cout << " ";
    cout << "]";
    
    for (int i = 0; i < barWidth - 2; i++) {
        gotoxy(barX + 1 + i, startY + 11);
        setConsoleColor(10);
        cout << char(219);
        playSound(200 + i * 15, 30);
        Sleep(30);
    }
    
    setConsoleColor(10);
    printCentered("PRESS ANY KEY TO CONTINUE...", startY + 14);
    setConsoleColor(7);
    _getch();
}

void printloginmenu() {
    clearScreen();
    printDeveloperHeader();
    
    int boxWidth = 50;
    int startX = centerX - boxWidth / 2;
    int startY = 6;
    
    setConsoleColor(14);
    printBox(startX, startY, boxWidth, 6);
    
    setConsoleColor(15);
    printCentered("Welcome To Login Portal", startY + 2);
    setConsoleColor(11);
    printCentered("Enter Username and Password to Continue", startY + 3);
    setConsoleColor(7);
    Sleep(500);
}

void loginn() {
    showConsoleCursor();
    int count = 0;
    string username, password, id, pass;
    
    int inputY = 14;
    int startX = centerX - 25;
    
    setConsoleColor(14);
    gotoxy(startX, inputY);
    cout << "============ LOGIN ============";
    setConsoleColor(7);
    
    // Username validation - alphanumeric only
    bool validUsername = false;
    do {
        gotoxy(startX, inputY + 2);
        cout << "Enter Username: ";
        cin >> username;
        
        validUsername = true;
        if (username.length() < 3 || username.length() > 20) {
            validUsername = false;
        } else {
            for (size_t i = 0; i < username.length(); i++) {
                if (!isalnum(username[i])) {
                    validUsername = false;
                    break;
                }
            }
        }
        
        if (!validUsername) {
            setConsoleColor(12);
            gotoxy(startX, inputY + 3);
            cout << "Invalid! Use 3-20 alphanumeric chars only.";
            playSound(300, 200);
            Sleep(1000);
            gotoxy(startX, inputY + 3);
            cout << "                                            ";
            gotoxy(startX, inputY + 2);
            cout << "                                            ";
        }
    } while (!validUsername);
    
    gotoxy(startX, inputY + 3);
    cout << "Enter Password: ";
    
    // Password masking
    password = "";
    char ch;
    while ((ch = _getch()) != 13) {
        if (ch == 8 && password.length() > 0) {
            password.pop_back();
            cout << "\b \b";
        } else if (ch != 8 && ch != 0 && ch != 224) {
            password += ch;
            cout << "*";
        }
    }
    cout << endl;
    
    fstream login;
    login.open("login.txt", ios::in);
    while (login >> id >> pass) {
        if (id == username && pass == password) {
            count++;
            current_user = username;
        }
    }
    login.close();
    
    if (count > 0) {
        setConsoleColor(10);
        gotoxy(startX, inputY + 5);
        cout << "Login Successful! Welcome, " << username << "!";
        playSound(800, 200);
        playSound(1000, 200);
        Sleep(1500);
    } else {
        setConsoleColor(12);
        gotoxy(startX, inputY + 5);
        cout << "Login Failed: Invalid Username or Password!";
        playSound(300, 500);
        gotoxy(startX, inputY + 7);
        setConsoleColor(14);
        cout << "New User? Please Register Below";
        registerr();
        Sleep(700);
    }
    setConsoleColor(7);
    hideConsoleCursor();
}

void registerr() {
    showConsoleCursor();
    string username, password, confirmPass, id, pass;
    bool usernameExists = false;
    bool validUsername = false;
    bool validPassword = false;
    
    int inputY = 20;
    int startX = centerX - 25;

    setConsoleColor(14);
    gotoxy(startX, inputY);
    cout << "========== REGISTER ==========";
    setConsoleColor(7);

    // Username validation
    do {
        usernameExists = false;
        validUsername = false;
        
        gotoxy(startX, inputY + 2);
        cout << "Choose Username (3-20 chars): ";
        cin >> username;

        // Validate username format
        validUsername = true;
        if (username.length() < 3 || username.length() > 20) {
            validUsername = false;
        } else {
            for (size_t i = 0; i < username.length(); i++) {
                if (!isalnum(username[i])) {
                    validUsername = false;
                    break;
                }
            }
        }
        
        if (!validUsername) {
            setConsoleColor(12);
            gotoxy(startX, inputY + 3);
            cout << "Invalid! Use alphanumeric characters only.";
            playSound(300, 200);
            Sleep(1000);
            gotoxy(startX, inputY + 3);
            cout << "                                          ";
            gotoxy(startX, inputY + 2);
            cout << "                                                ";
            continue;
        }

        // Check if username already exists
        fstream login;
        login.open("login.txt", ios::in);
        while (login >> id >> pass) {
            if (id == username) {
                usernameExists = true;
                setConsoleColor(12);
                gotoxy(startX, inputY + 3);
                cout << "Username already taken! Choose another.";
                playSound(300, 200);
                Sleep(1000);
                gotoxy(startX, inputY + 3);
                cout << "                                        ";
                gotoxy(startX, inputY + 2);
                cout << "                                                ";
                break;
            }
        }
        login.close();
    } while (usernameExists || !validUsername);

    // Password validation
    do {
        gotoxy(startX, inputY + 3);
        cout << "Choose Password (min 4 chars): ";
        
        password = "";
        char ch;
        while ((ch = _getch()) != 13) {
            if (ch == 8 && password.length() > 0) {
                password.pop_back();
                cout << "\b \b";
            } else if (ch != 8 && ch != 0 && ch != 224) {
                password += ch;
                cout << "*";
            }
        }
        cout << endl;
        
        if (password.length() < 4) {
            setConsoleColor(12);
            gotoxy(startX, inputY + 4);
            cout << "Password too short! Minimum 4 characters.";
            playSound(300, 200);
            Sleep(1000);
            gotoxy(startX, inputY + 4);
            cout << "                                          ";
            gotoxy(startX, inputY + 3);
            cout << "                                                ";
            validPassword = false;
        } else {
            validPassword = true;
        }
    } while (!validPassword);

    // Confirm password
    gotoxy(startX, inputY + 4);
    cout << "Confirm Password: ";
    
    confirmPass = "";
    char ch;
    while ((ch = _getch()) != 13) {
        if (ch == 8 && confirmPass.length() > 0) {
            confirmPass.pop_back();
            cout << "\b \b";
        } else if (ch != 8 && ch != 0 && ch != 224) {
            confirmPass += ch;
            cout << "*";
        }
    }
    cout << endl;
    
    if (password != confirmPass) {
        setConsoleColor(12);
        gotoxy(startX, inputY + 5);
        cout << "Passwords do not match! Try again.";
        playSound(300, 500);
        Sleep(1500);
        registerr();
        return;
    }

    fstream login;
    login.open("login.txt", ios::app);
    login << username << ' ' << password << endl;
    login.close();
    
    current_user = username;

    setConsoleColor(10);
    gotoxy(startX, inputY + 6);
    cout << "Registration Successful!";
    playSound(600, 150);
    playSound(800, 150);
    playSound(1000, 200);
    
    gotoxy(startX, inputY + 7);
    cout << "Redirecting to main menu...";
    Sleep(1500);
    setConsoleColor(7);
    hideConsoleCursor();
}

int navigateMenu(string options[], int numOptions, string title) {
    int selected = 0;
    int key;
    
    int boxWidth = 45;
    int startX = centerX - boxWidth / 2;
    int startY = 10;
    
    while (true) {
        setConsoleColor(14);
        printCentered(title, startY - 2);
        setConsoleColor(7);
        
        printBox(startX - 2, startY - 1, boxWidth + 4, numOptions + 2);
        
        for (int i = 0; i < numOptions; i++) {
            gotoxy(startX, startY + i);
            
            if (i == selected) {
                setConsoleColor(240); // White background, black text
                cout << " >> " << options[i] << " << ";
            } else {
                setConsoleColor(7);
                cout << "    " << options[i] << "    ";
            }
        }
        
        setConsoleColor(8);
        printCentered("[UP/DOWN: Navigate | ENTER: Select | ESC: Exit]", startY + numOptions + 2);
        setConsoleColor(7);
        
        key = _getch();
        
        if (key == 0 || key == 224) {
            key = _getch();
            
            if (key == KEY_UP) {
                selected--;
                if (selected < 0) selected = numOptions - 1;
                playSound(400, 50);
            }
            else if (key == KEY_DOWN) {
                selected++;
                if (selected >= numOptions) selected = 0;
                playSound(400, 50);
            }
        }
        else if (key == KEY_ENTER) {
            playSound(600, 100);
            return selected;
        }
        else if (key == KEY_ESC) {
            return numOptions - 1;
        }
    }
}

// Validation helper functions
bool isValidName(const char* name) {
    if (strlen(name) < 2 || strlen(name) > 20) return false;
    for (size_t i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) return false;
    }
    return true;
}

bool isValidMobile(const char* mobile) {
    if (strlen(mobile) < 10 || strlen(mobile) > 15) return false;
    for (size_t i = 0; i < strlen(mobile); i++) {
        if (!isdigit(mobile[i])) return false;
    }
    return true;
}

bool isValidEmail(const char* email) {
    string emailStr = email;
    size_t atPos = emailStr.find('@');
    size_t dotPos = emailStr.rfind('.');
    
    if (atPos == string::npos || dotPos == string::npos) return false;
    if (atPos == 0 || dotPos <= atPos + 1 || dotPos == emailStr.length() - 1) return false;
    return true;
}

bool isValidDate(const char* date) {
    // Format: DD-MM-YYYY or DD/MM/YYYY
    if (strlen(date) != 10) return false;
    if ((date[2] != '-' && date[2] != '/') || (date[5] != '-' && date[5] != '/')) return false;
    
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit(date[i])) return false;
    }
    
    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');
    int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
    
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2025) return false;
    return true;
}

class student {
public:
    int rno;
    char fname[25], lname[25], cource[30], dob[15], mo[20], addr[50], city[25], email[50];
    int sub1, sub2, sub3, sub4, sub5, sub6, total;
    float per;

    void input_details() {
        clearScreen();
        printDeveloperHeader();
        
        int startY = 5;
        int boxWidth = 70;
        int startX = centerX - boxWidth / 2;
        
        setConsoleColor(14);
        printBox(startX, startY, boxWidth, 3);
        setConsoleColor(15);
        printCentered("=== ADD NEW STUDENT RECORD ===", startY + 1);
        
        showConsoleCursor();
        int inputX = startX + 5;
        int inputY = startY + 5;
        
        // Roll Number validation
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY);
            cout << "Enter Roll No (1-9999): ";
            setConsoleColor(15);
            
            if (!(cin >> rno)) {
                cin.clear();
                cin.ignore(10000, '\n');
                rno = -1;
            }
            
            if (rno < 1 || rno > 9999) {
                setConsoleColor(12);
                gotoxy(inputX, inputY + 1);
                cout << "Invalid! Roll number must be between 1-9999.";
                playSound(300, 200);
                Sleep(1000);
                gotoxy(inputX, inputY + 1);
                cout << "                                              ";
                gotoxy(inputX, inputY);
                cout << "                                              ";
            }
        } while (rno < 1 || rno > 9999);
        
        // First Name validation
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY + 2);
            cout << "Enter First Name (letters only): ";
            setConsoleColor(15);
            cin >> fname;
            
            if (!isValidName(fname)) {
                setConsoleColor(12);
                gotoxy(inputX, inputY + 3);
                cout << "Invalid! Use 2-20 letters only.";
                playSound(300, 200);
                Sleep(1000);
                gotoxy(inputX, inputY + 3);
                cout << "                                ";
                gotoxy(inputX, inputY + 2);
                cout << "                                                    ";
            }
        } while (!isValidName(fname));
        
        // Last Name validation
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY + 4);
            cout << "Enter Last Name (letters only): ";
            setConsoleColor(15);
            cin >> lname;
            
            if (!isValidName(lname)) {
                setConsoleColor(12);
                gotoxy(inputX, inputY + 5);
                cout << "Invalid! Use 2-20 letters only.";
                playSound(300, 200);
                Sleep(1000);
                gotoxy(inputX, inputY + 5);
                cout << "                                ";
                gotoxy(inputX, inputY + 4);
                cout << "                                                    ";
            }
        } while (!isValidName(lname));
        
        // Course validation
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY + 6);
            cout << "Enter Course (e.g., BSCS, BSSE): ";
            setConsoleColor(15);
            cin >> cource;
            
            bool valid = true;
            if (strlen(cource) < 2 || strlen(cource) > 20) valid = false;
            for (size_t i = 0; i < strlen(cource) && valid; i++) {
                if (!isalnum(cource[i])) valid = false;
            }
            
            if (!valid) {
                setConsoleColor(12);
                gotoxy(inputX, inputY + 7);
                cout << "Invalid! Use alphanumeric characters.";
                playSound(300, 200);
                Sleep(1000);
                gotoxy(inputX, inputY + 7);
                cout << "                                      ";
                gotoxy(inputX, inputY + 6);
                cout << "                                                    ";
            } else {
                break;
            }
        } while (true);
        
        // Date of Birth validation
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY + 8);
            cout << "Enter Date Of Birth (DD-MM-YYYY): ";
            setConsoleColor(15);
            cin >> dob;
            
            if (!isValidDate(dob)) {
                setConsoleColor(12);
                gotoxy(inputX, inputY + 9);
                cout << "Invalid date format! Use DD-MM-YYYY.";
                playSound(300, 200);
                Sleep(1000);
                gotoxy(inputX, inputY + 9);
                cout << "                                     ";
                gotoxy(inputX, inputY + 8);
                cout << "                                                    ";
            }
        } while (!isValidDate(dob));
        
        // Mobile Number validation
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY + 10);
            cout << "Enter Mobile No (10-15 digits): ";
            setConsoleColor(15);
            cin >> mo;
            
            if (!isValidMobile(mo)) {
                setConsoleColor(12);
                gotoxy(inputX, inputY + 11);
                cout << "Invalid! Enter 10-15 digits only.";
                playSound(300, 200);
                Sleep(1000);
                gotoxy(inputX, inputY + 11);
                cout << "                                  ";
                gotoxy(inputX, inputY + 10);
                cout << "                                                    ";
            }
        } while (!isValidMobile(mo));
        
        // Address
        setConsoleColor(11);
        gotoxy(inputX, inputY + 12);
        cout << "Enter Address: ";
        setConsoleColor(15);
        cin >> addr;
        
        // City validation
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY + 13);
            cout << "Enter City (letters only): ";
            setConsoleColor(15);
            cin >> city;
            
            bool valid = true;
            for (size_t i = 0; i < strlen(city); i++) {
                if (!isalpha(city[i])) {
                    valid = false;
                    break;
                }
            }
            
            if (!valid || strlen(city) < 2) {
                setConsoleColor(12);
                gotoxy(inputX, inputY + 14);
                cout << "Invalid! Use letters only.";
                playSound(300, 200);
                Sleep(1000);
                gotoxy(inputX, inputY + 14);
                cout << "                           ";
                gotoxy(inputX, inputY + 13);
                cout << "                                                    ";
            } else {
                break;
            }
        } while (true);
        
        // Email validation
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY + 15);
            cout << "Enter Email: ";
            setConsoleColor(15);
            cin >> email;
            
            if (!isValidEmail(email)) {
                setConsoleColor(12);
                gotoxy(inputX, inputY + 16);
                cout << "Invalid email format!";
                playSound(300, 200);
                Sleep(1000);
                gotoxy(inputX, inputY + 16);
                cout << "                       ";
                gotoxy(inputX, inputY + 15);
                cout << "                                                    ";
            }
        } while (!isValidEmail(email));
        
        // Subject marks input with validation
        clearScreen();
        printDeveloperHeader();
        
        setConsoleColor(14);
        printBox(startX, startY, boxWidth, 3);
        setConsoleColor(15);
        printCentered("=== ENTER SUBJECT MARKS (0-100) ===", startY + 1);
        
        inputY = startY + 5;
        
        // Subject 1
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY);
            cout << "Programming Fundamentals: ";
            setConsoleColor(15);
            if (!(cin >> sub1)) {
                cin.clear();
                cin.ignore(10000, '\n');
                sub1 = -1;
            }
            if (sub1 < 0 || sub1 > 100) {
                setConsoleColor(12);
                gotoxy(inputX + 35, inputY);
                cout << "Invalid! (0-100)";
                playSound(300, 200);
                Sleep(800);
                gotoxy(inputX, inputY);
                cout << "                                                    ";
            }
        } while (sub1 < 0 || sub1 > 100);
        
        // Subject 2
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY + 2);
            cout << "Discrete Mathematics: ";
            setConsoleColor(15);
            if (!(cin >> sub2)) {
                cin.clear();
                cin.ignore(10000, '\n');
                sub2 = -1;
            }
            if (sub2 < 0 || sub2 > 100) {
                setConsoleColor(12);
                gotoxy(inputX + 35, inputY + 2);
                cout << "Invalid! (0-100)";
                playSound(300, 200);
                Sleep(800);
                gotoxy(inputX, inputY + 2);
                cout << "                                                    ";
            }
        } while (sub2 < 0 || sub2 > 100);
        
        // Subject 3
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY + 4);
            cout << "English: ";
            setConsoleColor(15);
            if (!(cin >> sub3)) {
                cin.clear();
                cin.ignore(10000, '\n');
                sub3 = -1;
            }
            if (sub3 < 0 || sub3 > 100) {
                setConsoleColor(12);
                gotoxy(inputX + 35, inputY + 4);
                cout << "Invalid! (0-100)";
                playSound(300, 200);
                Sleep(800);
                gotoxy(inputX, inputY + 4);
                cout << "                                                    ";
            }
        } while (sub3 < 0 || sub3 > 100);
        
        // Subject 4
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY + 6);
            cout << "Psychology: ";
            setConsoleColor(15);
            if (!(cin >> sub4)) {
                cin.clear();
                cin.ignore(10000, '\n');
                sub4 = -1;
            }
            if (sub4 < 0 || sub4 > 100) {
                setConsoleColor(12);
                gotoxy(inputX + 35, inputY + 6);
                cout << "Invalid! (0-100)";
                playSound(300, 200);
                Sleep(800);
                gotoxy(inputX, inputY + 6);
                cout << "                                                    ";
            }
        } while (sub4 < 0 || sub4 > 100);
        
        // Subject 5
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY + 8);
            cout << "ICT: ";
            setConsoleColor(15);
            if (!(cin >> sub5)) {
                cin.clear();
                cin.ignore(10000, '\n');
                sub5 = -1;
            }
            if (sub5 < 0 || sub5 > 100) {
                setConsoleColor(12);
                gotoxy(inputX + 35, inputY + 8);
                cout << "Invalid! (0-100)";
                playSound(300, 200);
                Sleep(800);
                gotoxy(inputX, inputY + 8);
                cout << "                                                    ";
            }
        } while (sub5 < 0 || sub5 > 100);
        
        // Subject 6
        do {
            setConsoleColor(11);
            gotoxy(inputX, inputY + 10);
            cout << "Calculus: ";
            setConsoleColor(15);
            if (!(cin >> sub6)) {
                cin.clear();
                cin.ignore(10000, '\n');
                sub6 = -1;
            }
            if (sub6 < 0 || sub6 > 100) {
                setConsoleColor(12);
                gotoxy(inputX + 35, inputY + 10);
                cout << "Invalid! (0-100)";
                playSound(300, 200);
                Sleep(800);
                gotoxy(inputX, inputY + 10);
                cout << "                                                    ";
            }
        } while (sub6 < 0 || sub6 > 100);
        
        total = sub1 + sub2 + sub3 + sub4 + sub5 + sub6;
        per = total / 6.0f;
        
        hideConsoleCursor();
    }

    void output_details() {
        setConsoleColor(11);
        cout << "\n  Roll No       : ";
        setConsoleColor(15);
        cout << rno;
        
        setConsoleColor(11);
        cout << "\n  Name          : ";
        setConsoleColor(15);
        cout << fname << " " << lname;
        
        setConsoleColor(11);
        cout << "\n  Course        : ";
        setConsoleColor(15);
        cout << cource;
        
        setConsoleColor(11);
        cout << "\n  Date Of Birth : ";
        setConsoleColor(15);
        cout << dob;
        
        setConsoleColor(11);
        cout << "\n  Mobile No     : ";
        setConsoleColor(15);
        cout << mo;
        
        setConsoleColor(11);
        cout << "\n  Address       : ";
        setConsoleColor(15);
        cout << addr << ", " << city;
        
        setConsoleColor(11);
        cout << "\n  Email         : ";
        setConsoleColor(15);
        cout << email;
    }

    void output_marksheet() {
        setConsoleColor(14);
        cout << "\n\n  ================= MARKSHEET =================\n";
        setConsoleColor(11);
        cout << "  Subject                          Max    Obtained\n";
        cout << "  ------------------------------------------------\n";
        setConsoleColor(7);
        cout << "  Programming Fundamentals         100        " << sub1 << endl;
        cout << "  Discrete Mathematics             100        " << sub2 << endl;
        cout << "  English                          100        " << sub3 << endl;
        cout << "  Psychology                       100        " << sub4 << endl;
        cout << "  ICT                              100        " << sub5 << endl;
        cout << "  Calculus                         100        " << sub6 << endl;
        setConsoleColor(14);
        cout << "  ------------------------------------------------\n";
        setConsoleColor(11);
        cout << "  Total                            600        " << total << endl;
        cout << "  Percentage                                  " << fixed << setprecision(2) << per << "%" << endl;

        cout << "\n  Grade: ";
        if (per >= 90) { setConsoleColor(10); cout << "A+ (Outstanding!)"; }
        else if (per >= 80) { setConsoleColor(10); cout << "A (Excellent!)"; }
        else if (per >= 70) { setConsoleColor(14); cout << "B+ (Very Good)"; }
        else if (per >= 60) { setConsoleColor(14); cout << "B (Good)"; }
        else if (per >= 50) { setConsoleColor(11); cout << "C (Average)"; }
        else if (per >= 40) { setConsoleColor(12); cout << "D (Pass)"; }
        else { setConsoleColor(12); cout << "F (Fail)"; }
        setConsoleColor(7);
    }
};

class master : public student {
public:
    void create_record() {
        input_details();
        save_to_file();
    }

    void display_records() {
        clearScreen();
        printDeveloperHeader();
        
        ifstream file("students.txt");
        if (!file) {
            setConsoleColor(12);
            printCentered("No records found in database!", centerY);
            playSound(300, 300);
            setConsoleColor(8);
            printCentered("Press any key to continue...", centerY + 3);
            _getch();
            return;
        }

        setConsoleColor(14);
        printCentered("=== ALL STUDENT RECORDS ===", 5);
        setConsoleColor(7);
        
        student s;
        int count = 0;
        int startY = 7;
        
        while (file >> s.rno >> s.fname >> s.lname >> s.cource >> s.dob >> s.mo >> s.addr >> s.city >> s.email 
                    >> s.sub1 >> s.sub2 >> s.sub3 >> s.sub4 >> s.sub5 >> s.sub6 >> s.total >> s.per) {
            
            if (count > 0 && count % 2 == 0) {
                setConsoleColor(8);
                cout << "\n\n  Press any key to see more records...";
                _getch();
                clearScreen();
                printDeveloperHeader();
                setConsoleColor(14);
                printCentered("=== ALL STUDENT RECORDS (continued) ===", 5);
            }
            
            int boxX = centerX - 40;
            gotoxy(boxX, startY + (count % 2) * 12);
            printBox(boxX, startY + (count % 2) * 12, 80, 11);
            gotoxy(boxX + 2, startY + (count % 2) * 12 + 1);
            s.output_details();
            s.output_marksheet();
            cout << "\n";
            count++;
        }
        file.close();
        
        if (count == 0) {
            setConsoleColor(12);
            printCentered("No records found!", centerY);
        } else {
            setConsoleColor(10);
            gotoxy(centerX - 15, startY + 24);
            cout << "Total Records: " << count;
        }
        
        setConsoleColor(8);
        cout << "\n\n  Press any key to continue...";
        _getch();
    }

    void save_to_file() {
        ifstream file("students.txt");
        student s;
        bool exists = false;

        while (file >> s.rno >> s.fname >> s.lname >> s.cource >> s.dob >> s.mo >> s.addr >> s.city >> s.email
                    >> s.sub1 >> s.sub2 >> s.sub3 >> s.sub4 >> s.sub5 >> s.sub6 >> s.total >> s.per) {
            if (s.rno == rno) {
                exists = true;
                break;
            }
        }
        file.close();

        clearScreen();
        printDeveloperHeader();

        if (exists) {
            setConsoleColor(12);
            printCentered("*** ERROR ***", centerY - 2);
            printCentered("A record with this roll number already exists!", centerY);
            playSound(300, 500);
        } else {
            ofstream outFile("students.txt", ios::app);
            outFile << rno << " " << fname << " " << lname << " " << cource << " " << dob << " " << mo << " "
                    << addr << " " << city << " " << email << " " << sub1 << " " << sub2 << " " << sub3 << " "
                    << sub4 << " " << sub5 << " " << sub6 << " " << total << " " << per << "\n";
            outFile.close();
            
            setConsoleColor(10);
            printCentered("*** SUCCESS ***", centerY - 2);
            printCentered("Record saved successfully!", centerY);
            playSound(800, 200);
            playSound(1000, 200);
        }
        
        setConsoleColor(8);
        printCentered("Press any key to continue...", centerY + 3);
        _getch();
    }

    void update_record(int roll_no) {
        ifstream file("students.txt");
        ofstream temp("temp.txt");
        
        if (!file) {
            clearScreen();
            printDeveloperHeader();
            setConsoleColor(12);
            printCentered("No records found!", centerY);
            playSound(300, 300);
            setConsoleColor(8);
            printCentered("Press any key to continue...", centerY + 3);
            _getch();
            return;
        }

        student s;
        bool found = false;
        
        while (file >> s.rno >> s.fname >> s.lname >> s.cource >> s.dob >> s.mo >> s.addr >> s.city >> s.email 
                    >> s.sub1 >> s.sub2 >> s.sub3 >> s.sub4 >> s.sub5 >> s.sub6 >> s.total >> s.per) {
            if (s.rno == roll_no) {
                clearScreen();
                printDeveloperHeader();
                
                setConsoleColor(14);
                printCentered("=== CURRENT STUDENT DETAILS ===", 5);
                
                int boxX = centerX - 40;
                printBox(boxX, 7, 80, 11);
                gotoxy(boxX + 2, 8);
                s.output_details();
                s.output_marksheet();
                
                setConsoleColor(14);
                gotoxy(centerX - 20, 20);
                cout << "Press any key to enter new details...";
                _getch();
                
                input_details();
                temp << rno << " " << fname << " " << lname << " " << cource << " " << dob << " " << mo << " "
                     << addr << " " << city << " " << email << " " << sub1 << " " << sub2 << " " << sub3 << " "
                     << sub4 << " " << sub5 << " " << sub6 << " " << total << " " << per << "\n";
                found = true;
            } else {
                temp << s.rno << " " << s.fname << " " << s.lname << " " << s.cource << " " << s.dob << " " << s.mo << " "
                     << s.addr << " " << s.city << " " << s.email << " " << s.sub1 << " " << s.sub2 << " " << s.sub3 << " "
                     << s.sub4 << " " << s.sub5 << " " << s.sub6 << " " << s.total << " " << s.per << "\n";
            }
        }

        file.close();
        temp.close();
        remove("students.txt");
        rename("temp.txt", "students.txt");

        clearScreen();
        printDeveloperHeader();
        
        if (found) {
            setConsoleColor(10);
            printCentered("*** SUCCESS ***", centerY - 2);
            printCentered("Record updated successfully!", centerY);
            playSound(800, 200);
            playSound(1000, 200);
        } else {
            setConsoleColor(12);
            printCentered("*** ERROR ***", centerY - 2);
            printCentered("Record not found!", centerY);
            playSound(300, 500);
        }
        
        setConsoleColor(8);
        printCentered("Press any key to continue...", centerY + 3);
        _getch();
    }
    
    void delete_record(int roll_no) {
        ifstream file("students.txt");
        ofstream temp("temp.txt");
        
        if (!file) {
            clearScreen();
            printDeveloperHeader();
            setConsoleColor(12);
            printCentered("No records found!", centerY);
            playSound(300, 300);
            setConsoleColor(8);
            printCentered("Press any key to continue...", centerY + 3);
            _getch();
            return;
        }

        student s;
        bool found = false;
        
        while (file >> s.rno >> s.fname >> s.lname >> s.cource >> s.dob >> s.mo >> s.addr >> s.city >> s.email 
                    >> s.sub1 >> s.sub2 >> s.sub3 >> s.sub4 >> s.sub5 >> s.sub6 >> s.total >> s.per) {
            if (s.rno == roll_no) {
                found = true;
                // Show the record being deleted
                clearScreen();
                printDeveloperHeader();
                setConsoleColor(12);
                printCentered("=== RECORD TO BE DELETED ===", 5);
                
                int boxX = centerX - 40;
                printBox(boxX, 7, 80, 11);
                gotoxy(boxX + 2, 8);
                s.output_details();
                
                setConsoleColor(14);
                gotoxy(centerX - 25, 20);
                cout << "Are you sure you want to delete? (Y/N): ";
                showConsoleCursor();
                char confirm;
                cin >> confirm;
                hideConsoleCursor();
                
                if (confirm == 'Y' || confirm == 'y') {
                    continue; // Skip writing this record
                } else {
                    temp << s.rno << " " << s.fname << " " << s.lname << " " << s.cource << " " << s.dob << " " << s.mo << " "
                         << s.addr << " " << s.city << " " << s.email << " " << s.sub1 << " " << s.sub2 << " " << s.sub3 << " "
                         << s.sub4 << " " << s.sub5 << " " << s.sub6 << " " << s.total << " " << s.per << "\n";
                    found = false; // User cancelled
                }
            } else {
                temp << s.rno << " " << s.fname << " " << s.lname << " " << s.cource << " " << s.dob << " " << s.mo << " "
                     << s.addr << " " << s.city << " " << s.email << " " << s.sub1 << " " << s.sub2 << " " << s.sub3 << " "
                     << s.sub4 << " " << s.sub5 << " " << s.sub6 << " " << s.total << " " << s.per << "\n";
            }
        }

        file.close();
        temp.close();
        remove("students.txt");
        rename("temp.txt", "students.txt");

        clearScreen();
        printDeveloperHeader();
        
        if (found) {
            setConsoleColor(10);
            printCentered("*** SUCCESS ***", centerY - 2);
            printCentered("Record deleted successfully!", centerY);
            playSound(600, 200);
            playSound(800, 200);
        } else {
            setConsoleColor(12);
            printCentered("*** ERROR / CANCELLED ***", centerY - 2);
            printCentered("Record not found or deletion cancelled!", centerY);
            playSound(300, 500);
        }
        
        setConsoleColor(8);
        printCentered("Press any key to continue...", centerY + 3);
        _getch();
    }
    
    void search_record(int roll_no) {
        ifstream file("students.txt");
        
        if (!file) {
            clearScreen();
            printDeveloperHeader();
            setConsoleColor(12);
            printCentered("No records found in database!", centerY);
            playSound(300, 300);
            setConsoleColor(8);
            printCentered("Press any key to continue...", centerY + 3);
            _getch();
            return;
        }

        student s;
        bool found = false;
        
        while (file >> s.rno >> s.fname >> s.lname >> s.cource >> s.dob >> s.mo >> s.addr >> s.city >> s.email 
                    >> s.sub1 >> s.sub2 >> s.sub3 >> s.sub4 >> s.sub5 >> s.sub6 >> s.total >> s.per) {
            if (s.rno == roll_no) {
                found = true;
                clearScreen();
                printDeveloperHeader();
                
                setConsoleColor(10);
                printCentered("*** RECORD FOUND ***", 5);
                
                int boxX = centerX - 40;
                printBox(boxX, 7, 80, 18);
                gotoxy(boxX + 2, 8);
                s.output_details();
                s.output_marksheet();
                
                playSound(800, 200);
                playSound(1000, 200);
                break;
            }
        }
        file.close();

        if (!found) {
            clearScreen();
            printDeveloperHeader();
            setConsoleColor(12);
            printCentered("*** RECORD NOT FOUND ***", centerY - 2);
            printCentered("No student with this roll number exists!", centerY);
            playSound(300, 500);
        }
        
        setConsoleColor(8);
        printCentered("Press any key to continue...", centerY + 5);
        _getch();
    }
    
    void display_statistics() {
        ifstream file("students.txt");
        
        if (!file) {
            clearScreen();
            printDeveloperHeader();
            setConsoleColor(12);
            printCentered("No records found in database!", centerY);
            playSound(300, 300);
            setConsoleColor(8);
            printCentered("Press any key to continue...", centerY + 3);
            _getch();
            return;
        }

        student s;
        int count = 0;
        float totalPer = 0;
        float maxPer = 0;
        float minPer = 100;
        int passCount = 0;
        int failCount = 0;
        string topStudent = "";
        
        while (file >> s.rno >> s.fname >> s.lname >> s.cource >> s.dob >> s.mo >> s.addr >> s.city >> s.email 
                    >> s.sub1 >> s.sub2 >> s.sub3 >> s.sub4 >> s.sub5 >> s.sub6 >> s.total >> s.per) {
            count++;
            totalPer += s.per;
            
            if (s.per > maxPer) {
                maxPer = s.per;
                topStudent = string(s.fname) + " " + string(s.lname);
            }
            if (s.per < minPer) minPer = s.per;
            
            if (s.per >= 40) passCount++;
            else failCount++;
        }
        file.close();

        clearScreen();
        printDeveloperHeader();
        
        int boxWidth = 60;
        int startX = centerX - boxWidth / 2;
        int startY = 6;
        
        setConsoleColor(14);
        printBox(startX, startY, boxWidth, 16);
        
        setConsoleColor(15);
        printCentered("=== DATABASE STATISTICS ===", startY + 1);
        
        setConsoleColor(11);
        gotoxy(startX + 5, startY + 4);
        cout << "Total Students        : ";
        setConsoleColor(15);
        cout << count;
        
        setConsoleColor(11);
        gotoxy(startX + 5, startY + 6);
        cout << "Average Percentage    : ";
        setConsoleColor(15);
        cout << fixed << setprecision(2) << (count > 0 ? totalPer / count : 0) << "%";
        
        setConsoleColor(11);
        gotoxy(startX + 5, startY + 8);
        cout << "Highest Percentage    : ";
        setConsoleColor(10);
        cout << maxPer << "% (" << topStudent << ")";
        
        setConsoleColor(11);
        gotoxy(startX + 5, startY + 10);
        cout << "Lowest Percentage     : ";
        setConsoleColor(12);
        cout << minPer << "%";
        
        setConsoleColor(11);
        gotoxy(startX + 5, startY + 12);
        cout << "Students Passed       : ";
        setConsoleColor(10);
        cout << passCount;
        
        setConsoleColor(11);
        gotoxy(startX + 5, startY + 14);
        cout << "Students Failed       : ";
        setConsoleColor(12);
        cout << failCount;
        
        playSound(600, 100);
        playSound(800, 100);
        playSound(1000, 100);
        
        setConsoleColor(8);
        printCentered("Press any key to continue...", startY + 18);
        _getch();
    }
};

void mainMenu() {
    master ms;
    
    string menuOptions[] = {
        "  Add New Student Record      ",
        "  Display All Records         ",
        "  Search Student by Roll No   ",
        "  Update Student Record       ",
        "  Delete Student Record       ",
        "  View Statistics             ",
        "  Logout & Exit               "
    };
    int numOptions = 7;
    
    while (true) {
        clearScreen();
        printDeveloperHeader();
        
        setConsoleColor(11);
        gotoxy(screenWidth - 25, 1);
        cout << "Logged in as: " << current_user;
        
        int choice = navigateMenu(menuOptions, numOptions, "=== MAIN MENU ===");
        
        int roll_no;
        
        switch (choice) {
            case 0:
                ms.create_record();
                break;
                
            case 1:
                ms.display_records();
                break;
                
            case 2:
                clearScreen();
                printDeveloperHeader();
                setConsoleColor(14);
                printCentered("=== SEARCH STUDENT ===", 8);
                showConsoleCursor();
                setConsoleColor(11);
                gotoxy(centerX - 20, 12);
                cout << "Enter Roll Number to Search: ";
                setConsoleColor(15);
                while (!(cin >> roll_no) || roll_no < 1) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    setConsoleColor(12);
                    gotoxy(centerX - 15, 14);
                    cout << "Invalid! Enter a valid roll number.";
                    playSound(300, 200);
                    Sleep(1000);
                    gotoxy(centerX - 15, 14);
                    cout << "                                    ";
                    gotoxy(centerX - 20, 12);
                    cout << "Enter Roll Number to Search:                ";
                    gotoxy(centerX + 9, 12);
                }
                hideConsoleCursor();
                ms.search_record(roll_no);
                break;
                
            case 3:
                clearScreen();
                printDeveloperHeader();
                setConsoleColor(14);
                printCentered("=== UPDATE STUDENT ===", 8);
                showConsoleCursor();
                setConsoleColor(11);
                gotoxy(centerX - 20, 12);
                cout << "Enter Roll Number to Update: ";
                setConsoleColor(15);
                while (!(cin >> roll_no) || roll_no < 1) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    setConsoleColor(12);
                    gotoxy(centerX - 15, 14);
                    cout << "Invalid! Enter a valid roll number.";
                    playSound(300, 200);
                    Sleep(1000);
                    gotoxy(centerX - 15, 14);
                    cout << "                                    ";
                    gotoxy(centerX - 20, 12);
                    cout << "Enter Roll Number to Update:                ";
                    gotoxy(centerX + 9, 12);
                }
                hideConsoleCursor();
                ms.update_record(roll_no);
                break;
                
            case 4:
                clearScreen();
                printDeveloperHeader();
                setConsoleColor(14);
                printCentered("=== DELETE STUDENT ===", 8);
                showConsoleCursor();
                setConsoleColor(11);
                gotoxy(centerX - 20, 12);
                cout << "Enter Roll Number to Delete: ";
                setConsoleColor(15);
                while (!(cin >> roll_no) || roll_no < 1) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    setConsoleColor(12);
                    gotoxy(centerX - 15, 14);
                    cout << "Invalid! Enter a valid roll number.";
                    playSound(300, 200);
                    Sleep(1000);
                    gotoxy(centerX - 15, 14);
                    cout << "                                    ";
                    gotoxy(centerX - 20, 12);
                    cout << "Enter Roll Number to Delete:                ";
                    gotoxy(centerX + 9, 12);
                }
                hideConsoleCursor();
                ms.delete_record(roll_no);
                break;
                
            case 5:
                ms.display_statistics();
                break;
                
            case 6:
                clearScreen();
                printDeveloperHeader();
                
                setConsoleColor(10);
                printCentered("T H A N K S   F O R   U S I N G", centerY - 2);
                setConsoleColor(14);
                printCentered("STUDENT MANAGEMENT SYSTEM", centerY);
                setConsoleColor(11);
                printCentered("Goodbye, " + current_user + "!", centerY + 2);
                setConsoleColor(8);
                printCentered("S E E   Y O U   N E X T   T I M E !", centerY + 4);
                
                playSound(523, 200);
                playSound(659, 200);
                playSound(784, 400);
                
                Sleep(2500);
                clearScreen();
                showConsoleCursor();
                exit(0);
                
            default:
                setConsoleColor(12);
                printCentered("Invalid choice!", centerY);
                playSound(300, 300);
                Sleep(1000);
        }
    }
}

int main() {
    setConsoleSize();
    hideConsoleCursor();
    printheadermenu();
    clearScreen();
    printCentered("Initializing System...", centerY);
    playSound(500, 200);
    Sleep(1000);
    clearScreen();
    printloginmenu();
    loginn();
    clearScreen();
    mainMenu();
    return 0;
}
