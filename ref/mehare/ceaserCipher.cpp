// Algorithm to implement for Ceaser Cipher
// Author - Prathamesh Mehare

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    char patternChar = '-';
    char resetChar = ' ';
    int lineWidth = 90;
    int initialWidth = 50;

    cout << setfill(patternChar) << setw(lineWidth) << patternChar << endl;
    cout << setfill(resetChar);
    cout << setw(initialWidth) << "Ceaser Cipher" << endl;
    cout << setfill(patternChar) << setw(lineWidth) << patternChar << endl;
    cout << setfill(resetChar);


    cout << endl;
    cout << "Enter the Sentence to be ciphered: ";

    string plainText;
    getline(cin, plainText);
    cout << endl;
    int key = 3; // since the cipher is ceaser the key is 3

    // Encryption
    string cipheredText = "";
    for(size_t i = 0; i < plainText.size(); i++){
        char cipheredAlpha;
        if(isalpha(plainText[i])){
            if(plainText[i] >= 'A' && plainText[i] <= 'Z'){
                cipheredAlpha = (((plainText[i]-'A')+key)%26)+'A';
            }else{
                cipheredAlpha = (((plainText[i]-'a')+key)%26)+'a';
            }
        }else{
            cipheredAlpha = plainText[i];
        }
        
        cipheredText += cipheredAlpha;
    }

    cout << setw(lineWidth) << "" << endl;

    cout << "The ciphered text for the given text is : ";
    cout << cipheredText << endl;

    cout << setw(lineWidth) << "" << endl;

    cout << "Enter text to decrypt: ";
    string cipher {};
    getline(cin,cipher);
    string decryptedText{};

    for(size_t i = 0; i < cipher.size(); i++){
        char decipheredAlpha;
        if(isalpha(cipher[i])){
            if(cipher[i] >= 'A' && cipher[i] <= 'Z'){
                decipheredAlpha = (((cipher[i]-'A')-key+26)%26)+'A';
            }else{
                decipheredAlpha = (((cipher[i]-'a')-key+26)%26)+'a';
            }
        }else{
            decipheredAlpha = cipher[i];
        }
        
        decryptedText += decipheredAlpha;
    }

    cout << "\nThe deciphered text for the given ciphertext is : ";
    cout << decryptedText << endl;

    cout << setw(lineWidth) << "" << endl;

    return 0;
}