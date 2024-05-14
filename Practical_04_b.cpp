// C++ code to implement Vigenere Cipher
#include<bits/stdc++.h>
using namespace std;

string createKey(string str, string key)
{
	int x = str.size();

	for (int i = 0; ; i++)
	{
		if (x == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}

string encryp(string str, string key)
{
	string cipher_text;

	for (int i = 0; i < str.size(); i++)
	{
		// converting in range 0-25
		char x = (str[i] + key[i]) %26;

		// convert into alphabets(ASCII)
		x += 'A';

		cipher_text.push_back(x);
	}
	return cipher_text;
}

string decryp(string cipher_text, string key)
{
	string orig_text;

	for (int i = 0 ; i < cipher_text.size(); i++)
	{
		// converting in range 0-25
		char x = (cipher_text[i] - key[i] + 26) %26;

		// convert into alphabets(ASCII)
		x += 'A';
		orig_text.push_back(x);
	}
	return orig_text;
}

// Driver program to test the above function
int main()
{
	cout<<"\n\n			Polyalphabetic Substitution Ciphers\n";
	string str ;
	cout<<"\nEnter Message To be Encrypted : ";
	cin>>str;
	
	string keyword = "IHS";

	string key = createKey(str, keyword);
	string cipher_text = encryp(str, key);

	cout << "\nCiphertext : " << cipher_text << "\n";

	cout << "\nDecrypted Text : " << decryp(cipher_text, key);
	return 0;
}

