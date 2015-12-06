/**
 * Задача 2. Да се напише функция, която намира и записва в масив
 * първите n прости числа на Фибоначи.
 */
#include <iostream>
#include <cmath>

bool isPrime (int number) {
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            // number is not prime, it is divisible by i
            return false;
        }
    }

    return true;
}

void findPrimeFibs(int primeFibs[], int n) {
    int fibPrev = 1, fibCurr = 1;
    int fibNext;
    int numFound = 0;
    while (numFound < n) {
        fibNext = fibCurr + fibPrev;
        fibPrev = fibCurr;
        fibCurr = fibNext;
        if (isPrime(fibNext)) {
            primeFibs[numFound] = fibNext;
            numFound++;
        }
    }
}

int main()
{
    int n;
    int fibs[10];
    std::cout << "Enter number of prime Fibonaccis to find: ";
    std::cin >> n;
    findPrimeFibs(fibs, n);
    for (int i=0; i < n; i++) {
        std::cout<<"The " << i <<"-th prime Fib is " << fibs[i] << std::endl;
    }
    return 0;
}
