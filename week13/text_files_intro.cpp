#include <iostream>
#include <fstream>
#include <cstring>

struct Point {
    int x;
    int y;
};

// print to either file or stdout
void print (const Point& p, std::ostream& out) {
    out << p.x << " " << p.y;
}

// can be used to read both from file and stdin
std::istream& read (Point& p, std::istream& in) {
    in >> p.x >> p.y;
    return in;
}

int main () {
    Point arr[10];
    int n;
    std::cout << "Enter number of points: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter point " << i << ": ";
        read(arr[i], std::cin);
    }
    // when using file streams, always close them!
    // file.open("...");  <read / write from file >; file.close()
    std::ofstream out;
    out.open("points.txt");
    for (int i = 0; i < n; i++) {
        print(arr[i], out);
        out << std::endl;
    }
    out.close();

    Point arr2[10];
    std::ifstream in;
    in.open("points.txt");
    int idx = 0;
    while (read(arr2[idx], in)) {
        idx++;
    }
    in.close();
    std::cout << "After assign: " << std::endl;
    for (int i = 0; i < idx; i++) {
        print(arr2[i], std::cout);
        std::cout << std::endl;
    }

    return 0;
}
