// Identify the plain text from the ciphered text
// Author - Prathamesh Mehare

// Note: The following program deciphers the text using different keys.
//       The user needs to identify the correct plain text from various options

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    char patternChar = '-';
    char resetChar = ' ';
    int lineWidth = 90;
    int initialWidth = 50;

    cout << setfill(patternChar) << setw(lineWidth) << patternChar << endl;
    cout << setfill(resetChar);
    cout << setw(initialWidth) << "Text Decryption" << endl;
    cout << setfill(patternChar) << setw(lineWidth) << patternChar << endl;
    cout << setfill(resetChar);


    cout << endl;
    cout << "Enter the Ciphered Text: " << endl;



    string cipherText;
    getline(cin, cipherText);

    cout << endl;
    

    for(size_t i = 1; i < 26; i++){
        int currentKey = i;
        string currPlainText = "";

        for(size_t j = 0; j<cipherText.size(); j++){
            char decipheredAlpha;
            if(isalpha(cipherText[j])){
                if(cipherText[j] >= 'A' && cipherText[j] <= 'Z'){
                    decipheredAlpha = (((cipherText[j]-'A')-currentKey)+26)%26+'A';
                }else{
                    decipheredAlpha = (((cipherText[j]-'a')-currentKey)+26)%26+'a';
                }
            }else{
                decipheredAlpha = cipherText[j];
            }
            
            currPlainText += decipheredAlpha;
        }

        cout << "Key: " << currentKey << endl;
        cout << "Plain Text: " << currPlainText << "\n" << endl;
    }

    return 0;
}