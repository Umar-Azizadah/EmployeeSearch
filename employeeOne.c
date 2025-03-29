#include <string.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber) {
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++)  // search until end of table
    {
        if (ptr->number == targetNumber)  // check if it equals the Employee number
            return (PtrToEmployee) ptr;  // return location of the number to callee.
    }

    return NULL;  // this will only happen if no Employee number matches in loop above
}

// Essentially the same functionality as above but comparing strings to check if equal
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName) {
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++) {
        if (strcmp(ptr->name, targetName) == 0)
            return (PtrToEmployee) ptr;
    }

    return NULL;
}

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tablesize, char *targetPhone) {
    const PtrToConstEmployee endptr = ptr + tablesize;

    for (; ptr <endptr; ptr++) {
        if(strcmp(ptr->phone, targetPhone) == 0) //checks if the phone number matches the target phone number
            return (PtrToEmployee) ptr; 
    }

    return NULL; // this will only happen if no phone number matches in loop above

} 

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tablesize, double targetSalary) {
    const PtrToConstEmployee endptr = ptr + tablesize;

    for (; ptr < endptr; ptr++) {
        if (ptr->salary == targetSalary) //checks if the salary matches the target salary
            return (PtrToEmployee) ptr; 
    }

    return NULL; //this will only happen if no salary matches in loop above
}



