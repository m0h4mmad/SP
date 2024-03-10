void baconian_cipher(string plaintext){
    // Converting word's characters to lowercase.
    for(char &k : plaintext){
        k = tolower(k);
    }
    // Making this array to access the value of each alphabet letter to be ciphered.
    string value[26] = {
            "aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb",
            "abaaa", "abaab", "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb",
            "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba", "babbb",
            "bbaaa", "bbaab" };
    // This string will have our word after being ciphered.
    string encrypted="";
    for(char &l : plaintext) {
        // If alpha we cipher it else we add it as it is.
        if (isalpha(l)) {
            // Adding word by using its value. Fact we are substracting 'a' to convert every letter into a values form 0 to 25.
            encrypted += value[int(l-'a')];
        }
        else {
            encrypted += l;
        }

    }
    cout << "The word \""<< plaintext << "\" after being ciphered is: " << encrypted << endl;
}
void baconian_decipher(string encryptedtext){
    for(char &k : encryptedtext){
        k = tolower(k);
    }
    // Making this array to access the value of each alphabet letter to be ciphered.
    string value[26] = {
            "aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb",
            "abaaa", "abaab", "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb",
            "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba", "babbb",
            "bbaaa", "bbaab" };
    // This string that we will add letters to it.
    string decrypted="";
    // Using this temp_string to add every five letters and use them to get the value of it like if it is aaaba that means 2.
    string temp_string = "";
    for(char &k : encryptedtext){
        // If alphabet we do our decipher else we add it as it is.
        if(isalpha(k)){
            // Adding the char to the string and when it has 5 characters we will go into the next if condition.
            temp_string += k;
            // Now we start looking for the 5 chars number in the string value.
            if(temp_string.size() % 5 == 0){
                for(int i = 0;i < 26;i++){
                    // When we find that temp_string equal value[i] then we add char of ('a' + i) to get the char we are decrypting to.
                    if(temp_string == value[i]){
                        temp_string = "";
                        decrypted+= char('a' + i);
                    }
                }
            }
        }
        else{
            decrypted += k;
        }

    }
    cout << "The word \""<< encryptedtext << "\" after being deciphered is: " << decrypted << endl;
}