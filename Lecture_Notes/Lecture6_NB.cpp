#include <iostream>
using namespace std;

class Word {
    private:
        int frequency;
        char* str;
    public:
        Word() {frequency = 0; str = nullptr;}

        explicit Word(int s) {
            cout << "explicit conversion1" << endl;
        }

        explicit Word(const char* s) {
            cout << "explicit conversion2" << endl;
        }


        void print() const {
            if(str) cout << frequency << " " << str << endl;
        }

        void set(int n, const char* s) {
            frequency = n;
            if (str) delete [] str; // prevent memory leak
            if (s) { str = new char[strlen(s)+1]; strcpy(str, s);}
            else str = nullptr; // prevent dangling pointer
        }
};

int main() {
    Word w1;
    w1.set(1, "comp2011");
    Word w2 {2.22};
    Word w3 = "comp2012";
    return 0;
}