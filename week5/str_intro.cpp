#include <iostream>
#include <cstring>
using namespace std;

// Intro to strings and built-in functions
int main()
{
    char str[10] = "Hello!";
    // a char array with 10 symbols can only hold
    // a string of length 9
    // char str1[10] = "Hello, world!";
    char str2[20];
    // read a string from the console
    cin.getline(str2, 20);
    cout << "The string \"" << str2 << "\" has length " << strlen(str2) << endl;
    char s1[10] = "Hello";
    char s2[10] = "World";
    int cmp = strcmp(s1, s2);
    if (cmp < 0) {
        cout << s1 << " comes before " << s2 << endl;
    } else if (cmp > 0) {
        cout << s1 << " comes after " << s2 << endl;
    } else {
        cout << s1 << " is the same as " << s2 << endl;
    }
    char s3[20];
    strcpy(s3, s1);
    cout << "After copying, s3 is " << s3 << endl;
    strcat(s3, s2);
    cout << "After concatenation, s3 is " << s3 << endl;
    return 0;
}
