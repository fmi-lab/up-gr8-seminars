/*
 * ЗЗС 6, зад. 8:
 * Да се дефинира функцията bool commonel (int *arrays[],int npointers, int arrlengths[]).
 * Масивът arrays съдъръжа npointers на брой указатели към масиви от цели числа.
 * i-тият масив има големина arrlengths[i]. Функцията да връща истина, ако има поне едно число x,
 * което е елемент на всички масиви. Ако има такъв елемент, стойността му да бъде записана в допълнителен
 * параметър към функцията.
*/
#include <iostream>

bool contains (int element, int* array, int arrlen) {
    for (int i = 0; i < arrlen; i++) {
        if (element == array[i]) {
            return true;
        }
    }
    return false;
}
bool allContain (int element, int *arrays[], int npointers, int arrlengths[]) {
    for (int i = 0; i < npointers; i++) {
        if (!contains (element, arrays[i], arrlengths[i])) {
            // some array does not contain the element
            return false;
        }
    }
    return true;
}

bool commonel (int *arrays[],int npointers, int arrlengths[], int& common) {
    // if they have a common element, it must be an element of the first array
    // so check if any of the elements of the first array belongs to all others
    for (int i = 0; i < arrlengths[0]; i++) {
        int element = arrays[0][i];
        if (allContain(element, arrays, npointers, arrlengths)) {
            common = element;
            return true;
        }
    }
    // no element was found in all arrays
    return false;
}

int main()
{
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[3] = {5, 3, 8};
    int array3[2] = {11, 5};
    int lens[3] = {5, 3, 2};
    int *all[3] = {array1, array2, array3};
    int common;
    // note that common will be assigned a value only if the function returns true!
    if (commonel(all, 3, lens, common)) {
        std::cout << "They have a common element " << common << std::endl;
    } else {
        std::cout << "They do not have a common element" << std::endl;
    }
    return 0;
}
