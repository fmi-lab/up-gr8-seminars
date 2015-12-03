#include <iostream>

// Basic pointer examples
int main () {
  int a = 5;
  int *pa = &a;
  // Указателят също е променлива, записана някъде в паметта -> също има адрес
  int **ppa = &pa;

  std::cout << a << std::endl; // 5

  // различна стойност на различните компютри,
  // но винаги някакво шестнайсетично число - номер на клетка в паметта
  // например на моята машина в момента е 0x7ffc82fd60ec
  std::cout << pa <<std::endl;
  // стойността, записана на този адрес
  std::cout << *pa << std:: endl;

  // друг адрес - 0x7ffc82fd60f0
  std::cout << ppa << std::endl;
  std::cout << *ppa << std::endl; // стойността, записана на адрес ppa -> pa
  std::cout << **ppa << std::endl; // стойността, записана на адреса, към който сочи указател ppa -> 5
  return 0;
}
