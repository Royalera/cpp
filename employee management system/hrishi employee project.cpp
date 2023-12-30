#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 100

struct Employee {
    int employeeID;
    char name[MAX_NAME_LENGTH];
    int age;
    double salary;
    int phone;
    char post[50];
    char department[50];
};

struct Employee database[MAX_EMPLOYEES];
int numEmployees = 0;

void addEmployee() {
    if (numEmployees >= MAX_EMPLOYEES) {
        printf("Database is full. Cannot add more employees.\n");
        return;
    }

    struct Employee emp;

    printf("Enter employee ID (6 digits): ");
    scanf("%d", &emp.employeeID);

    printf("Enter name: ");
    scanf("%s", emp.name);

    printf("Enter age: ");
    scanf("%d", &emp.age);

    printf("Enter salary: ");
    scanf("%lf", &emp.salary);

    printf("Enter phone number: ");
    scanf("%s", &emp.phone);

    printf("Enter post: ");
    scanf("%s", emp.post);

    printf("Enter department: ");
    scanf("%s", emp.department);

    database[numEmployees] = emp;
    numEmployees++;

    printf("Employee added successfully.\n");
}

void displayEmployees() {
    if (numEmployees == 0) {
        printf("Database is empty.\n");
        return;
    }

    printf("Employee Database:\n");
    int i;
    for (i = 0; i < numEmployees; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f, Post: %s, Department: %s\n",
               database[i].name, database[i].age, database[i].salary, database[i].post, database[i].department);
    }
}

void backupToExcel() {
    FILE *file = fopen("employee_database.csv", "w");

    if (file == NULL) {
        printf("Error creating backup file.\n");
        return;
    }

    fprintf(file, "Name,Age,Salary,Post,Department\n");
    int i;
    for (i = 0; i < numEmployees; i++) {
        fprintf(file, "%s,%d,%.2f,%s,%s\n",
                database[i].name, database[i].age, database[i].salary, database[i].post, database[i].department);
    }

    fclose(file);

    printf("Backup created successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nEmployee Database Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Backup to Excel\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                backupToExcel();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

