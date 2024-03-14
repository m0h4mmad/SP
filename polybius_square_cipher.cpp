#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <cctype>
#include <string>
using namespace std;
string polybius_square_cipher(string plain) {
    cout<<"press Enter button after any integer of the key you provide"<<endl;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >>e;
    map <char, string> mapping;
    mapping['A'] = to_string(a) + to_string(a);
    mapping['B'] = to_string(a) + to_string(b);
    mapping['C'] = to_string(a) + to_string(c);
    mapping['D'] = to_string(a) + to_string(d);
    mapping['E'] = to_string(a) + to_string(e);
    mapping['F'] = to_string(b) + to_string(a);
    mapping['G'] = to_string(b) + to_string(b);
    mapping['H'] = to_string(b) + to_string(c);
    mapping['I'] = to_string(b) + to_string(d);
    mapping['J'] = to_string(b) + to_string(d);
    mapping['K'] = to_string(b) + to_string(e);
    mapping['L'] = to_string(c) + to_string(a);
    mapping['M'] = to_string(c) + to_string(b);
    mapping['N'] = to_string(c) + to_string(c);
    mapping['O'] = to_string(c) + to_string(d);
    mapping['P'] = to_string(c) + to_string(e);
    mapping['Q'] = to_string(d) + to_string(a);
    mapping['R'] = to_string(d) + to_string(b);
    mapping['S'] = to_string(d) + to_string(c);
    mapping['T'] = to_string(d) + to_string(d);
    mapping['U'] = to_string(d) + to_string(e);
    mapping['V'] = to_string(e) + to_string(a);
    mapping['W'] = to_string(e) + to_string(b);
    mapping['X'] = to_string(e) + to_string(c);
    mapping['Y'] = to_string(e) + to_string(d);
    mapping['Z'] = to_string(e) + to_string(e);
    string ciphered;
    for(auto &k : plain){
        if(isalpha(k)){
            k = toupper(k);
            ciphered += mapping[k];
        }
        else{
            continue;
        }
    }
    return ciphered;

}
string polybius_square_decipher(string encrypted) {
    cout<<"press Enter button after any integer of the key you provide"<<endl;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >>e;
    map <string, char> mapping;
    mapping[to_string(a) + to_string(a)] = 'A';
    mapping[to_string(a) + to_string(b)] = 'B';
    mapping[to_string(a) + to_string(c)] = 'C';
    mapping[to_string(a) + to_string(d)] = 'D';
    mapping[to_string(a) + to_string(e)] = 'E';
    mapping[to_string(b) + to_string(a)] = 'F';
    mapping[to_string(b) + to_string(b)] = 'G';
    mapping[to_string(b) + to_string(c)] = 'H';
    mapping[to_string(b) + to_string(d)] = 'I';
    mapping[to_string(b) + to_string(e)] = 'K';
    mapping[to_string(c) + to_string(a)] = 'L';
    mapping[to_string(c) + to_string(b)] = 'M';
    mapping[to_string(c) + to_string(c)] = 'N';
    mapping[to_string(c) + to_string(d)] = 'O';
    mapping[to_string(c) + to_string(e)] = 'P';
    mapping[to_string(d) + to_string(a)] = 'Q';
    mapping[to_string(d) + to_string(b)] = 'R';
    mapping[to_string(d) + to_string(c)] = 'S';
    mapping[to_string(d) + to_string(d)] = 'T';
    mapping[to_string(d) + to_string(e)] = 'U';
    mapping[to_string(e) + to_string(a)] = 'V';
    mapping[to_string(e) + to_string(b)] = 'W';
    mapping[to_string(e) + to_string(c)] = 'X';
    mapping[to_string(e) + to_string(d)] = 'Y';
    mapping[to_string(e) + to_string(e)] = 'Z';

    string deciphered;
    string temp;
    for(int i=0;i<encrypted.size();i+=2){
        temp += encrypted[i];
        temp += encrypted[i+1];
        deciphered+=mapping[temp];
        temp = "";
    }
    return deciphered;

}

int main(){


    return 0;
}
