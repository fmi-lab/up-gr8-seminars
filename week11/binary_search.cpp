#include <iostream>
/*
 * Да се напише рекурсивна функция, която проверява дали дадено число
 * се среща в сортиран в нарастващ ред масив по метода на двоичното търсене.
 * База: len = 0 -> елементът го няма, false
 *       len = 1 -> arr[len-1] == element
 */
bool binarySearch (double* arr, int len, double element) {
    if (len == 0) {
        return false;
    }
    if (len == 1) {
        return arr[0] == element;
    }
    int middleIdx = len / 2;
    if (arr[middleIdx] == element) {
        return true;
    } else if (arr[middleIdx] < element) {
        // search in the second half of the array
        return binarySearch(arr + middleIdx + 1, len - (middleIdx + 1), element);
    } else {
        return binarySearch(arr, middleIdx, element);
    }
}

int main()
{
    double elements[10];
    int n;
    double elemToFind;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    std::cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> elements[i];
    }
    std::cout << "Enter element to search for: ";
    std::cin >> elemToFind;
    std::cout << "The element " << elemToFind << " is ";
    if (!binarySearch(&elements[0], n, elemToFind)) {
        std::cout << " not ";
    }
    std::cout << "in the array" << std::endl;
    return 0;
}
