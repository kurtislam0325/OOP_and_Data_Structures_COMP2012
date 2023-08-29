#include <iostream>
using namespace std;

class Base {};
class Derived: protected Base {};

int main() {
    const char* a;
    a = new char[9];
    int c = 1;
    

    [&c]() mutable->int& {++c; return c;}();
    cout << b << c << endl;
    
    return 0;
} 