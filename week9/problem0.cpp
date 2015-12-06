/**
 * Задача 0 (псевдоними).
 * Да се напише функция, която разменя стойностите на две целочислени променливи:
 * а) чрез указатели
 * б) чрез псевдоними
 */
#include <iostream>

void swap_ptr(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ref(int& a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a, b;
    std::cout<<"Enter a and b: ";
    std::cin>>a>>b;
    std::cout<<"You entered " << a << " " << b << std::endl;
    swap_ptr(&a, &b);
    std::cout<<"Swapped: " << a << " " << b << std::endl;
    swap_ref(a, b);
    std::cout<<"Swapped again: " << a << " " << b << std::endl;

    return 0;
}
