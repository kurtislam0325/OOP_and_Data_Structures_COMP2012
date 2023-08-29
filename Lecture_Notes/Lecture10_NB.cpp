#include <iostream>
using namespace std;

// void print(int x, int y) {}

// class Sentence {
//     private:
//         int x;
//     public:
//         Sentence(): x('h') { std::cout << "Sentence()\n";};
//         Sentence(int x) {this->x = x;}
// };

// class Word: public Sentence {
//     private:
//         int x;
//         float y;
//     public:
//         Word() = default;
//         Word(int x, float y) {this->x = x; this->y = y;}
// };

class X {
    public:
        int a;
        int b;
};

int main() {
    int n = 1;
    int* x = new int[n];
    x[0] = 1;
    for (int i = 0; i < n; i++) {
        cout << x[i] << endl;
    }
    n++;
    x = new int[n++];
    x[n] = 2;
    for (int i = 0; i < n; i++) {
        cout << x[i] << endl;
    }


    

    return 0;
}