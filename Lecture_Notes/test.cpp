#include <iostream>
using namespace std;

// class Number {
//     int n;
//     public:
//         Number(int n): n(n) {}
//         const Number& add(Number& number) {
//             return Number(n + number.n);
//         }
// };

class A {
    int x;
    public:
        A(): x(0) {
            cout << "A's def" << endl;
            cout << x << endl;
        }
        ~A() {
            cout << "A's tor" << endl;
        }
};

int main() {
    // Number n1(10), n2(20);
    // Number n3 = n1.add(n2);

    cout << "Construct A1" << endl;
    // A objA1();

    int c = 1;
    [c]() mutable->int& {++c; return c;} ();

    int d = 5;
    bool e = [d]() -> bool {return (d == 10);};
}