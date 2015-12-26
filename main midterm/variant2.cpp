#include <iostream>
#include <cstring>
#include <cmath>
/*
 * Задача 1. Да се дефинира функцията:
 * bool  nonSquare ([подходящ тип]a, int n)
 * Функцията получава масив a с n елемента от тип int. Функцията да връща истина
 * тогава и само тогава, когато елементите на масива a, които са точни квадрати,
 * са по-малко от елементите на масива, които не са точни квадрати.
 */
bool isSquare (int a) {
    int sqr = (int) sqrt(a);
    return sqr * sqr == a;
}

bool nonSquare(int a[], int n) {
    int squaresCount = 0;
    for (int i = 0; i < n; i++) {
        if (isSquare(a[i])) {
            squaresCount++;
        }
    }
    return squaresCount < n - squaresCount;
}

/*
 * Задача 2. Да се напише програма, която въвежда от клавиатурата
 * квадратна матрица ANxN (1 ≤ N ≤ 20) от числа (int). Програмата да отпечатва
 * броя на редовете на матрицата, в които има поне три съседни последователни естествени числа.
 * Пример: за следната матрица 4x4:
 * 1 2 3 7
 * 1 0 2 3
 * 1 2 9 3
 * 9 4 5 6
 * програмата да печата числото 2 (заради елементите 1,2,3 на първи ред и 4,5,6 на четвърти).
 */
bool hasConsecutivesInRow (int a[], int n) {
    for (int i = 0; i < n - 2; i++) {
        if (a[i] == a[i+1] - 1 && a[i] == a[i + 2] - 2) {
            return true;
        }
    }
    return false;
}

int countConsecutives(int A[20][20], int n) {
    int totalCount = 0;
    for (int i=0; i < n; i++) {
        if (hasConsecutivesInRow(A[i], n)) {
            totalCount++;
        }
    }
    return totalCount;
}

/*
 * Задача 3. Да се дефинира функцията:
 * bool policed ([подходящ тип]a, int na, [подходящ тип]b, int nb)
 * Функцията получава масиви а и b съответно с na и nb елемента от тип int.
 * Функцията да връща истина тогава и само тогава, когато всеки елемент x на масива a
 * е в затворен числов интервал с краища – два съседни елемента на b.
 * Пример: свойството е изпълнено за масивите a = [6, 2, 8] и b = [5, 10, 1, 2], тъй като 6 ∈ [5,10], 2 ∈ [1,2], 8 ∈ [5,10].
 */
bool isPolicedElement (int a, int b[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a >= b[i] && a <= b[i+1]) {
            return true;
        }
    }
    return false;
}

bool policed (int a[], int na, int b[], int nb) {
    for (int i = 0; i < na; i++) {
        if (!isPolicedElement(a[i], b, nb)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Start problem 1" << std::endl;
    int n1, a1[100];
    std::cout << "Enter size of array: ";
    std::cin >> n1;
    std::cout << "Enter array elements: ";
    for (int i=0; i < n1; i++) {
        std::cin >> a1[i];
    }
    if (nonSquare(a1, n1)) {
        std::cout << "Most elements are not squares" << std::endl;
    } else {
        std::cout << "Most elements are squares" << std::endl;
    }
    std::cout << "End problem 1" << std::endl;
    std::cout << std::endl;

    std::cout << "Start problem 2" << std::endl;
    int a2[20][20], n2;
    std::cout << "Enter size of matrix: ";
    std::cin >> n2;
    std::cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            std::cin >> a2[i][j];
        }
    }
    std::cout << "There are " << countConsecutives(a2, n2) << " sequences in the matrix" << std::endl;
    std::cout << "End problem 2" << std::endl;
    std::cout << std::endl;

    std::cout << "Start problem 3" << std::endl;
    int a3[20], na3, b3[20], nb3;
    std::cout << "Enter size of array a: ";
    std::cin >> na3;
    std::cout << "Enter array a: ";
    for (int i = 0; i < na3; i++) {
        std::cin >> a3[i];
    }
    std::cout << "Enter size of array b: ";
    std::cin >> nb3;
    std::cout << "Enter array b: ";
    for (int i = 0; i < nb3; i++) {
        std::cin >> b3[i];
    }
    if (policed(a3, na3, b3, nb3)) {
        std::cout << "a is policed by b" << std::endl;
    } else {
        std::cout << "a is not policed by b" << std::endl;
    }
    std::cout << "End problem 3" << std::endl;
    std::cout << std::endl;
    return 0;
}
