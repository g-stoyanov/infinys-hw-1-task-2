#include <stdio.h>
#include <math.h>
#include <limits.h>

#define OVERFLOW_LIMIT 93
#define OVERFLOW_CODE 0

int getClosestFibonacci(unsigned long long *fibonacciNumber, long long number);
long long getUserInput();

int main() {
    unsigned long long fibonacciNumber = 0;
    unsigned long long userNumber = getUserInput();
    int fibonacciCount = getClosestFibonacci(&fibonacciNumber, userNumber);

    if(fibonacciCount == OVERFLOW_CODE) {
        printf("%hi WTF Bro!", userNumber);
    }
    else {
        printf("Closest Fibonacci member is %d - %llu", fibonacciCount, fibonacciNumber);
    }

    return 0;
}

int getClosestFibonacci(unsigned long long *fibonacciNumber, long long number) {
    *fibonacciNumber = 1;
    if(number < 2) {
        return 1;
    }
    else if(number < 3) {
        *fibonacciNumber = 2;
        return 3;
    }

    unsigned long long minPrevDiff = ULONG_MAX;
    unsigned long long minNextDiff = ULONG_MAX;
    unsigned long long prevDiff = 0;
    unsigned long long nextDiff = 0;
    unsigned long long oldest = 0;
    unsigned long long previous = 1;
    unsigned long long current = 1;

    for (int i = 0; i < OVERFLOW_LIMIT; ++i) {
        unsigned long long new = previous + current;

        prevDiff = abs(number - previous);
        nextDiff = abs(number - current);

        if(minPrevDiff < prevDiff || minNextDiff < nextDiff) {
            if(minPrevDiff <= minNextDiff) {
                *fibonacciNumber = oldest;
                return i;
            }
            else {
                *fibonacciNumber = previous;
                return i + 1;
            }
        }
        else {
            minPrevDiff = prevDiff;
            minNextDiff  = nextDiff;
        }

        oldest = previous;
        previous = current;
        current = new;
    }

    return OVERFLOW_CODE;
}

long long getUserInput() {
    unsigned long long userInput;
    printf("\nPlease input number: ");
    scanf("%llu", &userInput);

    return userInput;
}
