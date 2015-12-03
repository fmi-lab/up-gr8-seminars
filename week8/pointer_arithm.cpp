// Аритметични операции с указатели

#include <iostream>

int main () {
  int a = 653123;
  short b = 3443;
  char c = 'x';

  int *pa = &a;
  short *pb = &b;
  char *pc = &c;

  // разликата е 4 байта, което е 1 int
  int *pa1 = pa + 1;
  std::cout << "Int pointers: ";
  std::cout << pa << " " << pa1 << std::endl;

  // разликата е 2 байта, което е 1 short
  short *pb1 = pb + 1;
  std::cout << "Short pointers: ";
  std::cout << pb << " " << pb1 << std::endl;

  char *pc1 = pc + 1;
  std::cout << "Char pointers: ";
  // ако няма (void*), cout приема, че pc сочи не към един символ,
  // а към цял низ, и се опитва да отпечата целия низ
  // std::cout << pc << " " pc1 << std::endl; // недефинирано поведение!
  std::cout << (void*)pc << " " << (void*)pc1 << std::endl;
  std::cout << std::endl;

  // ако разглеждаме pa като указател към int променлива,
  // *pa ще гледа автоматично 4 байта - колкото е един int 
  std::cout << "pa as an int: " << *pa << std::endl;
  // можем да контролираме как да тълкуваме записаните на даден адрес данни -
  // трябва ни указател към друг тип
  std::cout << "pa as a short: " << *((short*) pa) << std::endl;
  // а ако искаме само първия байт - указател към тип char
  // и тъй като го тълкуваме като char - отпечатва се
  // символът със съответния ASCII код
  std::cout << "pa as a char: " << *((char*) pa) << std::endl;
  // ако искаме стойността на самия код - още един cast обратно към int
  std::cout << "pa as ascii code: " << (int) *((char*) pa) << std::endl;
  std::cout << std::endl;

  // разликата между два указателя се определя от типа им:
  // 4 bytes = 1 int
  std::cout << "Int diff: " << pa1 - pa << std::endl;
  // 4 bytes = 4 chars
  std::cout << "Char diff: " << (char*)pa1 - (char*)pa << std::endl;
  return 0;
}
