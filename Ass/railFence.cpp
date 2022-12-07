// Cryptography and Network Security Lab
// Assignment 4
// Onkar Gavali
// 2019BTECS00037
// Batch B2
// The program implements the railfence cipher algorithm


#include <iostream>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;

char upper(char c){
	if(c>='a' && c<='z') return 'A'+c-'a';
}
string encrypt(string plainText, size_t depth){
    string encryption="";
    map<int,string> m;
    int flag=+1,d=0;
    for(int i=0;i<plainText.length();++i){
    	if(plainText[i]==' ')continue;
    	m[d]+=upper(plainText[i]);
    	if(d==depth-1){
    		flag=-1;
		}else if(d==0){
			flag=1;
		}
		d+=flag;
	}
	int i=0;
    for(auto a:m){
    	cout<<"line :"<<i<<" "<<a.second<<endl;
    	encryption+=a.second;
    	i++;
	}
    
    return encryption;
    
    
}

string decrypt(string encryptedText, size_t depth){
    int curLevel = 0;
    int turn = 1;
    vector<int> counts(depth, 0);
    
    for(int i=0;i<encryptedText.length();i++)
    {
        counts[curLevel]++;
        if(curLevel == depth - 1 && turn == 1)
        {
            turn = -1;
        }
        else if(curLevel == 0 && turn == -1)
        {
            turn = 1;
        }
        curLevel += turn;
    }
    vector<string> letters(depth);
    int start_index = 0;
    for(int i=0;i<depth;i++)
    {
        int c = counts[i];
        letters[i] = encryptedText.substr(start_index,c);
        start_index += c;
    }
    string plaintext;
    fill(counts.begin(),counts.end(),0);
    curLevel = 0;
    turn = 1;
    for(int i=0;i<encryptedText.length();i++)
    {
        plaintext += letters[curLevel][counts[curLevel]];
        counts[curLevel]++;

        if(curLevel == depth - 1 && turn == 1)
        {
            turn = -1;
        }
        else if(curLevel == 0 && turn == -1)
        {
            turn = 1;
        }
        curLevel += turn;
    }
    return plaintext;
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