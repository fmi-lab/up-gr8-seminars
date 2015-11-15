#include <iostream>
#include <cstring>
using namespace std;

/*
 * Задача 1. Код на Цезар
 * Да се напише програма, която дава възможност на потребителя да кодира
 * или декодира дадена дума по зададено кодиращо число.
 * Кодът на Цезар работи така:
 * 1. Избирате цяло число n, с което ще кодирате.
 * 2. За да кодирате дадена дума, всяка буква заместете с буквата, която
 * е на n позиции в азбуката след нея. Например за n=5, буквата 'a' се кодира с
 * буквата 'e'. Ако изместването излезе извън азбуката, започва се от началото,
 * т.е. при n = 1 буквата 'z' отива в буквата 'a'.
 * 3. Декодирането става по обратния път, т.е. връщаме се n букви назад, като считаме,
 * че преди 'a' е 'z'.
 * Пример:
 * n = 5
 * "fmi" се кодира като "krn"
 */
int main()
{
    int choice;
    int code, len;
    char word[50];

    do {
        cout << "1. Encode" <<endl;
        cout << "2. Decode" << endl;
        cout << "3. Exit" << endl;
        cout << "Pick an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                // ENCODE
                cout << "Enter the code number: ";
                cin >> code;
                cout << "Enter word to encode: ";
                // this is used to force cin  to skip any
                // leftover whitespace characters
                cin.ignore();
                cin.getline(word, 50);
                len = strlen(word);
                for (int i=0; i < len; i++) {
                    // find the index of the letter in the alphabet
                    word[i] = word[i] - 'a';
                    // shift the position in the alphabet
                    word[i] = word[i] + code % 26;
                    // make sure we wrap around from 'z' to 'a'
                    word[i] = word[i] % 26;
                    // go back to the ascii code
                    word[i] = word[i] + 'a';
                }
                cout << "The encoded message is: " << word << endl;
                break;
            case 2:
                // DECODE
                cout << "Enter the code number: ";
                cin >> code;
                cout << "Enter word to decode: ";
                // this is used to force cin  to skip any
                // leftover whitespace characters
                cin.ignore();
                cin.getline(word, 50);
                len = strlen(word);
                for (int i=0; i < len; i++) {
                    // find the index of the letter in the alphabet
                    word[i] = word[i] - 'a';
                    // shift the position in the alphabet
                    word[i] = word[i] - code;
                    // make sure we wrap around from 'z' to 'a'
                    word[i] = word[i] % 26;
                    // go back to the ascii code
                    word[i] = word[i] + 'a';
                }
                cout << "The decoded message is: " << word << endl;
                break;
            case 3: cout << "Exiting"<<endl; break;
            default: cout << "Please choose 1, 2 or 3"<<endl;
        }
    } while (choice != 3);
}
