#include <iostream>
using namespace std;

int main () {
    double x,y;
    cout<<"Enter x,y: ";
    cin>>x>>y;
    bool isInRect1 = x >=0 && x <=2 && y >= 0 && y <= 5;
    bool isInRect2 = x >= 2 && x <= 8 && y >= 2 && y <= 5;
    bool isInCircle = x * x + (y - 5) * (y - 5) <= 2 * 2;
    if (isInRect1 || isInRect2 || isInCircle) {
        cout<<"Still in Azkaban :("<<endl;
    } else {
        cout<<"Harry escaped!"<<endl;
    }
	return 0;
}