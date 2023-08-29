#include <iostream>
#include <string>
#include "array.h"
#include "module.h"
#include "filter.h"
#include "handler.h"

using namespace std;

HandlerModule::~HandlerModule() {
    languageFilter = nullptr;
    toneFilter = nullptr;
}

void HandlerModule::print() const {
    std::cout << "Module name = " << m_name << ", this is a Handler, can handle topic = " << topic << std::endl;
}

void HandlerModule::trainData(const string &question, const string &answer) {
    data.insert(question, answer);
}

string HandlerModule::answer(const string &question) const {
    // cout << "\nanswer function: " << endl;
    string tunedQuestion = question;

    // cout << "Question: " << question << endl;
    if (languageFilter)
        if (languageFilter->translatePreData(tunedQuestion) != "")
            tunedQuestion = languageFilter->translatePreData(tunedQuestion);
    // cout << "tunedQuestion after language: " << tunedQuestion << endl;        
    if (toneFilter) {
        if (toneFilter->translatePreData(tunedQuestion) != "")
            tunedQuestion = toneFilter->translatePreData(tunedQuestion);
    }

    if(inneranswer(tunedQuestion).empty())
        return "Sorry, I don't know";
    string tunedAnswer = inneranswer(tunedQuestion);


    // cout << "tunedAnswer:" << tunedAnswer << endl;
    if (toneFilter) {
        if (toneFilter->translatePostData(tunedAnswer) != "")
            tunedAnswer = toneFilter->translatePostData(tunedAnswer);
    }
    
    // cout << "tunedAnswer after tone:" << tunedAnswer << endl;    
    if (languageFilter)
        if (languageFilter->translatePostData(tunedAnswer) != "")
            tunedAnswer = languageFilter->translatePostData(tunedAnswer);
    // cout << "tunedAnswer after language:" << tunedAnswer << endl;

    return tunedAnswer;
}

string HandlerModule::inneranswer(const string &question) const {
    // cout << "inneranswer: " << data.find(question) << endl;
    return data.find(question);
}


HandlerMap::HandlerMap(): arraySize(0), names(nullptr), handlerModules(nullptr) {
}

HandlerMap::~HandlerMap() {
    clear();
    names = nullptr;
    handlerModules = nullptr;    
}


void HandlerMap::insert(string key, HandlerModule *value) {
    if (arraySize == 0) {
        arraySize++;

        names = new string[1];
        names[0] = key;
        handlerModules = new HandlerModule*[1];
        handlerModules[0] = value;
    } else {
        string* temp_n = new string[arraySize + 1];
        HandlerModule** temp_h = new HandlerModule*[arraySize + 1];

        for (int i = 0; i < arraySize; i++) {
            temp_n[i] = names[i];
            temp_h[i] = handlerModules[i];
        }

        temp_n[arraySize] = key;
        temp_h[arraySize] = value;

        arraySize++;        
        delete [] names;
        delete [] handlerModules;
        names = temp_n;
        handlerModules = temp_h;
    }

    return;
}

HandlerModule* HandlerMap::find(const string &key) const {
    int index = 0;
    for (; index < arraySize; index++) {
        if (names[index] == key)
            return handlerModules[index];
    }

    return nullptr;
}

string HandlerMap::getNames(int index) const {
    return (index >= 0 && index < arraySize)? names[index]: nullptr;
}

void HandlerMap::clear() {
    if (arraySize != 0)
    {
        arraySize = 0;
        delete [] names;
        delete [] handlerModules;
    }
    return;
}
