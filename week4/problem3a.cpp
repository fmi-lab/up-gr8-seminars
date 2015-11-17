#include <iostream>
#include <cstring>
using namespace std;

/*
 * Задача 3a. Дадени са два масива с числа. Да се провери дали
 * елементите на втория масив са подмножество на елементите на първия.
 * Пример:
 * а = {5, 4, 7, 8, 1, 9, 11}, b = {1, 4, 9} -> подмножество е
 * а = {5, 4, 7, 8, 1, 9, 11}, b = {1, 4, 13} -> не е подмножество
 */
int main()
{
    int a[50], b[50];
    int m, n;
    bool isSubset = true;

    cout << "Enter first array length: ";
    cin >> m;
    cout << "Enter " << m << " numbers for a: ";
    for (int i=0; i < m; i++) {
        cin >> a[i];
    }
    cout << "Enter second array length: ";
    cin >> n;
    cout << "Enter " << n << " numbers for b: ";
    for (int i=0; i < n; i++) {
        cin >> b[i];
    }

    for (int i=0; i < n; i++) {
        // check if b[i] can be found in a
        bool found = false;
        for (int j=0; j < m; j++) {
            if (a[j] == b[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            isSubset = false;
            break;
        }
    }
    if (isSubset) {
        cout << "b is a subset of a" << endl;
    } else {
        cout << "b is not a subset of a" << endl;
    }
    return 0;
}
