#include <iostream>
#include <cstring>
using namespace std;

/*
 * Задача 4: Да се намери думата, която най-често се повтаря в дадено изречение, и колко пъти се повтаря тя
 *
 * Примерен изход от изпълнението:
 * Enter sentence with up to 99 characters:
 * this bus ride is a long bus ride in a bus.
 * Found the word "this" 1 times.
 * Found the word "bus" 3 times.
 * Found the word "ride" 2 times.
 * Found the word "is" 1 times.
 * Found the word "a" 2 times.
 * Found the word "long" 1 times.
 * Found the word "bus" 3 times.
 * Found the word "ride" 2 times.
 * Found the word "in" 1 times.
 * Found the word "a" 2 times.
 * Found the word "bus" 3 times.
 * The most common word is "bus" and it was found 3 times.
 */
int main()
{
    char sentence[100];
    // each row is a word from the sentence
    // assumes we have at most 50 words
    // and each word contains at most 49 symbols
    char words[50][50];
    int wordCount = 0;
    // where we are in the sentence
    int sentIdx = 0;
    // where we are in the current word
    int wordIdx = 0;

    cout << "Enter sentence with up to 99 characters: "<<endl;
    cin.getline(sentence, 100);
    // 1. populate the word matrix
    while (sentence[sentIdx] != 0) {
        if (sentence[sentIdx] != ' ' && sentence[sentIdx] != '.') {
            // still the same word
            words[wordCount][wordIdx] = sentence[sentIdx];
            wordIdx++;
        } else {
            // terminate current word and prepare for the next one
            words[wordCount][wordIdx] = 0;
            wordCount++;
            wordIdx = 0;
        }
        sentIdx++;
    }
    if (sentence[sentIdx-1] != '.') {
        // The sentence didn't end with a fullstop,
        // handle this case correctly
        words[wordCount][wordIdx] = 0;
        wordCount++;
    }
    // check words have been read correctly
    for (int i=0; i < wordCount; i++) {
        cout << words[i] << endl;
    }

    // calculate word counts
    int wordCounters[50];
    for (int i = 0; i < wordCount; i++) {
        // compare word i to all other words
        wordCounters[i] = 0;
        for (int j=0; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                wordCounters[i]++;
            }
        }
    }
    // print word counts
    for (int i = 0; i < wordCount; i++) {
        cout << "Found the word \"" << words[i] << "\" "
            << wordCounters[i] << " times."<<endl;
    }

    // now find the most common word
    int maxCountIdx = 0;
    for (int i=1; i < wordCount; i++) {
        if (wordCounters[i] > wordCounters[maxCountIdx]) {
            maxCountIdx = i;
        }
    }
    // print final result
    cout << "The most common word is \"" << words[maxCountIdx]
         << "\" and it was found " << wordCounters[maxCountIdx] << " times."<<endl;
    return 0;
}
