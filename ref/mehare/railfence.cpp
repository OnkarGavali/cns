// The program implements the railfence cipher algorithm
// Author -> Prathamesh Mehare

#include <iostream>
#include <iomanip>
using namespace std;

string encrypt(string plainText, size_t depth){
    string encryption{};
    for(size_t i = 0; i < depth; i++){
        size_t position = i;
        for(; position < plainText.size(); position+=depth){
            encryption += plainText[position];
        }
    }
    return encryption;
}

string decrypt(string encryptedText, size_t depth){
    string decryption{};

    size_t jumpSize{0};
    if(encryptedText.size() % depth == 0){
        jumpSize = encryptedText.size()/depth;
    }else{
        jumpSize = encryptedText.size()/depth + 1;
    }
    int temp = (encryptedText.size() % depth);
    for(size_t i = 0; i < jumpSize; i++){
        size_t pos = i;
        int currStart = i;
        int count = 1;
        for(; pos < encryptedText.size();){
            decryption += encryptedText[pos];
            if(currStart == jumpSize-1 && count >= temp)
                break;
            if(temp != 0){
                if(count <= temp)
                    pos += jumpSize;
                else
                    pos += jumpSize-1;
            }else{
                pos += jumpSize;
            }
            count++;
        }
    }

    return decryption;
}

int main() {

    char patternChar = '-';
    char resetChar = ' ';
    int lineWidth = 90;
    int initialWidth = 50;

    cout << setfill(patternChar) << setw(lineWidth) << patternChar << endl;
    cout << setfill(resetChar);
    cout << setw(initialWidth) << "Railfence Cipher" << endl;
    cout << setfill(patternChar) << setw(lineWidth) << patternChar << endl;
    cout << setfill(resetChar);


    string text {};
    cout << "Enter text: " << endl;
    getline(cin, text);

    size_t depth;
    cout << "Enter depth (Depth must be greater than 0): ";
    cin >> depth;
    

    cout << "\nChoose an action" << endl;
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << "\n(Enter your choice number and then press the enter key)" << endl;

    int choice;
    cin >> choice;

    if(choice == 1){
        string encryptedText = encrypt(text, depth);
        cout << "\nEncrypted Text: " << encryptedText << endl;
    }else if(choice == 2){
        string decryptedText = decrypt(text, depth);
        cout << "\nDecrypted Text: " << decryptedText << endl;
    }else {
        cout << "Invalid choice..." << endl;
        cout << "Program Terminated." << endl;
    }

    return 0;
}