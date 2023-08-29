// struct Person {
//     char* name; // CString:
//                 // Option 1: char name[20] <-- static memory allocation
//                 // Option 2: char* name <-- dynamic memory allocation
//     int age;

//     void print() {cout << name << " " << age << endl;}
// };

class Person {
    private:
        char* name; // CString:
                    // Option 1: char name[20] <-- static memory allocation
                    // Option 2: char* name <-- dynamic memory allocation
        int age;

    public:
        // default constructor
        Person();
        // constructor
        Person(const char* n, int a);

        // destructor: to avoid memory leak 
        ~Person();

        // mutator: change data members
        void set(const char* n, int a);

        // accessor: read data members only (const function) 
        void print() const;

        // function inside class body --> inline function(inline keyword optional)
};
