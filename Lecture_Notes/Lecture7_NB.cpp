#include <iostream>
#include <cstring>
using namespace std;

class Word {
	private:
		int frequency;
		char* str; // dynamic cstring
	public:
	 	// default constructor
		Word () {
			cout << "Word()" << endl;
			frequency = 0; str = nullptr;
		}
		// Another Constructor
		Word(int n, const char* s) { 
			cout << "Word(int n, const char* s)" << endl;
			str = nullptr; set(n, s); // Why we need to have a str = nullptr?
		} 							  // speed increase since set function do not need to do the memory deallocation																					  
		// if we only have this constructor(default constructor disappeared), 
		// it will trigger error when we dont pass the value like Word w1,
		// since the complier now cannot provide its default constructor if we declare one

		// conversion constructor - invoke with 1 actual parameter	
		Word(const char* s) { 
			cout << "Word (const char* s)" << endl;
			str = nullptr; set(0, s);
		} 
		Word(char c) { // conversion constructor with char input
			cout << "Word(char c)" << endl;
			frequency = 0;
			str = new char[2];
			str[0] = c;
			str[1] = '\0';
		}
		// copy constructor
		Word(const Word& w) {
			cout << "Word(const Word& w)" << endl;
			frequency = w.frequency;
			str = w.str; // copy the address only - shallow copy

			if (w.str) {
				str = new char[strlen(w.str) + 1];
				strcpy(str, w.str);
			} else str = nullptr; // copy the whole content - deep copy
		}

		void set(int n, const char* s) {
			frequency = n;
			if (str) delete [] str; // prevent memory leak
			if (s) {str = new char[strlen(s)+1]; strcpy(str, s);}
			else str = nullptr;
		} 

		// Accessor
		void print() const { 
			if (str)
				cout << frequency << " " << str << endl;
		}
};

void print_word(Word w) {w.print();};
Word get_word() {
	Word temp("programming");
	return temp;
}

int main() {
	// Word w1;
	// w1.set(1, "comp2011");
	// w1.print();

	// Word* wptr = new Word; //Dynamic object initialization without set -> also invoke instructor

	Word w4('c'); w4.print();
	Word w5 {w4};
	Word w3("hkust"); w3.print();
	Word w1(1, "comp2012"); // Another Constructor
	print_word(w1);

	print_word("comp2011"); // Use the conversion constructor
	get_word();

    return 0;
}