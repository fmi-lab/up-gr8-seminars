#include <iostream>
using namespace std;

/*
 * Задача 0: Да се изведат елементите на въведена матрица с размери mxn
 *        а) по редове от ляво надясно
 *        б) по колони от последната към първата, като всяка колона се изведе
 *           от долу нагоре
 * Примерен изход от изпълнението:
 *
 * Enter matrix dimensions:
 * num rows m=2
 * num columns n=4
 * 1 2 3 4
 * 5 6 7 8
 *
 * Solution to a:
 * 1 2 3 4
 * 5 6 7 8
 *
 * Solution to b:
 * 8 4
 * 7 3
 * 6 2
 * 5 1
 * Done!
 */
int main()
{
    int a[50][50];
    int m, n;
    cout<<"Enter matrix dimensions:"<<endl;
    cout<<"num rows m=";
    cin>>m;
    cout<<"num columns n=";
    cin>>n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>a[i][j];
        }
    }
    cout<<endl;
    cout<<"Solution to a:"<<endl;
    for (int i = 0; i < m; i++) {
        // display all elements in row i
        for (int j=0; j < n; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Solution to b:"<<endl;
    for (int i = n-1; i >= 0; i--) {
        // display all elements from column i
        // from the bottom to the top
        for (int j = m-1; j >=0; j--) {
            cout << a[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<"Done!"<<endl;
    return 0;
}
