#include <iostream>
#include <string>
#include "array.h"

using namespace std;

DataMap::DataMap(): arraySize(0), keys(nullptr), values(nullptr) {};

DataMap::~DataMap() {
    clear();
    keys = nullptr;
    values = nullptr;
}

void DataMap::insert(const string &key, const string &value) {
    // cout << "insert start and arraySize: " << arraySize << endl; 
    if (arraySize == 0) {
        arraySize++;
        keys = new string[1];
        values = new string[1];

        keys[0] = key;
        values[0] = value;
        // cout << keys[0] << " " << values[0] << endl;
        return;
    } 

    string* temp_k = new string[arraySize + 1];
    string* temp_v = new string[arraySize + 1];
    for (int i = 0; i < arraySize; i++) {
        temp_k[i] = keys[i];
        temp_v[i] = values[i];
    }   
    temp_k[arraySize] = key;
    temp_v[arraySize] = value;

    arraySize++;
    delete [] keys;
    delete [] values;
    keys = temp_k;
    values = temp_v; 

    // cout << "Data: " << endl;
    // for (int i = 0; i < arraySize; i++)
    //     cout << keys[i] << " " << values[i] << endl;    
    return;
}

string DataMap::find(const string &key) const {
    int index = 0;
    for (; index < arraySize; index++) {
        // cout << ": " << keys[index] << " " << values[index] << endl;  
        if (keys[index] == key) {
            // cout << "find: " << keys[index] << " " << values[index] << endl;  
            return values[index];
        }
    }

    return "";
}

inline void DataMap::clear() {
    if (arraySize != 0)
    {
        arraySize = 0;
        delete[] keys;
        delete[] values;

        keys = nullptr;
        values = nullptr;
    }
}