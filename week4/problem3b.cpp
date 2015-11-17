#include <iostream>
#include <cstring>
using namespace std;

/*
 * Задача 3б. Дадени са два масива с числа. Да се провери дали
 * вторият масив е подпоследователност на първия.
 * Подпоследователност значи елементите на b да се срещат точно в този ред
 * и да са един до друг в а.
 * Пример:
 * а = {5, 4, 7, 8, 1, 9, 11}, b = {7, 8, 1} -> подпоследователност е
 * а = {5, 4, 7, 8, 1, 9, 11}, b = {7, 8, 9} -> не е подпоследователност
 */
int main()
{
    int a[50], b[50];
    int m, n;
    bool foundSubstring = false;

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

    // find possible matches for the first element in b
    // any match after index m - n does not work because
    // we won't be able to fit the whole array b in a
    // at this position
    for (int i=0; i < m - n && !foundSubstring; i++) {
        if (a[i] == b[0]) {
            // check if the rest of b matches
            bool isCompleteMatch = true;
            for (int j = 1; j < n; j++) {
                if (a[i + j] != b[j]) {
                    isCompleteMatch = false;
                    break;
                }
            }
            if (isCompleteMatch) {
                // found it!
                foundSubstring = true;
            }
        }
    }
    if (foundSubstring) {
        cout << "b is a substring of a" << endl;
    } else {
        cout << "b is not a substring of a" << endl;
    }
    return 0;
}
