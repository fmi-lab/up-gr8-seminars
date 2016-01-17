#include <iostream>
#include <cstring>

struct Mixed {
    char c;
    double d;
    int i;
    char arr[30];
};

struct Human {
    char name[30];
    int age;
    Human* bestFriend;
};

void read (Mixed& a) {
    // note the parameter a is a reference to a struct
    // if it's not a reference, we only change the local variable
    std::cin >> a.c >> a.d >> a.i;
    std::cin.ignore();
    std::cin.getline(a.arr, 30);
}

void print (const Mixed& a) {
    // the const is there to remind us that the print function
    // should not change its arguments
    std::cout << a.c << " " << a.d << " " << a.i << std::endl;
    std::cout << a.arr << std::endl;
}

// overloading the print function
void print (const Human& h) {
    std::cout << "Student: " << h.name << std::endl;
    std::cout << "Age: " << h.age << std::endl;
    if (h.bestFriend != NULL) {
        std::cout << "Best friend's name is: " << h.bestFriend->name << std::endl;
    } else {
        std::cout << "No best friend information available." << std::endl;
    }
}

void checkStructPadding(Mixed& m) {
    // check field addresses
    // cast all to char* so that we can see the difference in bytes
    char* pc = &m.c;
    char* pd = (char*) &m.d;
    char* pi = (char*) &m.i;
    char* parr = (char*) &m.arr;

    std::cout << "Struct starts at: " << &m << std::endl;
    // note the double doesn't start immediately after the char - there is padding
    std::cout << "The double starts " << pd - pc << " bytes after the char" << std::endl;
    std::cout << "The int starts " << pi - pd << " bytes after the double" << std::endl;
    std::cout << "The array starts " << parr - pi << " bytes after the int" << std::endl;
}

int main()
{
    // declare a variable of type Mixed
    Mixed m;
    std::cout << "Before assigning any values: " << std::endl;
    print (m);
    // assign values to its fields
    m.c = 'a';
    m.d = 8.5;
    m.i = 3;
    strcpy(m.arr, "test");

    std::cout << "Initial values in struct: " << std::endl;
    print(m);
    std::cout << std::endl;

    std::cout << "Enter new values: ";
    read(m);
    std::cout << "The new values are: " << std::endl;
    print(m);
    std::cout << std::endl;

    std::cout << "Printing padding in the memory: " << std::endl;
    checkStructPadding (m);
    std::cout << std::endl;

    std::cout << "Change struct through a pointer: " << std::endl;
    // pointer to a variable of type struct
    Mixed* pm = &m;
    // access values through the pointer
    pm->c = 'b';
    pm->d = 10.5;
    pm->i = 4;
    strcpy(pm->arr, "test2");
    std::cout << "The new values are: " << std::endl;
    print(m);
    std::cout << std::endl;

    Human hermione, harry, draco;
    hermione.age = 17;
    strcpy(hermione.name, "Hermione");
    harry.age = 16;
    strcpy(harry.name, "Harry");

    hermione.bestFriend = &harry;
    harry.bestFriend = &hermione;

    draco.age = 17;
    strcpy(draco.name, "Draco");
    // Draco has no best friend
    draco.bestFriend = NULL;

    // array of structs
    Human students[3] = {hermione, harry, draco};
    std::cout << "Printing students data: " << std::endl;
    for (int i = 0; i < 3; i++) {
        print(students[i]);
    }

    return 0;
}
