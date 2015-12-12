/*
 * ЗЗС 6, зад. 1: задача 3.55.
 * Дадена е квадратна таблица An×n (1 ≤ n ≤ 30) от низове, съдържащи думи с максимална дължина 6.
 * Да се напише програма, която проверява дали изречението, получено след конкатенацията на думите
 * от главния диагонал (започващо от горния ляв ъгъл), съвпада с изречението, получено след конкатенацията
 *  на думите от вторичния главен диагонал на A (започващо от долния ляв ъгъл).
*/
#include <iostream>
#include <cstring>

void concatMainDiagonal (char A[30][30][7], int n, char result[]) {
    for (int i = 0; i < n; i++) {
        strcat(result, A[i][i]);
    }
}
void concatSecondaryDiagonal (char A[30][30][7], int n, char result[]) {
    for (int i = n-1; i >= 0; i--) {
        strcat(result, A[i][n-i-1]);
    }
}
int main()
{
    char A[30][30][7];
    int n;
    char diag1[181] = "";
    char diag2[181] = "";
    std::cout << "Enter matrix size: ";
    std::cin >> n;
    std::cin.ignore();
    for (int i=0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin.getline(A[i][j], 7);
        }
    }
    concatMainDiagonal(A, n, diag1);
    concatSecondaryDiagonal(A, n, diag2);
    if (strcmp(diag1, diag2) == 0) {
        std::cout << "The diagonals are equal!" << std::endl;
    } else {
        std::cout << "The diagonals don't match" << std::endl;
    }
    return 0;
}
