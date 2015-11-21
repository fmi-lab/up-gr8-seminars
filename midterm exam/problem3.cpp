#include <iostream>
using namespace std;

int main () {
    int n;
    int a[10];
    cout << "Enter num people: ";
    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    bool friends = true;
    for (int i=0; i < n; i++) {
        bool foundFriend = false;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j] + 4 || a[i] == a[j] - 4) {
                foundFriend = true;
                break;
            }
        }
        if (!foundFriend) {
            friends = false;
            break;
        }
    }
    if (friends) {
        cout << "Harry found friends!" << endl;
    } else {
        cout << "No friends for Harry" << endl;
    }
   return 0;
}