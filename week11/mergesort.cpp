#include <iostream>
/*
 * Да се имплементира алгоритъма за сортиране чрез сливане (mergesort).
 * Идея:
 *     1) разделяме несортирания масив на две равни по големина половини
 *     2) сортираме двете половини (чрез рекурсивно извикване)
 *     3) сливаме сортираните половини по показвания вече merge метод
 */

void merge(int* arr1, int length1, int* arr2, int length2) {
	int temp[100];
	int idx1 = 0, idx2 = 0, tmpidx = 0;
	while (idx1 < length1 && idx2 < length2) {
		// both arrays have elements left
		if (arr1[idx1] < arr2[idx2])
			temp[tmpidx++] = arr1[idx1++];
		else
			temp[tmpidx++] = arr2[idx2++];
	}
	while (idx1 < length1) {
		temp[tmpidx++] = arr1[idx1++];
	}

	while (idx2 < length2) {
		temp[tmpidx++] = arr2[idx2++];
	}

	// return temp to arr1 and arr2
	for (int i=0; i < length1; i++) {
		arr1[i] = temp[i];
	}
	for (int i=0; i < length2; i++) {
		arr2[i] = temp[length1 + i];
	}
}

void mergesort(int* arr, int len) {
	if (len <= 1) {
		return;
	}
	int len1 = len/2, len2 = len - len1;
	mergesort(arr, len1);
	mergesort(arr + len1, len2);
	merge(arr, len1, arr + len1, len2);
}

int main()
{
    int elements[10];
    int n;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    std::cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> elements[i];
    }
    mergesort(elements, n);
    std::cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
