#include <iostream>
#include <string>
#include "array.h"
#include "module.h"
#include "filter.h"
#include "handler.h"

using namespace std;

FilterModule::~FilterModule() {}

void FilterModule::print() const {
    std::cout << "Module name = " << m_name << ", this is a filter, filter type = " << getFilterType(type) << std::endl;
}    

void FilterModule::trainPreData(const string &source, const string &target) {
    preData.insert(source, target);
}

void FilterModule::trainPostData(const string &source, const string &target) {
    postData.insert(source, target);
}

string FilterModule::translatePreData(string question) const {
    return preData.find(question);
}

string FilterModule::translatePostData(string question) const {
    // cout << "postData: " << postData.find(question) << endl;
    return postData.find(question);
}

void FilterArray::insert(FilterModule *input) {
    if (arraySize == 0)
    {
        arraySize++;
        array = new FilterModule*[1];
        array[0] = input;
        return;
    }
    arraySize++;
    FilterModule** temp = new FilterModule*[arraySize];
    for (int i = 0; i < arraySize - 1; i++)
    {
        temp[i] = array[i];
    }
    temp[arraySize - 1] = input;
    delete [] array;
    array = temp;
    return;
}

FilterModule* FilterArray::get(int index) const {
    return (index >= 0 && index < arraySize)? array[index]: nullptr;
}
