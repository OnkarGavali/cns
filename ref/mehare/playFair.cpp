// The following program implements the Play fair algorithm for ciphering the text
// Author: Prathamesh Mehare

#include <iostream>
#include <vector>
using namespace std;

void process(string plainText,vector<vector<char>>& processedText){
    
    char bogusChar = 'z';
    int size = 0;
    vector<char> temp(2);
    for(size_t i = 0; i < plainText.size(); i++){
        if(plainText[i] == ' ')
            continue;
        if(size == 0){
            if(plainText[i] == 'j'){
                temp[0] = bogusChar;
            }else{
                temp[0] = plainText[i];
            }
            size++;
        }else{
            if(plainText[i] == temp[0] || plainText[i] == 'j'){
                temp[1] = bogusChar;
                if(plainText[i]!='j')
                    i--;
            }else{
                temp[1] = plainText[i];
            }
            processedText.push_back(temp);
            size=0;
        }
    }
    // check if the last pair is not formed.
    if(size==1){
        temp[1] = bogusChar;
        processedText.push_back(temp);
    }

    cout << "\nThe processed Plain Text:" << endl;
    for(auto chars : processedText){
        for(auto c : chars){
            cout << c;
        }
        cout << " ";
    }
    cout << endl;
}

string playFairEncryption(string plainText, string key){
    vector<vector<char>> keySquare(5, vector<char>(5,'1'));
    vector<bool> markedAlphabets(26);
    
    // generating keySqaure
    // inserting the characters of the key in the keySquare

    
    int tempRow = 0;
    int tempCol = 0;

    for(size_t i = 0; i < key.size(); i++){
        if(key[i] != 'j' && !markedAlphabets[key[i]-'a']){
            markedAlphabets[key[i]-'a']=true;
            if(tempCol == 5){
                tempCol = 0;
                tempRow++;
            }
            keySquare[tempRow][tempCol] = key[i];
            tempCol++;
        }
    }

    // fill the remaining empty slots of the keySqaure with alphabets in ascending order
    // Here char 'j' is not inserted as keySquare needs only 25 alphabets
    for(char c = 'a'; c <= 'z'; c++){
        if(!markedAlphabets[c-'a'] && c != 'j'){
            if(tempCol == 5){
                tempCol = 0;
                tempRow++;
            }
            keySquare[tempRow][tempCol] = c;
            tempCol++;
        }
    }
    
    cout << "\nThe generated Key Square Matrix is: " << endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << keySquare[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<char>> processedText;

    process(plainText, processedText);

    vector<vector<char>> cipherVector;
    for(auto characters: processedText){
        char first = characters[0];
        char second = characters[1];

        vector<char> temp;

        pair<int,int> positionOfFirst;
        pair<int,int> positionOfSecond;

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(keySquare[i][j] == first){
                    positionOfFirst = {i,j};
                }else if(keySquare[i][j] == second){
                    positionOfSecond = {i,j};
                }
            }
        }

        if(positionOfFirst.first == positionOfSecond.first){
            temp.push_back(keySquare[positionOfFirst.first][(positionOfFirst.second + 1)%5]);
            temp.push_back(keySquare[positionOfSecond.first][(positionOfSecond.second + 1)%5]);
        }else if(positionOfFirst.second == positionOfSecond.second){
            temp.push_back(keySquare[(positionOfFirst.first+1)%5][positionOfFirst.second]);
            temp.push_back(keySquare[(positionOfSecond.first+1)%5][positionOfSecond.second]);
        }else{
            temp.push_back(keySquare[positionOfFirst.first][positionOfSecond.second]);
            temp.push_back(keySquare[positionOfSecond.first][positionOfFirst.second]);
        }

        cipherVector.push_back(temp);
    }
    string cipherText;
    for(auto chars: cipherVector){
        for(auto c: chars){
            cipherText += c;
        }
    }

    return cipherText;
}

int main()  {
    //string plainText {"we are discovered save yourself"};
    string plainText {"the key is secret"};
    // string plainText {"plr lrz kq truefz"};
    //string key {"charlie"};
    string key {"occurrence"};

    vector<vector<char>> keySquare(5, vector<char>(5));
    

    cout << "Plain Text: " << plainText << endl;
    cout << "\nKey: " << key << endl;

    string cipherText;
    cipherText = playFairEncryption(plainText, key);

    cout << "\nEncryption using Play Fair Cipher: " << endl;
    int j = 0;
    for(size_t i = 0; i < plainText.size(); i++){
        if(plainText[i] == ' '){
            cout << ' ';
        }else {
            cout << cipherText[j];
            j++;
        }
    }
    cout << endl;

    return 0;
}