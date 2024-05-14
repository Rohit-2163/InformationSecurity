#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string transpose(const string& text, const string& key) {
    // Remove spaces and convert text to uppercase
    string processedText;
    for ( string::const_iterator it = text.begin(); it != text.end(); ++it) {
        char c = *it;
        if ( isalpha(c))
            processedText +=  toupper(c);
    }

    // Calculate the number of columns based on the length of the key
    int numColumns = key.length();

    // Calculate the number of rows needed to accommodate the text
    int numRows = (processedText.length() + numColumns - 1) / numColumns;

    // Add padding if necessary
    processedText.resize(numRows * numColumns, 'X');

    // Create a vector of vectors to represent the grid
    vector< vector<char> > grid(numRows,  vector<char>(numColumns));

    // Fill the grid with characters from the processed text
    int index = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            grid[i][j] = processedText[index++];
        }
    }

    // Create a vector to store the positions of the columns based on the key
    vector<int> columnPositions(numColumns);
    for (int i = 0; i < numColumns; ++i) {
         string::size_type pos = key.find('0' + i + 1);
        columnPositions[i] = pos !=  string::npos ? pos : 0;
    }

    // Transpose the grid according to the key
    vector< vector<char> > transposedGrid(numRows,  vector<char>(numColumns));
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            transposedGrid[i][j] = grid[i][columnPositions[j]];
        }
    }

    // Read off the ciphertext from the transposed grid
    string ciphertext;
    for (int j = 0; j < numColumns; ++j) {
        for (int i = 0; i < numRows; ++i) {
            ciphertext += transposedGrid[i][j];
        }
    }

    return ciphertext;
}

int main() {
    
	string plaintext;
    cout<<"\nEnter Plain Text : ";
    cin>>plaintext;
    
	string key ;
    cout<<"\nEnter Key : ";
    cin>>key;
    
    string ciphertext = transpose(plaintext, key);
    cout << "\nCiphertext: " << ciphertext <<  endl;
    return 0;
}

