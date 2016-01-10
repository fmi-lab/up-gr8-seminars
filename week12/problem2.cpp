/*
 * Задача 2. Дадена е правоъгълна мрежа от клетки с целочислени стойности.
 * Клетките с еднакви стойности, които са свързани, т.е. са съседни в хоризонтално
 * или вертикално направление, образуват област.
 * Да се напише функция, която намира броя на областите в мрежата.
*/

#include <iostream>
using namespace std;

int directions[4][2] = {/*left*/{-1, 0}, /*right*/{1, 0}, /*up*/ {0, 1}, /*down*/{0, -1}};

/*
 * Checks whether (x, y) is a valid index in a matrix with dimensions mxn
 */
bool isValid (int x, int y, int m, int n) {
    return x >= 0 && x < m && y >=0 && y < n;
}

/*
 * Marks as visited all cells is the region that contains cell (i, j)
 */
void visitRegion(int maze[100][100], bool visited[100][100], int m, int n, int i, int j) {
	visited[i][j] = true;

	for (int k=0; k<4; k++) {
		int newI = i + directions[k][0], newJ = j + directions[k][1];
		if (isValid(newI, newJ, m, n) &&
            !visited[newI][newJ] &&
            maze[i][j] == maze[newI][newJ]) {
                visitRegion(maze, visited, m, n, newI, newJ);
        }
	}
}

int countRegions(int maze[100][100], int m, int n) {
    int count = 0;
    bool visited[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            if (!visited[i][j]) {
                visitRegion(maze, visited, m, n, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
	int maze[100][100];
	int m,n;
	int regionsCount = 0;
    std::cout << "Enter the size of the map: ";
	std::cin >> m >> n;
	std::cout << "Enter map: ";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> maze[i][j];
		}
	}
    std::cout << "The map contains " << countRegions(maze, m, n) << " regions" << std::endl;
    return 0;
}
