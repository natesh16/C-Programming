#include <stdio.h>
#include <string.h>
struct Student {
    int id;
    char name[50];
    float gpa;
};
void addStudent(struct Student students[], int *count) {
    printf("Enter student ID: ");
    scanf("%d", &students[*count].id);
    printf("Enter student name: ");
    scanf("%s", students[*count].name);
    printf("Enter student GPA: ");
    scanf("%f", &students[*count].gpa);

    (*count)++;
    printf("Student added successfully!\n");
}
void displayStudents(struct Student students[], int count) {
    printf("\nStudent Information:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}
void searchStudent(struct Student students[], int count) {
    int searchID;
    printf("Enter student ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < count; i++) {
        if (students[i].id == searchID) {
            printf("Student found!\n");
            printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
            return;
        }
    }

    printf("Student not found.\n");
}

int main() {
    struct Student students[100]; // Assuming a maximum of 100 students
    int count = 0;
    int choice;

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
