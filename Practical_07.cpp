#include <bits/stdc++.h> 
using namespace std;

int main(){
	
	string msg;
	int key,len;
	
	//Enter the text to convert to railfence
	
	cout<<"Enter Plain Text : ";
	cin>>msg;
	
	cout<<"Enter Key : ";
	cin>>key;
	
	char matrix[30][30];
	len = msg.length();//len is the length of input message
	
	
    //specify the number of rows/rails
	for(int i=0;i<key;i++){
		for(int j=0;j<len;j++){
			matrix[i][j] = ' ';
		}
	}

	int k=0,l=0,temp=0,flag=0;
	
	//input message should be stored in railfence format.
	for(int i=0;i<len;i++){
		flag=0;
		temp=0;
		 
		if(k==0 || k==key-1){
			k=k*(-1);
		}
		
		if(k<0){
			temp=k;
			k=k*(-1);
			flag=1;
		}
		
		matrix[k][i]=msg[l];
		if(flag==1){
			k=temp;
		}
		l++;
		k++;
	}
	
	cout<<endl;
	
	printf("Railfence Matrix is : \n");
	
	for(int i=0;i<key;i++){
		for(int j=0;j<len;j++){
			cout<<" "<<matrix[i][j];
		}
		cout<<endl;
	}

    //code for encryption

	char str[100];
	int glo=0;
	
	for(int i=0;i<key;i++){
		for(int j=0;j<len;j++){
			if(matrix[i][j] != ' '){
				str[glo++]=matrix[i][j];
			}
		}
	}


    cout<<endl;
	cout<<"Original Message is: "<<endl;
	cout<<""<<msg<<endl;
	
	//printing encrypted message
	cout<<endl;
	cout<<"Encrypted Message is: "<<endl;
	cout<<str<<endl;
	char dstr[100];
	int glob=0;
	
	cout<<endl;
	cout<<"Decrypted message is: "<<endl;
	int kk=0,temp1=0;
	
	for(int i=0;i<len;i++){
		temp1=0;
		flag=0;
	
		if(kk==0 || kk==key-1){
			kk=kk*(-1);
		}
		
		if(kk<0){
			temp1=kk;
			kk=kk*(-1);
			flag=1;
		}
		
		char ct=matrix[kk][i];
		 dstr[glob++]=ct;
		  
		 if(flag==1){
		 	kk=temp1;
		 }
		 kk++;
	}
	
	for(int i=0;dstr[i] !='\0';i++){
		cout<<""<<dstr[i];
	}
	cout<<endl;
}
