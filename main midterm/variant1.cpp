#include <iostream>
#include <cstring>
/*
 * Задача 1. Да се дефинира функцията:
 * bool evenMore ([подходящ тип]a, int n)
 * Функцията получава масив a с n елемента от тип int. Функцията да връща истина тогава и само тогава,
 * когато елементите на масива a, които имат четна стойност, са повече от елементите на масива с нечетна стойност.
 */
bool evenMore (int a[], int n) {
    int evenCount = 0;
    for (int i=0; i < n; i++) {
        if (a[i] % 2 == 0) {
            evenCount++;
        }
    }
    return evenCount > n - evenCount;
}

/*
 * Задача 2. Да се напише програма, която въвежда от клавиатурата
 * квадратна матрица ANxN (1 ≤ N ≤ 20) от символи (char).
 * Програмата да отпечатва на екрана колко пъти думата “dog” се среща в някои от редовете на матрицата.
 * Пример: за следната матрица 4x4:
 * d o g s
 * d o c a
 * d x o g
 * x d o g
 * програмата да печата числото 2 (думата dog се среща на първи и трети ред).
 */
int countWordInRow(char A[20], int n, char word[]) {
    int count = 0;
    int wordLen = strlen(word);
    bool match;
    for (int i=0; i <= n - wordLen; i++) {
        match = true;
        for (int j=0; j < wordLen && match; j++) {
            if (A[i + j] != word[j]) {
                match = false;
            }
        }
        if (match) {
            count++;
        }
    }
    return count;
}
int countWord(char A[20][20], int n, char word[]) {
    int totalCount = 0;
    for (int i=0; i < n; i++) {
        totalCount += countWordInRow(A[i], n, word);
    }
    return totalCount;
}

/*
 * Задача 3. Да се дефинира функцията:
 * bool timesSquare ([подходящ тип]a, int na, [подходящ тип]b, int nb)
 * Функцията получава масиви а и b съответно с na и nb на брой елемента от тип int.
 * Функцията да връща истина тогава и само тогава, когато всеки елемент x на масива a
 * е от вида x = k * y2, където y е някой от елементите на масива b, a k е произволно цяло число.
 * Пример: свойството е изпълнено за масивите a=[12,9,18] и b=[2,3], тъй като 12=3*2^2, 9=1*3^2, 18=2*3^2.
 */
bool isSquareType (int item, int b[], int n) {
    for (int i=0; i < n; i++) {
        if (item % (b[i] * b[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool timesSquare (int a[], int na, int b[], int nb) {
    for (int i = 0; i < na; i++) {
        if (!isSquareType(a[i], b, nb)) {
            // a[i] не е от желания вид
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout << "Start problem 1" << std::endl;
    int arr1[100];
    int n1;
    std::cout << "Enter array length: ";
    std::cin >> n1;
    std::cout << "Enter array: ";
    for (int i = 0; i < n1; i++) {
        std::cin >> arr1[i];
    }
    if (evenMore(arr1, n1)) {
        std::cout << "Even numbers are more" << std::endl;
    } else {
        std::cout << "Odd numbers are more" << std::endl;
    }
    std::cout << "End problem 1" << std::endl;
    std::cout << std::endl;

    std::cout << "Start problem 2" << std::endl;
    char A[20][20];
    int nA;
    char word[4] = "dog";
    std::cout << "Enter size of matrix: ";
    std::cin >> nA;
    std::cout << "Enter the chars for the matrix: " << std::endl;
    for (int i = 0; i < nA; i++) {
        for (int j = 0; j < nA; j++) {
            std::cin.ignore();
            std::cin.get(A[i][j]);
        }
    }
    std::cout << "\"dog\" can be found in the matrix "
            << countWord(A, nA, word) << " times" << std::endl;
    std::cout << "End problem 2" << std::endl;
    std::cout << std::endl;

    std::cout << "Start problem 3" << std::endl;
    int a[10], b[10], na, nb;
    std::cout << "Enter size of array a: ";
    std::cin >> na;
    std::cout << "Enter array a: ";
    for (int i = 0; i < na; i++) {
        std::cin >> a[i];
    }
    std::cout << "Enter size of array b: ";
    std::cin >> nb;
    std::cout << "Enter array b: ";
    for (int i = 0; i < nb; i++) {
        std::cin >> b[i];
    }
    if (timesSquare(a, na, b, nb)) {
        std::cout << "The condition is satisfied!" << std::endl;
    } else {
        std::cout << "The condition is not satisfied!" << std::endl;
    }
    std::cout << "End problem 3" << std::endl;
    std::cout << std::endl;
    return 0;
}
