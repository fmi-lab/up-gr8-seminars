#include <iostream>
#include <cmath>

/*
 * Solution to problem 2
 */
struct Point {
    double x;
    double y;
    double z;
};
struct Planet {
    Point coord;
    double mass;
};

double dist (Point& a, Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y) +
                (a.z - b.z) * (a.z - b.z));
}

double calculateFitness(Point& target, Planet planets[], int numPlanets) {
    double result = 0;
    for (int i = 0; i < numPlanets; i++) {
        result += planets[i].mass * dist(target, planets[i].coord);
    }
    std::cout << "The fitness of " <<
    "(" << target.x << ", " << target.y << ", " << target.z <<
    ") is " << result << std::endl;
    return result;
}

double maxFitness (Planet planets[], int numPlanets, Point& cubeVertex, int cubeSide, Point& result) {
    Point currentPoint;
    double bestFitness = 0, currentFitness;
    for (int i = 0; i <= cubeSide; i++) {
        currentPoint.x = cubeVertex.x + i;
        for (int j = 0; j <= cubeSide; j++) {
            currentPoint.y = cubeVertex.y + j;
            for (int k = 0; k <= cubeSide; k++) {
                currentPoint.z = cubeVertex.z + k;
                currentFitness = calculateFitness(currentPoint, planets, numPlanets);
                if (currentFitness > bestFitness) {
                    result = currentPoint;
                    bestFitness = currentFitness;
                }
            }
        }
    }
    return bestFitness;
}

int main()
{
    Planet planets[8];
    planets[0].coord.x = 0.1;
    planets[0].coord.y = 0.1;
    planets[0].coord.z = 0.1;
    planets[0].mass = 2;

    planets[1].coord.x = 4.9;
    planets[1].coord.y = 0;
    planets[1].coord.z = 0;
    planets[1].mass = 1;

    planets[2].coord.x = 0;
    planets[2].coord.y = 3.7;
    planets[2].coord.z = 0;
    planets[2].mass = 1;

    Point cubeStart;
    cubeStart.x = 1;
    cubeStart.y = 3;
    cubeStart.z = -2;
    int cubeSide = 4;
    Point bestJump;
    double best = maxFitness(planets, 3, cubeStart, cubeSide, bestJump);
    std::cout << "The best point is (" <<
     bestJump.x << ", " << bestJump.y << ", " << bestJump.z <<
      ") and has a fitness of " << best << std::endl;
    return 0;
}
