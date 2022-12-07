// This program implements the Columnar Cipher
// Author -> Prathamesh Mehare

#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>

using namespace std;

string encrypt(string plainText, string key){
    string cipherText{};
    unordered_map<char,vector<char>> columnar;


    for(size_t i = 0, j=0; i < plainText.size(); i++, j=(j+1)%key.size()){
        columnar[key[j]].push_back(plainText[i]);
    }

    for(int i = 0; i < 26; i++){
        if(columnar.count('a'+i)){
            for(auto c : columnar['a' + i]){
                cipherText += c;
            }
        }
    }

    return cipherText;
}

string decrypt(string encryptedText, string key){
    size_t blockSize = 0;

    if(encryptedText.size() % key.size() == 0){
        blockSize = encryptedText.size() / key.size();
    }else{
        blockSize = encryptedText.size() / key.size() + 1;
    }

    int count = 0;
    for(char curr = 'a'; curr <= 'z'; curr++){
        if(key.find(curr) != string::npos){
            int i = blockSize*count;
            for(size_t j = 0; j < blockSize; j++,i++){
                
            }
        }
    }
}

int main() {

    string text{};
    string key{};

    char patternChar = '-';
    char resetChar = ' ';
    int lineWidth = 90;
    int initialWidth = 50;

    cout << setfill(patternChar) << setw(lineWidth) << patternChar << endl;
    cout << setfill(resetChar);
    cout << setw(initialWidth) << "Columnar Cipher" << endl;
    cout << setfill(patternChar) << setw(lineWidth) << patternChar << endl;
    cout << setfill(resetChar);

    cout << "Enter text: ";
    getline(cin, text);

    cout << "\nEnter the key: ";
    getline(cin, key);

    cout << "\nChoose an action" << endl;
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << "\n(Enter your choice number and then press the enter key)" << endl;

    int choice;
    cin >> choice;

    if(choice == 1){
        string encryptedText = encrypt(text, key);
        cout << "\nEncrypted Text: " << encryptedText << endl;
    }else if(choice == 2){
        string decryptedText = decrypt(text, key);
        cout << "\nDecrypted Text: " << decryptedText << endl;
    }else {
        cout << "Invalid choice..." << endl;
        cout << "Program Terminated." << endl;
    }

    return 0;
}