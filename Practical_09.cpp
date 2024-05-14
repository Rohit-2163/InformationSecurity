#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to perform Caesar substitution encryption
string substitution_encrypt(const string& plaintext, int shift) {
    string ciphertext = plaintext;
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char& c = ciphertext[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }
    return ciphertext;
}

// Function to perform Caesar substitution decryption
string substitution_decrypt(const string& ciphertext, int shift) {
    return substitution_encrypt(ciphertext, 26 - shift); // Reverse the shift for decryption
}

// Function to perform transposition encryption and substitution encryption
string product_cipher_encrypt(const string& plaintext, int shift, int key) {
    string ciphertext = plaintext;
    // Step 1: Substitution (Caesar cipher)
    ciphertext = substitution_encrypt(ciphertext, shift);
    // Step 2: Transposition
    size_t len = ciphertext.length();
    size_t rows = (len + key - 1) / key;
    char matrix[rows][key];
    size_t k = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < key; ++j) {
            if (k < len)
                matrix[i][j] = ciphertext[k++];
            else
                matrix[i][j] = ' ';
        }
    }
    k = 0;
    for (size_t j = 0; j < key; ++j) {
        for (size_t i = 0; i < rows; ++i) {
            ciphertext[k++] = matrix[i][j];
        }
    }
    return ciphertext;
}

// Function to perform transposition decryption and substitution decryption
string product_cipher_decrypt(const string& ciphertext, int shift, int key) {
    string decrypted = ciphertext;
    // Step 1: Transposition decryption
    size_t len = decrypted.length();
    size_t rows = (len + key - 1) / key;
    char matrix[rows][key];
    size_t k = 0;
    for (size_t j = 0; j < key; ++j) {
        for (size_t i = 0; i < rows; ++i) {
            matrix[i][j] = decrypted[k++];
        }
    }
    k = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < key; ++j) {
            decrypted[k++] = matrix[i][j];
        }
    }
    // Step 2: Substitution decryption
    decrypted = substitution_decrypt(decrypted, shift);
    return decrypted;
}

int main() {
    string plaintext = "Information Security";
    int substitution_shift = 3;
    int transposition_key = 4;
	
	cout<<"\nPlain Text : "<<plaintext<<endl;
    // Encryption
    string encrypted = product_cipher_encrypt(plaintext, substitution_shift, transposition_key);
    cout << "\nEncrypted Text : " << encrypted << endl;

    // Decryption
    string decrypted = product_cipher_decrypt(encrypted, substitution_shift, transposition_key);
    cout << "\nDecrypted Text : " << decrypted << endl;

    return 0;
}

