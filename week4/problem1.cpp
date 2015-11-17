#include <iostream>
#include <cstring>
using namespace std;

/*
 * Задача 1. Да се провери дали всяко число от даден интервал [a, b]
 * е взаимнопросто с числото c.
 * Пример:
 * a = 5, b = 19, c = 23 -> всяко число е взаимнопросто
 * a = 5, b = 19, c = 21 -> не всяко число е взаимнопросто
 */
int main()
{
    int a, b, c;
    bool allCoprime = true;
    cout << "Enter interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter c: ";
    cin >> c;
    for (int i = a; i <= b && allCoprime; i++) {
        // check if i and c are co-prime
        // check if there is a number that divides both i and c
        for (int j = 2; j <= i && j <= c && allCoprime; j++) {
            if (c % j == 0 && i % j == 0) {
                // not coprime
                allCoprime = false;
            }
        }
    }
    if (allCoprime) {
        cout << "All numbers in [" << a << ", " << b
            << "] are coprime with " << c << endl;
    } else {
        cout << "Not all numbers in [" << a << ", " << b
            << "] are coprime with " << c << endl;

    }
	return 0;
}
