// Review of Class and Struct. This is an extra example from Lecture

#include <iostream>
#include <string>
#include "Lecture2_NB.h"

using namespace std;

//Seperate Compliation

// default constructor
Person::Person() {name = nullptr; age = 0;} 
// constructor
Person::Person(const char* n, int a) {
    name = nullptr; age = 0; // this because we check the status of name below,
                             // if we do not assign nullptr to name first, name will be sth 
                             // that the below if-statement will return true;
    set(n, a);
} 

// destructor: to avoid memory leak 
Person::~Person() {delete [] name;} 

// mutator: change data members
void Person::set(const char* n, int a) { 
    if (name) delete [] name; //avoid memory leak if we re-declare the name
    
    name = new char[strlen(n) + 1]; // +1 is for the null character
    strcpy(name, n);
    age = a;
}

// accessor: read data members only (const function) 
void Person::print() const {cout << name << " " << age << endl;}

// function inside class body --> inline function(inline keyword optional)

int main() {
    Person p; // define object

    // Below cannot use since the info become private:
        // p.name = new char[20];
        // strcpy(p.name, "Amy");
        // p.age = 100;

        // Person *personPtr = &p;
        // cout << (*personPtr).name << endl; // Deference notation
        // cout << personPtr->name << endl; // "Point" notation

    p.set("Amy", 100);
    p.set("Bob", 10); // since we delcare twice, we need (if(name) delete [] name) to avoid memory leak

    p.print();

    return 0;
}