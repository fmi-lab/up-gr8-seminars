#include <iostream>
#include <cstring>

/*
 * Solution to problem 3
 */
int neighbors[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool isValid (int x, int y, int n) {
    return x >= 0 && x < n && y >=0 && y < n;
}
void calculateBuildingSize (int map[100][100], bool visited[100][100], int n, int x, int y, int &size) {
    if (visited[x][y]) {
        return;
    }
    size++;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int newX = x + neighbors[i][0];
        int newY = y + neighbors[i][1];
        if (isValid(newX, newY, n) && !visited[newX][newY] && map[newX][newY] != 0) {
            calculateBuildingSize(map, visited, n, newX, newY, size);
        }
    }
}

void findLargestBuilding (int map[100][100], int n, int& entranceX, int& entranceY) {
    int maxSize = 0;
    bool visited[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 2 && !visited[i][j]) {
                // building entrance, check its size
                int currentSize = 0;
                calculateBuildingSize(map, visited, n, i, j, currentSize);
                if (currentSize > maxSize) {
                    maxSize = currentSize;
                    entranceX = i;
                    entranceY = j;
                }
            }
        }
    }
}

int main()
{
    int map[100][100];
    int n;
    std::cout << "Enter map size n=";
    std::cin >> n;
    std::cout << "Enter map: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> map[i][j];
        }
    }
    int leiaEntranceX;
    int leiaEntranceY;
    findLargestBuilding(map, n, leiaEntranceX, leiaEntranceY);
    std::cout << "Leia is in building with entrance at ("
        << leiaEntranceX << ", " << leiaEntranceY << ")" << std::endl;
    return 0;
}
