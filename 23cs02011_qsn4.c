#include <stdio.h>

#define MAX_SIZE 5

// Define a union named DataArray
union DataArray {
    int integers[MAX_SIZE];
    float floats[MAX_SIZE];
    char characters[MAX_SIZE];
};

int main() {
   
    union DataArray data;

   
    for (int i = 0; i < MAX_SIZE; i++) {
        data.integers[i] = i + 1;
    }

    
    printf("Integer Array: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", data.integers[i]);
    }
    printf("\n");

    
    for (int i = 0; i < MAX_SIZE; i++) {
        data.floats[i] = (float)(i + 0.5);
    }

    // Access and print the float array
    printf("Float Array: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%.2f ", data.floats[i]);
    }
    printf("\n");

    
    for (int i = 0; i < MAX_SIZE; i++) {
        data.characters[i] = 'A' + i;
    }

    printf("Character Array: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%c ", data.characters[i]);
    }
    printf("\n");

    //  printf("Integer Array: ");
    // for (int i = 0; i < MAX_SIZE; i++) {
    //     printf("%d ", data.integers[i]);
    // }
    // printf("\n");
    return 0;
}
// union only holds one of the arrays at a time. Modifying one array may affect the other arrays because they share the same memory location.
// Unions are not suitable for storing multiple arrays if you need to access or modify more than one array simultaneously.
