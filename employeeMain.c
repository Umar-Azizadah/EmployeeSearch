// Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c

// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    // defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *phoneToFind); 
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    // defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;  // Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    // Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");


    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-1235");

    if (matchPtr != NULL) // checks if the pointer is not null, meaning it found a match
        printf("Employee with phone number 909-555-1235 is in record %d\n", matchPtr - EmployeeTable); // prints the index of the employee in the array
    else
        printf("Employee with phone number 909-555-1235 is NOT found in the record\n"); // if no match is found, print this message
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "123-456-1235");
    if (matchPtr != NULL) // checks if the pointer is not null, meaning it found a match
        printf("Employee with phone number 123-456-1235 is in record %d\n", matchPtr - EmployeeTable); // prints the index of the employee in the array
    else
        printf("Employee with phone number 123-456-1235 is NOT found in the record\n"); // if no match is found, print this message

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32); //searches for an employee with a salary of 8.32

    if (matchPtr != NULL) // checks if the pointer is not null, meaning it found a match
        printf("Employee with salary 8.32 is in record %d\n", matchPtr - EmployeeTable); // prints the index of the employee in the array
    else
        printf("Employee with salary 8.32 is NOT found in the record\n"); // if no match is found, print this message
    
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 10.00); //searches for an employee with a salary of 10.00 which does not exist

    if(matchPtr != NULL) // checks if the pointer is not null, meaning it found a match
        printf("Employee with salary 10.00 is in record %d\n", matchPtr - EmployeeTable); // prints the index of the employee in the array
    else
        printf("Employee with salary 10.00 is NOT found in the record\n"); // if no match is found, print this message
    return EXIT_SUCCESS;
}
