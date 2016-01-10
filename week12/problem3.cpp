/*
 * Задача 3:
 * Дадена е дъска nxn, на която са разположени m на брой черни фигури и един бял кон.
 * Считаме, че конят може да вземе някоя от фигурите, ако с един или повече ходове
 * може да достигне до нея, без да минава през клетки, заети от други фигури
 * (конят се движи Г-образно по стандартните за шаха правила).
 * Да се намери броя черни фигури, които конят може да вземе.
 */
#include <iostream>

int horseMove[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

bool isValid (int i, int j, int n) {
    return i >= 0 && i < n && j >=0 && j < n;
}

bool isReachableRec (int x, int y, int fromX, int fromY, bool used[][100], int n) {
    if (x == fromX && y == fromY) {
        return true;
    }
    used[fromX][fromY] = true;
    for (int i = 0; i < 8; i++) {
        int nextX = fromX + horseMove[i][0];
        int nextY = fromY + horseMove[i][1];
        if (isValid(nextX, nextY, n) && !used[nextX][nextY]) {
            if (isReachableRec(x, y, nextX, nextY, used, n)) {
                // found a path!
                return true;
            }
        }
    }
    // path was not found in any direction
    return false;
}

bool isReachable (int blackIdx, int horseX, int horseY, int blackCoords[][2], int m, int n) {
    // define it here, because the used cells need to be reset
    // when trying to reach the next black cell
    bool used[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            used[i][j] = false;
        }
    }
    for (int i = 0; i < m; i++) {
        if (i != blackIdx) {
            // mark black cells as unavailable
            used[blackCoords[i][0]][blackCoords[i][1]] = true;
        }
    }
    return isReachableRec(blackCoords[blackIdx][0], blackCoords[blackIdx][1], horseX, horseY, used, n);
}

int main() {
    int n, m, x, y;
    int blackCoords[100][2];
    std::cout << "Enter board size: ";
    std::cin >> n;
    std::cout << "Enter number of black figures: ";
    std::cin >> m;
    std::cout << "Enter black coordinates: ";
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y;
        blackCoords[i][0] = x;
        blackCoords[i][1] = y;
    }
    std::cout << "Enter white horse position: ";
    std::cin >> x >> y;
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (isReachable(i, x, y, blackCoords, m, n)) {
            count++;
        }
    }
    std::cout << count << " black figures are reachable from the white horse position." << std::endl;
    return 0;
}
