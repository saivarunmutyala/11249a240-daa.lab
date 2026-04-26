AIM: To implement a recursive function in C to find the n-th Fibonacci number.

PROGRAM:
#include <stdio.h>
// Recursive function to find Fibonacci number
int fib(int n){  
    // Base case: fib(0) = 0
    if (n == 0){
        return 0;
    }

    // Base case: fib(1) = 1
    if (n == 1) {
        return 1;
    }

    // Recursive case: fib(n) = fib(n-1) + fib(n-2)
    return fib(n-1) + fib(n-2); 
}  

int main() {
    int n;

    // Input number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Check for invalid input
    if (n < 0){
        printf("Invalid number");
        return 0;
    }

    // Print nth Fibonacci number
    printf("Fibonacci term is: %d", fib(n));

    return 0;
}

OUTPUT:
Enter the number of terms: 7
Fibonacci term is: 13
