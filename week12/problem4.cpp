/*
 * Задача 4: Subset sum
 * Дадена е редица от две по две различни положителни числа, подредени в намаляващ ред, и число S.
 * Да се отпечатат на екрана всевъзможните подмножества числа от редицата,
 * чиято сума е равна на даденото число S.
 */
#include <iostream>

void printSubset (int subset[], int n) {
    std::cout << "Found subset: ";
    for (int i = 0; i < n; i++) {
        std::cout << subset[i] << " ";
    }
    std::cout << std::endl;
}

void findSubsetsRec (int numbers[], int subset[], int firstUnusedIdx, int subsetLen, int n, int S) {
    for (int i = firstUnusedIdx; i < n; i++) {
        subset[subsetLen] = numbers[i];
        int newS = S - numbers[i];
        if (newS == 0) {
            printSubset(subset, subsetLen + 1);
        } else if (newS > 0) {
            findSubsetsRec(numbers, subset, i + 1, subsetLen + 1, n, newS);
        }
    }
}

void findSubsets (int numbers[], int n, int S) {
    int subset[100];
    findSubsetsRec(numbers, subset, 0, 0, n, S);
}

int main() {
    int numbers[100];
    int n, S;
    std::cout << "Enter n=";
    std::cin >> n;
    std::cout << "Enter numbers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }
    std::cout << "Enter target sum: ";
    std::cin >> S;
    findSubsets(numbers, n, S);
    return 0;
}
