#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string string_to_hex(const string& input) {
    stringstream hex_stream;
    hex_stream << hex << setfill('0');
    for (unsigned char c : input) {
        hex_stream << setw(2) << static_cast<unsigned int>(c);
    }
    return hex_stream.str();
}
string hex_to_string(const string& hex) {
    string result;
    for (size_t i = 0; i < hex.length(); i += 2) {
        string byteString = hex.substr(i, 2);
        char byte = (char)strtol(byteString.c_str(), nullptr, 16);
        result += byte;
    }
    return result;
}



string xor_encrypt(const string& plaintext, const string& key) {
    string ciphertext;
    for (size_t i = 0; i < plaintext.size(); ++i) {
        ciphertext += plaintext[i] ^ key[i % key.size()];
    }
    return ciphertext;
}

string xor_decrypt(const string& ciphertext, const string& key) {
    string plaintext;
    for (size_t i = 0; i < ciphertext.size(); ++i) {
        plaintext += ciphertext[i] ^ key[i % key.size()];
    }
    return plaintext;
}


int main() {

    char choice;
    cout<<"A)encrypt"<<endl<<"B)decrypt"<<endl;
    cin>>choice;
    if(choice=='A' || choice=='a'){
        string input_message, key;
        cout<<"enter a message to be ciphered: ";
        cin>>input_message;
        cout<<"enter the key: ";
        cin>>key;
        string ciphertext = xor_encrypt(input_message, key);
        cout<<"Ciphered text (text): "<<ciphertext<<endl;
        cout << "Ciphered text (hex): " << string_to_hex(ciphertext) << endl;
    }
    else if(choice=='b' ||choice=='B'){
        string message, key;
        cout<<"enter a message in HEX to be decrypted: ";
        cin>>message;
        cout<<"enter the decryption key: ";
        cin>>key;
        cout<<xor_decrypt(hex_to_string(message),key);
    }

    else{
        cout<<"ERR: invalid choice";
    }


    return 0;
}
