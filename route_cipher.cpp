#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to remove spaces and non-letter characters and convert to uppercase
string processMessage(const string& message) {
    string processedMessage;
    for (char c : message) {
        if (isalpha(c)) {
            processedMessage += toupper(c);
        }
    }
    return processedMessage;
}

// Function to encrypt the message using the route cipher
string encrypt(const string& message, int key) {
    string processedMessage = processMessage(message);
    int numRows = ceil(static_cast<double>(processedMessage.length()) / key);
    int numCols = key;

    // Fill the matrix
    vector<vector<char>> matrix(numRows, vector<char>(numCols, 'X'));
    int index = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols && index < processedMessage.length(); ++j) {
            matrix[i][j] = processedMessage[index++];
        }
    }

    // Read the grid clockwise, starting from the top right corner
    string encryptedMessage;
    int startRow = 0, endRow = numRows - 1, startCol = numCols - 1, endCol = 0;
    while (startCol >= endCol && startRow <= endRow) {
        for (int i = startRow; i <= endRow; ++i) {
            encryptedMessage += matrix[i][startCol];
        }
        for (int i = startCol - 1; i >= endCol; --i) {
            encryptedMessage += matrix[endRow][i];
        }
        for (int i = endRow - 1; i >= startRow && startCol != endCol; --i) {
            encryptedMessage += matrix[i][endCol];
        }
        for (int i = endCol + 1; i < startCol && startRow != endRow; ++i) {
            encryptedMessage += matrix[startRow][i];
        }
        startRow++;
        endRow--;
        startCol--;
        endCol++;
    }

    return encryptedMessage;
}

int main() {
    string message;
    int key;
    cout<<"enter a message to be encrypted: ";
    cin>>message;
    cout<<"enter the encryption key(such as 2 or 3 or 4 ...): ";
    cin>>key;

    string encryptedMessage = encrypt(message, key);

    cout << "Original message: " << message << endl;
    cout << "Encrypted message: " << encryptedMessage << endl;

    return 0;
}
