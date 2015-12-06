/**
 * Задача 1. Да се напише функция, която по зададен масив връща стойността на
 * най-малкия му елемент, както и на кой индекс е бил намерен.
 * За връщане на индекса са се използва:
 * а) формален параметър от тип указател
 * б) формален параметър псевдоним
 */
#include <iostream>

double findMin_ptr(double a[], int n, int* minIdxAddr) {
    *minIdxAddr = 0;
    for (int i=1; i < n; i++) {
        if (a[*minIdxAddr] > a[i]) {
            *minIdxAddr = i;
        }
    }
    return a[*minIdxAddr];
}

double findMin_ref(double a[], int n, int& minIdx) {
    minIdx = 0;
    for (int i=1; i < n; i++) {
        if (a[minIdx] > a[i]) {
            minIdx = i;
        }
    }
    return a[minIdx];
}

int main()
{
    double a[10];
    int n;
    std::cout << "Enter num elements: ";
    std::cin >> n;
    std::cout << "Enter elements: ";
    for (int i=0; i < n; i++) {
        std::cin >> a[i];
    }
    int minIdxValue;
    double min = findMin_ptr(a, n, &minIdxValue);
    std::cout<<"The min element is " << min << " and it was found at idx " << minIdxValue << std::endl;

    int minIdxValue2;
    double min2 = findMin_ref(a, n, minIdxValue2);
    std::cout<<"The min2 element is " << min2 << " and it was found at idx " << minIdxValue2 << std::endl;

    return 0;
}
