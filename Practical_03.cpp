// Caesar Cipher Technique
#include <iostream>
using namespace std;

string Cipher(string text, int key)
{
	string res = "";

	for (int i = 0; i < text.length(); i++) {
		if (isupper(text[i]))
			res += char(int(text[i] + key - 65) % 26 + 65);

		else
			res += char(int(text[i] + key - 97) % 26 + 97);
	}

	// Return the resulting string
	return res;
}

int main()
{
	string text ;
	cout<<"\nEnter The Text : ";
	cin>>text;
	int key;
	cout<<"\nEnter Key : ";
	cin>>key;
	
	cout << "\nCipher : " << Cipher(text, key);
	return 0;
}

