#include <iostream>
using namespace std;

//lambdas expression
int main() {
    int a = 1, b = 2;
    char c1 = 200;

    // cout << [a](int x) -> int{ return a += x; } (20) << endl; // Error!
    cout << [b](int x) mutable -> int { return b *= x; } (20) << endl; // OK!

    cout << "a = " << a << "\tb = " << b << endl;
    cout << c1;
    return 0;
}