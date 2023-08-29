#include "CipherUtility.h"

// TODO #5
// Implement the static member function isKeyValid
bool CipherUtility::isKeyValid(const Cipher* cipher) {
    for (int i = 0; i < cipher->key.length(); i++)
        if (!isalpha(cipher->key[i]))
            return false;
    
    return true;
}

// TODO #6
// Implement the static member function removeNonAlphaCharsHelper
string CipherUtility::removeNonAlphaCharsHelper(string str) {
    string modifiedStr = "";

    if (str != "") {
        if (isalpha(str[0])) {
            modifiedStr += str[0];
        }
        // cout << "hello" << endl;
        string x = removeNonAlphaCharsHelper(str.substr(1, str.length() - 1));
        modifiedStr += x;
    }

    return modifiedStr;
}