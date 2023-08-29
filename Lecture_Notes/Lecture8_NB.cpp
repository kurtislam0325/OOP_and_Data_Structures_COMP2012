#include <iostream>
#include <cstring>
using namespace std;

// class X {
//     private:
//         int a;
//     public:
//         X() {cout << "X()" << endl;}
//         X(const X& other) {cout << "const X& other" << endl;}
// };

class Y {
    private:
        int a;
    public:
        Y() {cout << "Y()" << endl;}
        Y(const Y& other) {cout << "const Y& other" << endl;}
};

class XY {
    private:
        X x;
        Y y;
    public:
        XY() {cout << "XY()" << endl;}
        XY(const XY& other)
        : x(other.x), y(other.y)
        {
            // x = other.x;
            // y = other.y;
        }
};

class Word {
	private:
		int frequency;
		char* str;
	public:
		Word(const char*s, int f = 1) {
			frequency = f; str = new char[strlen(s)+1]; strcpy(str, s);
			cout << "conversion" << endl;
		}
		Word(const Word& w): Word(w.str, w.frequency) {
			cout << "copy" << endl;
		}
};

class X {
    public:
        X() {cout << "X()" << endl;}
        ~X() {cout << "~X()" << endl;}
};

int main() {
    X x();
	Word w1("s2");
	return 0;
}

// int main() {
//     XY some1;
//     XY some2(some1);
//     return 0;
// }