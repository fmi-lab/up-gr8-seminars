/*
 * Базови примери за рекурсия. Връзка с индуктивна дефиниция:
 * 1) база на индукцията (за кои стойности знаем резултата директно)
 * 2) индукционна стъпка - как да сведем задачата до по-малки стойности на входа
 */

#include <iostream>

/*
 * Намиране на n-ти член на аритметична прогресия с първи член a0 и разлика d.
 * n=0 -> an = a0
 * n>0 -> an = a_(n-1) + d
 */
int arithmProgression (int a0, int d, int n) {
    if (n == 0) {
        return a0;
    }
    return arithmProgression(a0, d, n-1) + d;
}

/*
 * Отпечатване на масив в обратен ред, използвайки рекурсивна функция
 * база: масив с един елемент - просто го отпечатваме този елемент
 * ако масивът е с дължина > 1 - отпечатваме първо остатъка и накрая първия елемент на масива
 */
void printArr(int *arr, int len) {
    if (len > 1) {
        printArr(arr + 1, len - 1);
        std::cout << *arr << " ";
    }
}

/*
 * Пресмятане на n-тото число на Фибоначи.
 * база: n = 0, n = 1 -> fib_n = 1
 * стъпка: fib_n = fib_(n-1) + fib_(n-2)
 */
int fib (int n) {
    std::cout << "Calculating Fib" << n << std::endl;
    if (n == 0 || n == 1) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

/*
 * Пресмятане на функцията на Акерман.
 * база: m = 0, ackermann(0, n) = n + 1
 * стъпка:
 *     ако n = 0, ackermann(m, 0) = ackerman(m-1, 1)
 *     иначе ackermann(m, n) = ackermann(m-1, ackermann(m, n-1))
 */
int ackermann (int m, int n) {
    std::cout << "Calculating Ackermann("
            << m << ", " << n << ")" << std::endl;

    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return ackermann(m - 1, 1);
    }
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }
    std::cout << "Arithmetic progression: " << arithmProgression(5, 2, 4) << std::endl;
    std::cout << "Print array: ";
    printArr(&arr[0], 5);
    std::cout << std::endl;
    std::cout << "Fibonacci example: (n = 4)" << std::endl;
    std::cout << "The result is " << fib(4) << std::endl;
    std::cout << std::endl;
    std::cout << "Ackermann test (m=2, n=2): " << std::endl;
    std::cout << "The result is " << ackermann(2, 2) << std::endl;
    return 0;
}
