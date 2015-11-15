#include <iostream>
using namespace std;

/*
 * Задача 2: Дадена е матрица mxn от цели числа, различни помежду си.
 * "Максимален ред" на матрица ще наричаме такъв ред, който съдържа
 * максималния елемент на всяка колона.
 * Например в матрицата
 * 1 4  5
 * 7 11 8
 * 3 9  6
 * редът с индекс 1 е максимален, понеже 7 е най-голямото число в колона 0,
 * 11 е най-голямото в колона 1, а 8 - в колона 2.
 * Да се провери дали дадената матрица има максимален ред и ако да - кой е той.
 *
 * Примерен изход от изпълнението:
 * Enter matrix dimensions:
 * num rows m=3
 * num cols n=3
 * 1 4 5
 * 7 11 8
 * 3 9 6
 *
 * The max element in column 0 is at index 1
 * The max element in column 1 is at index 1
 * The max element in column 2 is at index 1
 * Row 1 is the maximum row of the matrix.
 */
int main()
{
    int a[50][50];
    int m,n;
    // maxIndexes[i] contains the index of the max element in column i
    // i = 0 .. n-1
    int maxIndexes[50];

    cout<<"Enter matrix dimensions:"<<endl;
    cout<<"num rows m=";
    cin>>m;
    cout<<"num cols n=";
    cin>>n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>a[i][j];
        }
    }
    cout<<endl;
    for (int i=0; i < n; i++) {
        // for column i, find the max element in it
        int maxIdxI = 0;
        for (int j=1; j < m; j++) {
            if (a[maxIdxI][i] < a[j][i]) {
                maxIdxI = j;
            }
        }
        maxIndexes[i] = maxIdxI;
    }
    // print intermediary result
    for (int i=0; i < n; i++) {
        cout<<"The max element in column " << i
            << " is at index " << maxIndexes[i]<< endl;
    }

    // check whether all found indexes are equal
    bool areAllEqual = true;
    for (int i = 0; i < n-1; i++) {
        if (maxIndexes[i] != maxIndexes[i+1]) {
            areAllEqual = false;
            break;
        }
    }
    if (areAllEqual) {
        cout<<"Row "<<maxIndexes[0]<<" is the maximum row of the matrix."<<endl;
    } else {
        cout<<"The matrix has no maximum row"<<endl;
    }

    return 0;
}
