# Example Usage Guide

## Quick Start Example

Here's a complete walkthrough of using the Student Management System:

### Step 1: Add Students

```
Menu Option: 1 (Add New Student)
Name: Alice Johnson
Age: 20
Result: Student added with ID 1001

Menu Option: 1 (Add New Student)
Name: Bob Smith
Age: 22
Result: Student added with ID 1002
```

### Step 2: Add Courses

```
Menu Option: 6 (Add Course to Student)
Student ID: 1001
Course Name: Mathematics
Result: Course added successfully

Menu Option: 6
Student ID: 1001
Course Name: Physics
Result: Course added successfully

Menu Option: 6
Student ID: 1002
Course Name: Computer Science
Result: Course added successfully
```

### Step 3: Add Grades

```
Menu Option: 7 (Add Grade to Student)
Student ID: 1001
Grade: 95
Result: Grade added successfully

Menu Option: 7
Student ID: 1001
Grade: 88
Result: Grade added successfully

Menu Option: 7
Student ID: 1002
Grade: 92
Result: Grade added successfully
```

### Step 4: View Student Details

```
Menu Option: 3 (Search Student by ID)
Student ID: 1001

Output:
┌─────────────────────────────────────────────────────┐
│ Student ID: 1001                                 │
│ Name:       Alice Johnson                        │
│ Age:        20                                   │
├─────────────────────────────────────────────────────┤
│ Courses:                                            │
│   1. Mathematics                                  │
│   2. Physics                                      │
├─────────────────────────────────────────────────────┤
│ Grades:                                             │
│   Mathematics                                    │
│     Score: 95.00                                 │
│   Physics                                        │
│     Score: 88.00                                 │
├─────────────────────────────────────────────────────┤
│ Average: 91.50                                    │
│ GPA:     4.00                                     │
└─────────────────────────────────────────────────────┘
```

### Step 5: View All Students

```
Menu Option: 2 (View All Students)

Output: Displays all registered students with their complete information
```

### Step 6: Display Statistics

```
Menu Option: 8 (Display Statistics)

Output:
┌─────────────────────────────────────────────────────┐
│ Total Students:     2                           │
│ Class Average:      91.75                       │
│ Highest Scorer:     Alice Johnson               │
│   Score:            91.50                       │
│ Lowest Scorer:      Bob Smith                   │
│   Score:            92.00                       │
├─────────────────────────────────────────────────────┤
│ Students with grades: 2                         │
│ Grade A (90-100):     2                         │
│ Grade B (80-89):      0                         │
│ Grade C (70-79):      0                         │
└─────────────────────────────────────────────────────┘
```

### Step 7: Search by Name

```
Menu Option: 9 (Search Students by Name)
Name: Alice

Output: Shows all students matching "Alice"
```

### Step 8: Update Student Information

```
Menu Option: 4 (Update Student Information)
Student ID: 1001
New Name: Alice J. Johnson (or Enter to keep current)
New Age: 21 (or 0 to keep current)
Result: Student updated successfully
```

### Step 9: View Performance Groups

```
Menu Option: 10 (View Students Above Average)
Output: Shows students performing above class average

Menu Option: 11 (View Students Below Average)
Output: Shows students performing below class average
```

### Step 10: Save and Exit

```
Menu Option: 12 (Save Data)
Result: Data saved successfully to students.dat

Menu Option: 0 (Exit)
Result: Data automatically saved, program exits
```

## Advanced Features

### Batch Operations

You can perform multiple operations in sequence:
1. Add multiple students
2. Add courses for all students
3. Add grades for all courses
4. View comprehensive statistics

### Data Persistence

- Data is saved to `students.dat`
- On next run, all data is automatically loaded
- Manual save option available (Menu option 12)
- Auto-save on exit

### Search Capabilities

1. **Search by ID**: Exact match search for specific student
2. **Search by Name**: Partial match, case-insensitive
3. **Filter by Performance**: Above/below class average

### Statistics Features

The system provides:
- Total student count
- Class average score
- Highest scorer identification
- Lowest scorer identification
- Grade distribution (A/B/C counts)
- Students with/without grades

## Tips

1. **Student IDs**: Auto-generated starting from 1001
2. **Grade Range**: Valid grades are 0-100
3. **Age Range**: Valid ages are 1-100
4. **GPA Scale**: 0.0-4.0 scale
5. **Case Sensitivity**: Name searches are case-insensitive
6. **Data Safety**: Always use option 12 to save before system crashes

## Error Handling

The system handles:
- Invalid menu choices
- Student not found errors
- Invalid grade ranges
- Invalid age ranges
- File I/O errors
- Empty system operations

All errors are displayed with ✗ symbol and clear messages.
