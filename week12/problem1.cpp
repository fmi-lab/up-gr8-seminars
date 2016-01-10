/*
 * Задача 1. Ханойски кули
 * Да се напише функция, която дава решение на задачата за Ханойските кули.
 * Функцията приема единствен аргумент n - броят на дисковете, които искаме да
 * преместим, и да отпечатва на екрана последователността, в която трябва да
 * местим дискове от едно колче на друго.
 * Пример: n = 3, искаме да преместим три диска от колче А на колче B
 * Move a disk from A to B
 * Move a disk from A to C
 * Move a disk from B to C
 * Move a disk from A to B
 * Move a disk from C to A
 * Move a disk from C to B
 * Move a disk from A to B
 */

#include <iostream>
void moveDisk(char from, char to) {
    std::cout << "Move a disk from " << from << " to " << to << std::endl;
}

/*
 * 1. If there's only one disk (n=1) - just move it and return from the function
 * 2. Otherwise:
 *   2.1. Recursively move the top (n-1) disks from A to C (using B as helper)
 *   2.2. Move the bottom disk from A to B
 *   2.3. Recursively move back the top (n-1) disks from C to B (using A as helper)
 */
void hanoiRec (int n, char from, char to, char helper) {
    if (n == 1) {
        moveDisk(from, to);
        return;
    }
    hanoiRec(n-1, from, helper, to);
    moveDisk(from, to);
    hanoiRec(n-1, helper, to, from);
}

void hanoi (int n) {
    hanoiRec(n, 'A', 'B', 'C');
}
int main() {
    int n;
    std::cout << "Enter n=";
    std::cin >> n;
    hanoi(n);
    return 0;
}
