// Cryptography and Network Security Lab
// Assignment 5
// Onkar Gavali
// 2019BTECS00037
// Batch B2
// This program implements the Columnar Cipher
#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

char upper(char c){
	if(c>='a' && c<='z') return 'A'+c-'a';
	return c;
}
string encrypt(string plainText, string key){
    string cipherText{};
    map<char,string> columnar;
	cout<<endl;
	cout<<"Table:\n";
    for(size_t i = 0, j=0; i < plainText.size(); i++, j=(j+1)%key.size()){
    	if(plainText[i]==' '){
    		j--;
			continue;
		}
        columnar[key[j]]+=upper(plainText[i]);
        cout<<plainText[i];
        if(j==key.size()-1) cout<<endl;
    }
    for(auto a:columnar){
        cipherText+=a.second;
    }
    return cipherText;
}

string dencrypt(string cipherText, string key){
    map<char,list<char>> m;
	auto sortedkey=key;
	sort(sortedkey.begin(),sortedkey.end());
	int q=cipherText.length()/key.length();
	int re=cipherText.length()%key.length();
	int z=cipherText.length(),k=0;
   for(int i=0;i<key.length();++i){
		int j=0;
		for(j=0;j<q;++j){
			m[sortedkey[i]].push_back(cipherText[k]);
			++k;
		}
		if(re>0){
			m[sortedkey[i]].push_back(cipherText[k]);
			k++;
			re--;
		}
   }
   if(cipherText.length()%key.length()>1){
   	q++;
   }
   string plaintext="";
    for(int i=0;i<q;++i){
    	for(int j=0;j<key.length();++j){
    		if(m[key[j]].size()>0){
    			plaintext+=m[key[j]].front();
    			m[key[j]].pop_front();	
			}
		}
	}
    return plaintext;
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

    cout << " Encryption:" << endl;

    string encryptedText = encrypt(text, key);
    cout << "\nEncrypted Text: " << encryptedText << endl;
	
	
	string decrytedText = dencrypt(encryptedText, key);
    cout << "\decrytedText Text: " << decrytedText << endl;
    return 0;
}