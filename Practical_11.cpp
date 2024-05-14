#include <iostream>
#include <string>

using namespace std;

// Function to perform stream cipher encryption using XOR
string stream_cipher_encrypt(const string& plaintext, const string& key) {
    string ciphertext;
    for (size_t i = 0; i < plaintext.length(); ++i) {
        ciphertext += (plaintext[i] == key[i] ? '0' : '1'); // XOR operation on binary digits
    }
    return ciphertext;
}

// Function to perform stream cipher decryption using XOR
string stream_cipher_decrypt(const string& ciphertext, const string& key) {
    return stream_cipher_encrypt(ciphertext, key); // XOR operation is its own inverse
}

int main() {
    string plaintext = "111000101";
    string key = "101011101";
	
	cout<<"\nPlaintext : "<<plaintext<<endl;
	cout<<"\nNOTE : Here we have used XOR operation t o perform Encryption and\n"
		<<"XOR operation of key with Encrypted Text (Cipher Text) to perform Encryption.\n";
		
    // Encryption
    string encrypted = stream_cipher_encrypt(plaintext, key);
    cout << "\nEncrypted: " << encrypted << endl;

    // Decryption
    string decrypted = stream_cipher_decrypt(encrypted, key);
    cout << "\nDecrypted: " << decrypted << endl;

    return 0;
}

