#include<iostream>
#include<cstring>
using namespace std;

template <class T>
class Arithmetic
{
    private:
        T a;
        T b;
    public:
        Arithmetic() = default;
        Arithmetic(T a, T b): a(0), b(0) {};
        T add();
        T sub();
};

class A
{
    private:
        int a;
        int b;
    public:        
        A(int a, int b): a(a), b(b) {};
        void print() { cout << a << " " << b << endl;}
};

int main() {

    A* ptr = new A(2, 3); ptr->print();
    
    return 0;
}
