#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int rollNumber;
    float marks;
    int attendance;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount < MAX_STUDENTS) {
        printf("Enter student's name: ");
        scanf(" %[^\n]s", students[studentCount].name);
        printf("Enter roll number: ");
        scanf("%d", &students[studentCount].rollNumber);
        printf("Enter marks: ");
        scanf("%f", &students[studentCount].marks);
        printf("Enter attendance (in days): ");
        scanf("%d", &students[studentCount].attendance);
        studentCount++;
        printf("Student added successfully!\n\n");
    } else {
        printf("Student record is full!\n\n");
    }
}

void viewStudents() {
    if (studentCount == 0) {
        printf("No students found!\n\n");
    } else {
        printf("Student Records:\n");
        for (int i = 0; i < studentCount; i++) {
            printf("Name: %s | Roll No: %d | Marks: %.2f | Attendance: %d days\n",
                   students[i].name, students[i].rollNumber,
                   students[i].marks, students[i].attendance);
        }
        printf("\n");
    }
}

void calculateGrade() {
    for (int i = 0; i < studentCount; i++) {
        char grade;
        if (students[i].marks >= 90) grade = 'A';
        else if (students[i].marks >= 75) grade = 'B';
        else if (students[i].marks >= 50) grade = 'C';
        else grade = 'D';
        printf("Student: %s | Marks: %.2f | Grade: %c\n",
               students[i].name, students[i].marks, grade);
    }
    printf("\n");
}

void showAnnouncements() {
    printf("Announcements:\n");
    printf("1. Semester exams begin on 15th Dec.\n");
    printf("2. Submit assignments by 10th Dec.\n");
    printf("3. Winter vacation starts from 24th Dec.\n");
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("Academic Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Calculate Grades\n");
        printf("4. Show Announcements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                calculateGrade();
                break;
            case 4:
                showAnnouncements();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Try again.\n\n");
        }
    }
    return 0:
}
