//Program to implement Hill Cipher Subsitution

//Ading required Libraries
#include<iostream>
#include<math.h>

using namespace std;

//Defining Matrices  which  willbe used
float encryp[3][1], decryp[3][1], a[3][3], b[3][3], msg[3][1], m[3][3];

//Function to get Key From user
void getKeyMatrix()
{ 
   int i, j;
   char mes[3];
   
   cout<<"Enter a Matrix For Key :\n";
   for(i = 0; i < 3; i++)
   {
	   
	   for(j = 0; j < 3; j++)
	   {
	      cin>>a[i][j];
	      m[i][j] = a[i][j];
	   }
	}
   
   cout<<"\nEnter a string of 3 letter(use A through Z): ";
   cin>>mes;
   
   for(i = 0; i < 3; i++)
   msg[i][0] = mes[i] - 65;
}

//  Function to Encrypt The Message
void encrypt() {
   int i, j, k;
   
   for(i = 0; i < 3; i++)
   {
	   for(j = 0; j < 1; j++)
	   {
		   	for(k = 0; k < 3; k++)
		   	{
			   	encryp[i][j] = encryp[i][j] + a[i][k] * msg[k][j];
		    }
		}
   }
   
   cout<<"\nEncrypted string is: ";
   
   for(i = 0; i < 3; i++)
   cout<<(char)(fmod(encryp[i][0], 26) + 65);

}

void inversematrix() { 
   int i, j, k;
   float p, q;

   for(i = 0; i < 3; i++)
   {
	   for(j = 0; j < 3; j++)
	   {
	      if(i == j)
	         b[i][j]=1;
	      else
	         b[i][j]=0;
	   }
   } 
	
	for(k = 0; k < 3; k++)
	   {
	      for(i = 0; i < 3; i++)
		  {
	         p = m[i][k];
	         q = m[k][k];
	         for(j = 0; j < 3; j++)
			 {
	            if(i != k){
	               m[i][j] = m[i][j]*q - p*m[k][j];
	               b[i][j] = b[i][j]*q - p*b[k][j];
	            }
	         }
	      }
	   }
   
    
    
	for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
	    b[i][j] = b[i][j] / m[i][i];
	
	cout<<"\n\nInverse Matrix is:\n";
	    
	for(i = 0; i < 3; i++) {
      for(j = 0; j < 3; j++)
      cout<<b[i][j]<<"  ";
      cout<<"\n";
   }
}

//Functon to Derypt the Mssage
void decrypt()
{ 
   int i, j, k;
   
   inversematrix();
   
   for(i = 0; i < 3; i++)
   for(j = 0; j < 1; j++)
   for(k = 0; k < 3; k++)
	   decryp[i][j] = decryp[i][j] + b[i][k] * encryp[k][j]; 
   
   cout<<"\nDecrypted string is: ";
   
   for(i = 0; i < 3; i++)
   cout<<(char)(fmod(decryp[i][0], 26) + 65); 
   cout<<"\n";
}

int main() {
   getKeyMatrix();
   encrypt();
   decrypt();
}
