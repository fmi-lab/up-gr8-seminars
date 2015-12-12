/*
 * ЗЗС 6, зад. 7:
 * Да се дефинира функцията bool subarrays (int *arrays[],int npointers, int arrlengths[]).
 * Масивът arrays съдъръжа npointers на брой указатели към масиви от цели числа.
 * i-тият масив има големина arrlengths[i]. Функцията да връща истина, ако поне един от масивите е подмасив на друг масив.
 * Масивът a наричаме подмасив на b, ако заетата от a памет е част от заетата от b памет
*/
#include <iostream>

bool subarrays (int *arrays[],int npointers, int arrlengths[]) {
    for (int i = 0; i < npointers; i++) {
        // the current array starts at address arrays[i]
        // and has lendth of arrlengths[i]
        int *currentStart = arrays[i];
        int *currentEnd = currentStart + arrlengths[i];
        // check if the current array is a subarray of any of the others
        // current is a subarray of an array b iff current begins after b begins
        // and current ends before b ends
        for (int j = 0; j < npointers; j++) {
            int *bStart = arrays[j];
            int *bEnd = arrays[j] + arrlengths[j];
            if ( (i!=j) && (currentStart >= bStart) && (currentEnd <= bEnd)) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // ensure we have some large enough piece of
    // consecutive array elements to test the function
    int all[100];
    for (int i = 0; i < 100; i++) {
        all[i] = i;
    }
    int *arrays[10];
    int lens[10];
    int narrays;
    std::cout << "Enter number of test arrays (<= 10): ";
    std::cin >> narrays;
    // each array will be specified by where it begins with respect to the big array
    // and what length it has.
    // e.g. we want two arrays, one starts at the first element of all and has length 5,
    // the other starts at the third element of all and has length 4
    for (int i = 0; i < narrays; i++) {
        int offset;
        std::cout << "Enter offset where array " << i << " begins: ";
        std::cin >> offset;
        arrays[i] = all + offset;
        std::cout << "Enter length of array " << i << ": ";
        std::cin >> lens[i];
    }
    if (subarrays(arrays, narrays, lens)) {
        std::cout << "There is an array that is a subarray of another" << std::endl;
    } else {
        std::cout << "There are no subarrays among the chosen arrays" << std::endl;
    }
    return 0;
}
