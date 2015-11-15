#include <iostream>
#include <cstring>
using namespace std;

/*
 * Задача 0. Напишете програма, която сравнява лексикографски два въведени низа.
 * (без да използвате вградените функции)
 */
int main()
{
    char s1[40], s2[40];
    cout << "Enter the two strings on separate lines:" << endl;
    cin.getline(s1, 40);
    cin.getline(s2, 40);
    int idx = 0;
    while(s1[idx] != 0 && s2[idx] != 0 && s1[idx] == s2[idx]) {
        idx++;
    }
    int result = s1[idx] - s2[idx];
    if (result < 0) {
        cout << s1 << " comes before " << s2 << endl;
    } else if (result > 0) {
        cout << s1 << " comes after " << s2 << endl;
    } else {
        cout << s1 << " is the same as " << s2 << endl;
    }
    return 0;
}
