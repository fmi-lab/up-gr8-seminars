/*
 * ЗЗС 5, зад. 9в:
 * Да се дефинира функция int StringCompareNotSensitive(const char* first, const char* second),
 * която сравнява лексикографски два символни низа, като не различава малки и главни букви.
 * Функцията да връща 0, ако символните низове съвпадат без да се различават малки и главни букви,
 * отрицателно цяло число, ако първият низ е по-малък от втория и положително цяло число, ако първият низ е по-голям от втория
*/
#include <iostream>

char convertToLowercase (char c) {
    if (c < 'A' || c > 'Z') {
        // not an uppercase letter, do not modify it
        return c;
    }
    // c - 'A' = lowercaseC - 'a'
    return c - ('A' - 'a');
}
bool isEqualCaseInsensitive (char c1, char c2) {
    return convertToLowercase(c1) == convertToLowercase(c2);
}

int stringCompareNotSensitive(const char* first, const char* second) {
    while (*first != 0 && *second != 0 &&
           isEqualCaseInsensitive(*first, *second)) {
            first++;
            second++;
    }
    return *first - *second;
}

int main()
{
    char s1[10];
    char s2[10];
    std::cout << "Enter first string: ";
    std::cin.getline(s1, 10);
    std::cout << "Enter second string: ";
    std::cin.getline(s2, 10);
    if (stringCompareNotSensitive(s1, s2) == 0) {
        std::cout<< "They are equal!" << std::endl;
    } else {
        std::cout << "Not equal" << std::endl;
    }
    return 0;
}
