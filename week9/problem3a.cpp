/**
 * Задача 3а. Да се напише функция, която сортира даден масив
 * с метода на пряката селекция. Елементите на масива да се сортират
 * според това колко пъти се среща цифрата 3 в десетичния им запис.
 */
#include <iostream>
int countDigit (int number, int digit) {
    int counter = 0;
    do {
        int currentDigit = number % 10;
        number /= 10;
        if (currentDigit == digit) {
            counter++;
        }
    } while (number != 0);

    return counter;
}

/**
 * Compare the number of threes in the decimal representation of a and b.
 * If a has less threes, return a negative number.
 * If b has less threes, return a positive number.
 * If equal, return 0.
 */
int cmpNumThrees(int a, int b) {
    int threesInA = countDigit(a, 3);
    int threesInB = countDigit(b, 3);
    return threesInA - threesInB;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void sort(int a[], int n) {
    for (int i=0; i < n; i++) {
        int currMinIdx = i;
        for (int j=i; j < n; j++) {
            if (cmpNumThrees(a[currMinIdx], a[j]) > 0) {
                // a[currMinIdx] has more thress
                currMinIdx = j;
            }
        }
        if (currMinIdx != i) {
            swap(a[i], a[currMinIdx]);
        }
    }
}

int main()
{
    int n;
    int a[10];
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter array to sort: ";
    for (int i=0; i < n; i++) {
        std::cin >> a[i];
    }
    sort(a, n);
    std::cout << "Sorted: " << std::endl;
    for (int i=0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
