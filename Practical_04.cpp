#include<bits/stdc++.h>

using namespace std;

string sets="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'0''1''2''3''4''5''6''7''8''9' ";

string encryption(string plaintext,string key)
{
   string encrypt_text="";

	for ( int i=0;i<plaintext.length();i++)
	{
		//alnum check wheather the character is alphanumeric or not.If the character is alphanumeric
	    // then that character is  encrypted otherwise it remain same throughout the enryption process		
		if(isalnum(plaintext[i]))
		{
			for(int j=0;j<sets.length();j++)
			{
		
				if(plaintext.at(i)==sets.at(j))
				{
					encrypt_text+=key.at(j);
					break;
				 }
			}
		
		
		}
		else
			encrypt_text+=char(plaintext[i]);
	}

   return encrypt_text;
	
}

void decryption(string ciphertext,string key)
{
 	string decrypt_text="";
 
 	for (int i=0;i<ciphertext.length();i++)
 	{
		//alnum check wheather the character is alphanumeric or not.If the character is alphanumeric
		// then that character is  decrypted otherwise it remain same throughout the deryption process
	 	if(isalnum(ciphertext[i]))
	 	{
	 		for(int j=0;j<key.length();j++)
	 		{
	
	 			if(ciphertext.at(i)==key.at(j))
	 			{
	 				decrypt_text+=sets.at(j);
	 				break;
				 }
			 }
		}
		else
			decrypt_text+=char(ciphertext[i]);
	}
	
	cout<<"Decrypted Text  : "<<decrypt_text<<endl;
}


int main()
{
	cout<<"\n\n			Monoalphabetic Substitution Ciphers\n";
 	string message ,cipher_text;
 	int choice;
 	string key="PQRSTUVWXYZABCDEFGHIJKLMNO";

 	cout<<"\nEnter the Message : ";
 	getline(cin,message);
 	
 	//for display the process of interchanging of characters
 	cout<<"\nABCDEFGHIJKLMNOPQRSTUVWXYZ"<<endl;
 	cout<<"||||||||||||||||||||||||||"<<endl;
 	cout<<key<<endl;

 	while(1)
 	{
	 	
	 	cout<<"\n1  :- Encryption"<<endl<<"2 :-  Decryption"<<endl<<"3 :- Exit"<<endl;
	 	cout<<"\nEnter your choice : ";
	 	cin>>choice;
	
	 	switch(choice)
		{
		 	 case 1:
		 		cout<<"\nEncryption  :  "<<endl;
		 		cipher_text=encryption(message,key);
		 		cout<<"\nCipher Text : "<<cipher_text<<endl;
		 		cout<<"\n\n---------------------------------------------"<<endl;
		 		break;
		 		
		 	case 2:
		 		cout<<"Decryption  :  "<<endl;
		 		cipher_text=encryption(message,key);
		 		decryption(cipher_text,key);
		 		cout<<"\n\n---------------------------------------------"<<endl;
				break;
				 
			case 3:
				exit(0);
				break;
			default:
				cout<<"\nInvalid entry!!"<<endl;
		}

	}
 	return 0;
}

