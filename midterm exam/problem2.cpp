#include <iostream>
using namespace std;

int main () {
	int currentYear = 2015;
    while (true) {
        int sum = 0;
        int val = currentYear;
        while (val != 0) {
            sum += val % 10;
            val = val / 10;
        }
        if (19783 % sum == 0) {
            cout <<"The year is " <<currentYear << endl;
            break;
        }
        currentYear++;
    }
    return 0;
}