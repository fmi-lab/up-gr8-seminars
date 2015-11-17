#include <iostream>
#include <cstring>
using namespace std;

/*
 * Задача 3в. Дадени са два масива с числа. Да се провери дали
 * вторият масив е подредица на първия.
 * Подредица означава елементите на b да се срещат точно в този ред в а,
 * но не задължително един до друг.
 * Пример:
 * а = {5, 4, 7, 8, 1, 9, 11}, b = {7, 8, 9} -> подредица е
 * а = {5, 4, 7, 8, 1, 9, 11}, b = {7, 4, 5} -> не е подредица
 */
int main()
{
    int a[50], b[50];
    int m, n;

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

    int idxB = 0;
    // when we see the current element of b that we need,
    // start looking for the next element from b
    for (int i = 0; i < m && idxB < n; i++) {
        if (a[i] == b[idxB]) {
            idxB++;
        }
    }
    if (idxB == n) {
        // we found all elements from b in the correct order
        cout << "b is a subsequence of a" << endl;
    } else {
        cout << "b is not a subsequence of a" << endl;
    }

    return 0;
}
