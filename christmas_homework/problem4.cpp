#include <iostream>
#include <cstring>

/*
 * Solution to problem 4
 */
void permuteRec (char* symbols, int len, char perm[], int currIdx, bool used[]) {
    if (len == currIdx) {
        // no more symbols to use, print permutation
        perm[currIdx] = 0;
        std::cout << perm << std::endl;
        return;
    }
    // each of the unused elements is a candidate for the next position in the permutation
    for (int i = 0; i < len; i++) {
        if (!used[i]) {
            // use symbols[i] for currIdx
            perm[currIdx] = symbols[i];
            used[i] = true;
            // choose the rest of the permutation
            permuteRec(symbols, len, perm, currIdx + 1, used);
            // on the next iteration symbols[i+1] will be used for currIdx
            // and symbols[i] will be unused
            // so we reset it here
            used[i] = false;
        }
    }
}
void permute (char symbols[], int len) {
    char permutation[27];
    bool used[27];
    for (int i = 0; i < len; i++) {
        used[i] = false;
    }
    permuteRec(symbols, len, permutation, 0, used);
}

int main()
{
    char symbols[27];
    std::cout << "Enter the symbols used: ";
    std::cin.getline(symbols, 27);
    std::cout << "The possible combinations are: " << std::endl;
    permute(symbols, strlen(symbols));
    return 0;
}
