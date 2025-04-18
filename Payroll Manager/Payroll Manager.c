/*
   Programmer: Gabriel ROdriguez
   Date: 03/28/2025
   Purpose: Payroll Management program. Allows user to add payroll records, display paycheck stubs,
   and display total payroll clearly and efficiently.
 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Struct_B_payrollheader.Gabriel_Rodriguez.h"

// Function prototypes
void displayMenu();
char getMenuChoice();
#include <string.h>

// Function prototypes for validation
int validateAge(int age);
int validateHourlyRate(float rate);
int validateHoursWorked(float hours);
int validateDate(DATE date) {
    // Temporary simple validation
    if (date.month < 1 || date.month > 12) return 0;
    if (date.day < 1 || date.day > 31) return 0;
    if (date.year < 1900 || date.year > 2100) return 0;
    return 1;
}
void inputPayrollRecord(PAYRECORD payroll[], int* recordCount) {
    if (*recordCount >= 100) {
        printf("Cannot add more payroll records (limit reached).\n");
        return;
    }

    PAYRECORD temp;

    // Input name
    printf("Enter employee name: ");
    (void)scanf(" %[^\n]", temp.name);

    // Input and validate age
    do {
        printf("Enter age (18-120): ");
        (void)scanf("%d", &temp.age);
        if (!validateAge(temp.age))
            printf("Invalid age. Try again!\n");
    } while (!validateAge(temp.age));

    // Input and validate hourly wage
    do {
        printf("Enter hourly wage (>0 and <500): ");
        (void)scanf("%f", &temp.hrlyWage);
        if (!validateHourlyRate(temp.hrlyWage))
            printf("Invalid hourly wage. Try again!\n");
    } while (!validateHourlyRate(temp.hrlyWage));

    // Input and validate hours worked
    do {
        printf("Enter hours worked (>0 and <100): ");
        (void)scanf("%f", &temp.hrsWorked);
        if (!validateHoursWorked(temp.hrsWorked))
            printf("Invalid hours worked. Try again!\n");
    } while (!validateHoursWorked(temp.hrsWorked));

    // Input and validate pay date (reuse your previous code here)
    do {
        printf("Enter pay date (mm dd yyyy): ");
        (void)scanf("%d %d %d", &temp.payDate.month, &temp.payDate.day, &temp.payDate.year);
        if (!validateDate(temp.payDate))
            printf("Invalid date. Try again!\n");
    } while (!validateDate(temp.payDate));

    // Calculate pay clearly (your logic)
    if (temp.hrsWorked <= 40) {
        temp.regPay = temp.hrsWorked * temp.hrlyWage;
        temp.otPay = 0;
    }
    else {
        temp.regPay = 40 * temp.hrlyWage;
        temp.otPay = (temp.hrsWorked - 40) * temp.hrlyWage * 1.5f; // added 'f' to clearly indicate float
    }
    temp.totalPay = temp.regPay + temp.otPay;

    // Store record
    payroll[*recordCount] = temp;
    (*recordCount)++;

    printf("Payroll record added successfully!\n");
}

// Validation functions clearly:

int validateAge(int age) {
    return (age >= 18 && age <= 120);
}

int validateHourlyRate(float rate) {
    return (rate > 0 && rate < 500);
}

int validateHoursWorked(float hours) {
    return (hours > 0 && hours < 100);
}

// Implement validateDate based on your previous assignment clearly!
static void displayAllPayStubs(const PAYRECORD payroll[], int recordCount) {
    printf("\n*** Paycheck Stubs ***\n");
    for (int i = 0; i < recordCount; i++) {
        printf("\nEmployee #%d:\n", i + 1);
        printf("Name: %s\n", payroll[i].name);
        printf("Age: %d\n", payroll[i].age);
        printf("Hourly Wage: $%.2f\n", payroll[i].hrlyWage);
        printf("Hours Worked: %.2f\n", payroll[i].hrsWorked);
        printf("Regular Pay: $%.2f\n", payroll[i].regPay);
        printf("Overtime Pay: $%.2f\n", payroll[i].otPay);
        printf("Total Pay: $%.2f\n", payroll[i].totalPay);
        printf("Pay Date: %02d/%02d/%04d\n",
            payroll[i].payDate.month, payroll[i].payDate.day, payroll[i].payDate.year);
    }

    if (recordCount == 0) {
        printf("No records available!\n");
    }
}
static void displayTotalPayroll(const PAYRECORD payroll[], int recordCount) {
    float totalGross = 0;

    for (int i = 0; i < recordCount; i++) {
        totalGross += payroll[i].totalPay;
    }

    printf("\n*** Total Payroll ***\n");
    printf("Total payroll amount for all employees: $%.2f\n", totalGross);
}

int main() {
    PAYRECORD payroll[100]; // array to store payroll records
    int recordCount = 0; // how many records are stored
    char choice;

    do {
        displayMenu();
        choice = getMenuChoice();

        switch (choice) {
        case 'A':
            inputPayrollRecord(payroll, &recordCount);
            break;

        case 'B':
            displayAllPayStubs(payroll, recordCount);
            break;


        case 'C':
            displayTotalPayroll(payroll, recordCount);
            break;

        case 'D':
            printf("Quitting program...\n");
            break;

        default:
            printf("Invalid choice. Try again!\n");
        }

    } while (choice != 'D');

    return 0;
}

// Definitions for the simple functions:

void displayMenu() {
    printf("\nMENU:\n");
    printf("A. Enter payroll record\n");
    printf("B. Display all paycheck stubs\n");
    printf("C. Display total payroll\n");
    printf("D. Quit\n");
}

char getMenuChoice() {
    char c;
    printf("Enter your choice: ");
    (void)scanf(" %c", &c);
    return c;
}
