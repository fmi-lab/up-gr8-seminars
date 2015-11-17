#include <iostream>
#include <cstring>
using namespace std;

/*
 * Задача 1a. Да се провери дали съществува число от даден интервал [a, b],
 * което е взаимнопросто с числото c.
 * Пример:
 * a = 5, b = 19, c = 23 -> съществува такова число
 * a = 2, b = 6, c = 30 -> не съществува такова число
 */
int main()
{
    int a, b, c;
    bool existsCoprime = false;
    cout << "Enter interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter c: ";
    cin >> c;
    for (int i = a; i <= b && !existsCoprime; i++) {
        // check if i and c are co-prime
        // check if there is a number that divides both i and c
        bool coprime = true;
        for (int j = 2; j <= i && j <= c; j++) {
            if (c % j == 0 && i % j == 0) {
                // not coprime
                coprime = false;
            }
        }
        if (coprime) {
            existsCoprime = true;
        }
    }
    if (existsCoprime) {
        cout << "There is a number in [" << a << ", " << b
            << "] that is coprime with " << c << endl;
    } else {
        cout << "No number in [" << a << ", " << b
            << "] is coprime with " << c << endl;

    }
	return 0;
}
