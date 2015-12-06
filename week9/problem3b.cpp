/**
 * Задача 3б. Нека е дадена матрица от символи, в която всеки ред представлява
 * въведен от потребителя низ. Да се напише функция, която сортира редовете на матрицата
 * 1) лексикографски
 * 2) според броя главни букви на реда.
 * Да се използва схемата, показана в задача 3а.
 */
#include <iostream>
#include <cstring>

// maximum number of symbols in a row
const int MAX_LEN = 10;

int countCapitalLetters(char* a) {
    int counter = 0;
    while (*a != 0) {
        if (*a >= 'A' && *a <='Z') {
            counter++;
        }
        a++;
    }
    return counter;
}

int cmpNumCapitalLetters(char* a, char* b) {
    int countA = countCapitalLetters(a);
    int countB = countCapitalLetters(b);
    return countA - countB;
}

void swap(char* a, char* b) {
    while(*a != 0 && *b != 0) {
        char tmp = *a;
        *a = *b;
        *b = tmp;
        a++;
        b++;
    }
    if (*a != 0) {
        while (*a != 0) {
            *b = *a;
            *a = 0;
            a++; b++;
        }
        *b = 0;
    } else {
        while (*b != 0) {
            *a = *b;
            *b = 0;
            a++; b++;
        }
        *a = 0;
    }
}

void swapSmarter(char* a, char* b) {
    char temp[MAX_LEN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void sortLex(char a[][MAX_LEN], int n) {
    for (int i=0; i < n; i++) {
        int currMinIdx = i;
        for (int j=i; j < n; j++) {
            if (strcmp(a[currMinIdx], a[j]) > 0) {
                // a[currMinIdx] has more thress
                currMinIdx = j;
            }
        }
        if (currMinIdx != i) {
            swapSmarter(a[i], a[currMinIdx]);
        }
    }
}

void sortByCapitalLetters(char a[][MAX_LEN], int n) {
    for (int i=0; i < n; i++) {
        int currMinIdx = i;
        for (int j=i; j < n; j++) {
            if (cmpNumCapitalLetters(a[currMinIdx], a[j]) > 0) {
                // a[currMinIdx] has more thress
                currMinIdx = j;
            }
        }
        if (currMinIdx != i) {
            swapSmarter(a[i], a[currMinIdx]);
        }
    }
}

int main()
{
    int n;
    char words[100][MAX_LEN];
    std::cout << "Enter number of words: ";
    std::cin >> n;
    std::cout << "Enter words with max length " << MAX_LEN <<": " << std::endl;
    // ignore the newline entered after n
    std::cin.ignore();
    for (int i=0; i < n; i++) {
        std::cin.getline(words[i], MAX_LEN);
    }

    sortLex(words, n);
    std::cout << "Sorted (lexicographic): " << std::endl;
    for (int i=0; i < n; i++) {
        std::cout << words[i] << std::endl;
    }
    std::cout << std::endl;

    sortByCapitalLetters(words, n);
    std::cout << "Sorted (by num capital letters): " << std::endl;
    for (int i=0; i < n; i++) {
        std::cout << words[i] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
