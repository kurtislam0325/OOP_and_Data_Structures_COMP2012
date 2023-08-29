#include "VigenereCipher.h"
#include "Utility.h"

// TODO #1
// Initialize the static data member alphabetSize here
const int VigenereCipher::alphabetSize {26};

// TODO #2
// Implement the encrypt member function according to the given algoirthm.
string VigenereCipher::encrypt(string plaintextMsg) const {
    string encryptedMsg;
    // cout << "plaintextMsg: " << plaintextMsg << endl;

    for (int i = 0; i < plaintextMsg.length(); i++) {
        if (!((plaintextMsg[i] <= 'z' && plaintextMsg[i] >= 'a') || (plaintextMsg[i] <= 'Z' && plaintextMsg[i] >= 'A')))
            continue;

        if (plaintextMsg[i] >= 'A' && plaintextMsg[i] <= 'Z') 
            plaintextMsg[i] -= ('A' - 'a');

        int shift = (key[i % key.length()]) - 'a';
        // cout << i << ": " << plaintextMsg[i] << " " << shift;

        plaintextMsg[i] = ((plaintextMsg[i] + shift) > 'z')? plaintextMsg[i] + shift - alphabetSize: plaintextMsg[i] + shift;
        // cout << plaintextMsg[i] << endl;        
    }

    // cout << "encryptedtMsg: " << encryptedMsg << endl;
    encryptedMsg = plaintextMsg;
    return encryptedMsg; 
}

// TODO #3
// Implement the decrypt member function according to the given algoirthm.
string VigenereCipher::decrypt(string plaintextMsg) const {
    string decryptedMsg;
    cout << "plaintextMsg: " << plaintextMsg << endl;

    for (int i = 0; i < plaintextMsg.length(); i++) {
        if (!((plaintextMsg[i] <= 'z' && plaintextMsg[i] >= 'a') || (plaintextMsg[i] <= 'Z' && plaintextMsg[i] >= 'A')))
            continue;

        if (plaintextMsg[i] >= 'A' && plaintextMsg[i] <= 'Z') 
            plaintextMsg[i] -= ('A' - 'a');

        int shift = (key[i % key.length()]) - 'a';
        // cout << i << ": " << plaintextMsg[i] << " " << shift;

        plaintextMsg[i] = ((plaintextMsg[i] - shift) < 'a')? plaintextMsg[i] - shift + alphabetSize: plaintextMsg[i] - shift;
        // cout << plaintextMsg[i] << endl;       
    }

    decryptedMsg = plaintextMsg;
    // cout << "decryptedtMsg: " << decryptedMsg << endl;    
    return decryptedMsg;
}

// TODO #4
// Implement the static member function generateRandomKey
// according to the given algorithm.
string VigenereCipher::generateRandomKey(int length) {
    string key;

    for (int i = 0; i < length; i++) {
        char k = static_cast<char>(_rand() % alphabetSize + 'a');
        key += k;
    }

    // cout << "key: " << key << endl;
    return key;
}
