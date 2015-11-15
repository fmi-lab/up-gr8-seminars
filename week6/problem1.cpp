#include <iostream>
using namespace std;

/*
 * Задача 1: Да се изведат елементите на въведена квадратна матрица с размери nxn,
 * които се намират под вторичния диагонал (включително диагонала).
 * Примерен изход от изпълнението:
 *
 * Enter matrix dimensions:
 * num rows and columns n=4
 * 1 2 3 4
 * 5 6 7 8
 * 9 10 11 12
 * 13 14 15 16
 *
 * Elements under the secondary diagonal (by row):
 * 4
 * 7 8
 * 10 11 12
 * 13 14 15 16
 * Done!
 */
int main()
{
    int m[50][50];
    int n;
    cout<<"Enter matrix dimensions:"<<endl;
    cout<<"num rows and columns n=";
    cin>>n;
    for (int i = 0; i < n; i++) {
        for (int j = 0
             ; j < n; j++) {
            cin>>m[i][j];
        }
    }
    cout<<endl;
    cout<<"Elements under the secondary diagonal (by row):"<<endl;
    for (int i = 0; i < n; i++) {
        // display all elements in row i
        // which are on or below the secondary diagonal
        for (int j = n-i-1; j < n ; j++) {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Done!"<<endl;
    return 0;
}
