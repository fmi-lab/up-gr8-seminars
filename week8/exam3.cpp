/*
 * Решение на зад. 3 от контролното, но с функции
 */
#include <iostream>

bool hasAFriend (int x, int a[], int n) {
  for (int i=0; i < n; i++) {
    if (a[i] == x - 4 || a[i] == x + 4) {
      // found the friend of x
      return true;
    }
  }
  // only return false if none of the elements of a matched
  return false;
}

bool checkAllFriends (int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (!hasAFriend(a[i], a, n)) {
      // this person does not have a friend,
      // so the group cannot be all friends
      return false;
    }
  }
  // return true only if we have found a friend for each person
  return true;
}

int main () {
  int n;
  int a[10];
  std::cout << "Enter number of people: ";
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cout << "Enter height of person " << i+1 << ": ";
    std::cin >> a[i];
  }
  if (checkAllFriends(a, n)) {
    std::cout << "They can all be friends!" << std::endl;
  } else {
    std::cout << "They cannot be friends." << std::endl;
  }
  return 0;
}
