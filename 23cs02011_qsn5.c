#include <stdio.h>
#include <string.h>


enum PayType {
    HOURLY,
    SALARY
};


union EmpDetails {
    struct {
        float hourlyWage;
        enum PayType payType; // Added PayType enumeration
    } hourlyDetails;
    struct {
        double fixedSalary;
        enum PayType payType; 
    } salaryDetails;
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
    
    
    emp.details.hourlyDetails.hourlyWage = 15.50;
    emp.details.hourlyDetails.payType = HOURLY;

    emp.details.salaryDetails.fixedSalary = 50000.00;
    emp.details.salaryDetails.payType = SALARY;

    
    printf("Employee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);

    // Print pay details based on pay type
    if (emp.details.hourlyDetails.payType == HOURLY) {
        printf("Employee Hourly Wage: %.2f\n", emp.details.hourlyDetails.hourlyWage);
    } else if (emp.details.salaryDetails.payType == SALARY) {
        printf("Employee Fixed Salary: %.2f\n", emp.details.salaryDetails.fixedSalary);
    }

    return 0;
}
