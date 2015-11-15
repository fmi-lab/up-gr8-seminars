#include <iostream>
using namespace std;

// Intro to the ASCII table
int main()
{
    // Char and ASCII examples
    char c = '0';
    int b = 97;
    cout << "The char '" << c << "' has ascii code " << (int) c << endl;
    cout << "The char with ascii code " << b << " is '" << (char) b << "'" <<endl;
    if ( '0' != 0) {
        cout << "The symbol '0' is different than the symbol with ASCII code 0!"<<endl;
    }
    // operations on characters are operations on their ASCII codes
    int letterDistance = 'z' - 'a';
    cout << "The letters 'z' is the " << letterDistance
         << " letter in the English alphabet (counting from 0)"<<endl;

    letterDistance = 5;
    cout << "The " << letterDistance << " letter in the English alphabet is "
         << "'" << (char) ('a' + letterDistance) << "'" << endl;

    char c1 = 'a', c2 = 'A';
    if (c1 > c2) {
        cout << "Small letters come after capital letters in the ASCII table." <<endl;
    } else {
        cout << "Capital letters come after small letters in the ASCII table." << endl;
    }
    return 0;
}
