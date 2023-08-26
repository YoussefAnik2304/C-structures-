#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Department {
    HR,
    Sales,
    Research,
    Software,
    Executive
};

struct Employee {
    enum Department department;
    int annualSalary;
    unsigned int socialSecurityNumber;
};

int generateSalaryOffset() {
    return rand() % 1000 + 500; // Random offset between 500 and 1500
}

int generateSalary(enum Department department) {
    int baseSalary;
    switch (department) {
        case HR:
            baseSalary = 40000;
            break;
        case Sales:
            baseSalary = 50000;
            break;
        case Research:
            baseSalary = 55000;
            break;
        case Software:
            baseSalary = 75000;
            break;
        case Executive:
            baseSalary = 100000;
            break;
        default:
            baseSalary = 0;
            break;
    }
    return baseSalary + generateSalaryOffset();
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    struct Employee employees[10];

    for (int i = 0; i < 10; ++i) {
        employees[i].department = rand() % 5; // Random department
        employees[i].annualSalary = generateSalary(employees[i].department);
        employees[i].socialSecurityNumber = 100000000 + i; // Just an example scheme for generating SSNs
    }

    // Print employee information
    char *departmentNames[] = {"HR", "Sales", "Research", "Software", "Executive"};
    for (int i = 0; i < 10; ++i) {
        printf("Department: %s, Salary: $%d, SSN: %u\n", departmentNames[employees[i].department],
               employees[i].annualSalary, employees[i].socialSecurityNumber);
    }

    return 0;
}
