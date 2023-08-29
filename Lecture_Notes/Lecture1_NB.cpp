#include <iostream>
using namespace std;

//Pointer, Reference, Initializer, Range-for.

// void testConstRef(const int& j) {
//     j += 10;
// }

void func1(int* p1) { (*p1)++; }
void func2(int& ri) { ri++; }

void reviewOfReference() {
    //Review of Reference variable

    int j = 1;
    int q = 2;
    int& r = j;

    r = 2;
    cout << r << j << endl;

    int k = 50;
    r = k;
    cout << r << k << j << endl;

    int *p = &j;
    int*& ref = p;
    cout << ref << "\t" << p << "\t" << j << endl;
    
    // cout << testConstRef(j) << endl;

    int i = 1;
    cout << "i = " << i << endl;
    // call using address of i
    func1(&i);
    cout << "i = " << i << endl;
    // call using i
    func2(i);
    cout << "i = " << i << endl;
}

void reviewOfPointer() {
    //Review of Pointer variable

    int A[6] = {2,4,6,8,10};
    int* pOfA = &A[1]; //  pOfA[0] = 4
    cout << pOfA[1] << endl;

    const char* words[] = { "first", "second", NULL };
    for (const char** p = words; *p != NULL; ++p) {
        cout << *p << endl;
    }

    int* p = nullptr;
    cout << p << endl;
    cout << &p << endl;
    // cout << *p << endl; lead error
}

void dynamicMemory() {
    int* p = new int;
    if (!p) {
        cout << "Memory allocation not successful!" << endl;
        exit(1);
    }

    *p = 100;
    cout << "At " << p << " ";
    cout << "is the value " << *p << endl;

    delete p;
    cout << "At " << p << " ";
    cout << "is the value " << *p << endl;

    //Dynamic Array
    int* q;
    q = new int[10]; // allocate an array of a 10 ints
    if(q == nullptr) { // or if(!q)
        cout << "Memory application not successful" << endl;
        exit(1);
    }

    for(int i=0; i<10; ++i) {
        q[i] = i;
        cout << q[i] << " ";
    }

    cout << "\nq: " << q;
    delete [] q; // release the array
    cout << "\nq: " << q << endl;
}

void printString(int arr[]) {
    // Below two are both not ok, since arr is a pointer
    // for (int i = 0; i < (sizeof(arr)/sizeof(int)); i++) {
    //     cout << arr[i] << endl;
    // }

    // for (int k : arr) {
    //     cout << k;
    // }
}

void printStringbyRefToArray(int (&arr)[5]) {
    for (int k : arr) {
        cout << k << endl;
    }
}

int main (void) {

    // reviewOfPointer();
    // dynamicMemory();

    // int x = {5};
    // int a[] {1,2,3};

    // cout << x << " " << a[0];

    int arr[] {10, 5, 20, 25, 0};

    //traditional way to increment every element in the array
    for (int i = 0; i < (sizeof(arr)/sizeof(int)); i++) { //sizeof(int) -> more favorable to use (flexibility++)
        cout << arr[i] << endl;
        
    }

    cout << endl;
    //range-for version
    for (int k : arr) {
        cout << ++k << endl;
    }

    for (int& k : arr) { //changed the array
        cout << ++k << endl;
    }

    printStringbyRefToArray(arr);

    int (&Rarr)[5] = arr;
    int a = 1;
    int& ref = a;

    cout << arr << endl << Rarr << endl << ref;

    int c = 3;
    int d = 4;
    int *const cpc = &c;
    *cpc = 5;


    return 0;
}