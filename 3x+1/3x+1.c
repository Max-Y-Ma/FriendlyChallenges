#include <stdio.h>

// Function Prototypes
int calculate(unsigned long long int);
void printmsg(unsigned long long int);
void calcMaxValue(unsigned long long int*, unsigned long long int);

// Static Variables
static unsigned long long int maxValue = 0;
static int counter = 0;

int main() {
    // Get User Input
    unsigned long long int n;
    printf("Enter a number for n: ");
    scanf("%lld", &n);

    if (calculate(n))
        printf("\nF(n) is defined for %lld", n);
    else
        printf("\nF(n) is not defined for %lld", n);

    printf("\nThe Maximum Value was: %lld\n", maxValue);

    return 0;
}

int calculate(unsigned long long int n) {
    printmsg(n);    
    calcMaxValue(&maxValue, n);
    counter++;

    // Base Case #1
    if (n == 1)
        return 1;

    // Recursive Case #1
    if (n % 2 == 0)
        return calculate(n/2);
           
    // Recursive Case #2
    else
        return calculate(3*n+1);
}

void printmsg(unsigned long long int n) {
    printf("Iteration #%d = %lld\n", counter, n);
}

void calcMaxValue(unsigned long long int* max, unsigned long long int n) {
    if (*max < n)
        *max = n;
}