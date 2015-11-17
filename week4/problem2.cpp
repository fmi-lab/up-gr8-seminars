#include <iostream>
#include <cstring>
using namespace std;

/*
 * Задача 2. Да се провери дали два въведени масива с еднаква дължина
 * са симетрични
 * Пример:
 * a = {1, 2, 3}, b = {3, 2, 1} -> симетрични са
 * a = {1, 2, 3} b = {3, 1, 2} -> не са симетрични
 */
int main()
{
    int a[50], b[50];
    int n;
    bool areSymmetrical = true;
    cout << "Enter array length: ";
    cin >> n;
    cout << "Enter " << n << " number for a: ";
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter " << n << " number for b: ";
    for (int i=0; i < n; i++) {
        cin >> b[i];
    }
    for (int i=0; i < n && areSymmetrical; i++) {
        if (a[i] != b[n-i-1]) {
            areSymmetrical = false;
        }
    }
    if (areSymmetrical) {
        cout << "The arrays are symmetrical"<<endl;
    } else {
        cout << "The arrays are not symmetrical"<<endl;
    }
    return 0;
}
