#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[100];
    int roll;
    float marks;
};

void addStudent();
void viewStudent();

int main() {
    int choice;
    
    do {
        printf("\n<------ Student Record System ------>\n");
        printf("1) Add Student Record\n");
        printf("2) View Student Records\n");
        printf("3) Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudent();
                break;
            case 3:
                printf("Program Exited Successfully!\n");
                break;
            default:
                printf("Invalid Choice, Try again!\n");
        }
    } while (choice != 3);

    return 0;
}

void addStudent() {
    FILE *fptr;
    struct student s;

    fptr = fopen("student.txt", "a");
    if (fptr == NULL) {
        printf("Error in opening the File!\n");
        exit(1);
    }

    printf("Enter your Name: ");
    scanf("%s", s.name);
    printf("Enter your Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter your Marks: ");
    scanf("%f", &s.marks);

    fprintf(fptr, "%d %s %.2f\n", s.roll, s.name, s.marks);
    fclose(fptr);

    printf("Record added successfully!\n");
    printf("-----------------------------------\n");
}

void viewStudent() {
    FILE *fptr;
    struct student s;

    fptr = fopen("student.txt", "r");
    if (fptr == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n<----- Student Records ----->\n");
    while (fscanf(fptr, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", s.roll, s.name, s.marks);
        printf("-----------------------------------\n");
    }

    fclose(fptr);
}
