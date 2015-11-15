#include <iostream>
using namespace std;

/*
 * Задача 3: Една квадратна матрица се нарича магически квадрат, ако сумата на елементите
 * на всеки ред, всеки стълб и двата главни диагонала са равни.
 * Да се напише програма, която проверява дали дадена матрица nxn е магически квадрат.
 *
 * Примерен изход от изпълнението:
 * Enter matrix dimensions:
 * num rows and columns n=3
 * 2 7 6
 * 9 5 1
 * 4 3 8
 *
 * This is a magic square
 */
int main()
{
    int a[50][50];
    int n;
    // the sum of the elements in row 0
    int firstSum = 0;
    // used to calculate the sums in the other rows/columns/diagonals
    int currentSum;
    // store end result
    bool isMagic = true;

    cout<<"Enter matrix dimensions:"<<endl;
    cout<<"num rows and columns n=";
    cin>>n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>a[i][j];
        }
    }
    cout<<endl;

    // calculate the sum in row 0
    for (int i = 0; i < n; i++) {
        firstSum += a[0][i];
    }
    // now calculate every other sum and compare it to this one
    // 1. check the rest of the rows
    for (int i = 1; i < n && isMagic; i++) {
        // the sum in row i
        currentSum = 0;
        for (int j=0; j < n; j++) {
            currentSum += a[i][j];
        }
        if (currentSum != firstSum) {
            cout << "Mismatch found in row " << i << endl;
            isMagic = false;
        }
    }

    // if all rows are ok, now check the columns
    for (int i = 0; i < n && isMagic; i++) {
        // column i
        currentSum = 0;
        for (int j = 0; j < n; j++) {
            currentSum += a[j][i];
        }
        if (currentSum != firstSum) {
            cout << "Mismatch found in column " << i << endl;
            isMagic = false;
        }
    }

    // now try the diagonals, but only if all other sums were equal
    if (isMagic) {
        // main diagonal
        currentSum = 0;
        for (int i = 0; i < n; i++) {
            currentSum += a[i][i];
        }
        if (currentSum != firstSum) {
            cout << "Mismatch in the main diagonal"<<endl;
            isMagic = false;
        } else {
            // finally, check the secondary diagonal
            currentSum = 0;
            for (int i = 0; i < n; i++) {
                currentSum += a[i][n - i - 1];
            }
            if (currentSum != firstSum) {
                cout << "Mismatch in the secondary diagonal"<<endl;
                isMagic = false;
            }
        }
    }
    // print final result
    if (isMagic) {
        cout << "This is a magic square"<<endl;
    } else {
        cout << "This is not a magic suqare :(" << endl;
    }
    return 0;
}
