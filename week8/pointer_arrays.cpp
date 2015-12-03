#include <iostream>

int main() {
  int a[10];
  for (int i=0; i < 10; i++) {
    a[i] = i;
  }

  // а е адресът на първия елемент от масива
  // а == &a[0]
  std::cout << a << std::endl;
  std::cout << &a[0] << std::endl;
  // тогава *a е стойността на първия елемент:
  std::cout << a[0] << " " << *a << std::endl;
  std::cout << std::endl;

  // i-тият елемент е на адрес a + i,
  // понеже елементите на масива винаги са последователно в паметта
  std::cout << "Array elements are at consecutive addresses: ";
  std::cout << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << "address of a[" << i << "]= " << a + i << std::endl;
  }

  // т.е. стойността на i-тия елемент e *(a+i)
  // странен, но коректен запис: i[a]
  // a[i] == *(a+i) == *(i+a) == i[a]
  std::cout << "Weird syntax works: ";
  std::cout << a[5] << " " << * (a + 5) << " " << 5[a] << std::endl;
  std::cout << std::endl;

  // двумерни масиви: масив от масиви (по редове)
  // int m[2][3] всъщност е масив с два елемента, всеки от които
  // е масив с три елемента
  // и по аналогия с едномерните масиви, m е указател към първия ред
  // int m[2][3] <---> int **m

  int m[2][3];
  for (int i=0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      m[i][j] = 3*i + j;
    }
  }

  // къде започва ред 0:
  std::cout << "Row 0 is at address: " << m << std::endl;
  // къде започва ред 1:
  std::cout << "Row 1 is at address: " << m + 1 << std::endl;
  // адрес на клетка m[1][1]:
  // 1) m+1 ни праща на адреса на реда
  // 2) *(m+1) - "влизаме" в съответния ред
  // 3) *(m+1) + 1 - отиваме до адреса на съответната клетка в реда
  std::cout << "Address of m[1][1]: " << *(m+1) + 1 << std::endl;
  // m[i][j] <---> стойността на позиция j в ред m[i] <---> * (m[i] + j)  <---> * (*(m + i) + j)
  std::cout << m[1][1] << " " << *(*(m+1) + 1) << std::endl;
  return 0;
}
