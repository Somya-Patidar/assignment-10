#include <stdio.h>

// Define a union named Data
union Data {
    int integer;
    float floating;
    char character;
    int flag; // flag to indicate the active member
};

// Define constants to represent the active member
#define INTEGER 1
#define FLOATING 2
#define CHARACTER 3

int main() {
    // Declare a variable of type Data
    union Data data;

    // Assign values to the union members
    data.flag = INTEGER;
    data.integer = 10;

    // Access and print the integer value
    printf("Integer: %d\n", data.integer);

    // Change the active member
    data.flag = FLOATING;
    data.floating = 3.14;

    // Access and print the floating-point value
    printf("Float: %.2f\n", data.floating);

    // Change the active member
    data.flag = CHARACTER;
    data.character = 'A';

    // Access and print the character value
    printf("Character: %c\n", data.character);

    

    return 0;
}
