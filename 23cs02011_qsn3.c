#include <stdio.h>
#include <string.h>
// Define a union named EmpDetails
union EmpDetails {
    float hourlyWage;
    double fixedSalary;
};

// Define a structure named Employee
struct Employee {
    int id;
    char name[50];
    union EmpDetails details;
};

int main() {
   
    struct Employee emp;

    
    emp.id = 101;
    strcpy(emp.name, "John Doe"); 
    emp.details.hourlyWage = 15.50; 
    // emp.details.fixedSalary = 50000.00; // Uncomment this line to assign fixed salary

    
    printf("Employee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Employee Hourly Wage: %.2f\n", emp.details.hourlyWage);
    // printf("Employee Fixed Salary: %.2f\n", emp.details.fixedSalary); // Uncomment this line to print fixed salary

    return 0;
}
// when you need only one entity at a time. and for better memory allocation or to conserve the memory