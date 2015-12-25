#include <iostream>
/*
 * Даден е полином  чрез коефициентите му и реално число x.
 * Коефициентите са представени чрез масив coef[], в който coef[0] е старщият коефициент
 * (т.е. този пред най-високата степен), а coef[n-1] - свободният член.
 * Да се напише рекурсивна функция, която пресмята стойността на полинома при аргумент х.
 * База: полином константа, p0 (x) = c
 * Стъпка: p_n(x) = p_(n-1)(x) * x + c
 */
double polynomial (double* coef, int degree, double x) {
    if (degree == 0) {
        return coef[0];
    }
    return polynomial(coef, degree - 1, x) * x + coef[degree];
}

int main()
{
    // 4*x^3 + 3*x^2 + 1
    // четири коефициента -> степента на полинома е 3
    double poly[] = {4, 3, 0, 1};
    double x = 2;
    std::cout << "p(" << x << ") = " << polynomial(&poly[0], 3, x);
    std::cout << std::endl;
}
