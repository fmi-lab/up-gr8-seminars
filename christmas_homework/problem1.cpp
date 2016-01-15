#include <iostream>
#include <cstring>

/*
 * Solution to problem 1
 */

char decodeChar (char c, char code) {
    int resultIdx = c - code;
    // handle correctly negatives
    resultIdx = (resultIdx + 26) % 26;
    return 'a' + resultIdx;
}

void vigenereDecypher(char* message, char* codeWord, char* decoded) {
    int codeWordIdx = 0;
    int messageLen = strlen(message);
    int codeLen = strlen(codeWord);
    for (int i = 0; i < messageLen; i++) {
        decoded[i] = decodeChar(message[i], codeWord[codeWordIdx]);
        // make sure to reset the code word index when we reach its end
        codeWordIdx = (codeWordIdx + 1) % codeLen;
    }
    decoded[messageLen] = 0;
}

int main()
{
    char message[100];
    char codeWord[100];
    char decoded[100];
    std::cout << "Enter message to decode: ";
    std::cin.getline(message, 100);
    std::cout << "Enter code word: ";
    std::cin.getline(codeWord, 100);
    vigenereDecypher(message, codeWord, decoded);
    std::cout << "The decoded message is: " << decoded << std::endl;
    return 0;
}
