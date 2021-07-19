//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    string keyboard="`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    string code;
    while(getline(cin,code)){
        for(int i=0;i<code.length();i++){
            if(code[i]==' '){
                cout << ' ';
            }
            else{
                code[i]=tolower(code[i]);
                cout << keyboard[keyboard.find(code[i])-2];
            }
        }
        cout << '\n';    
    }
    
    //cout << "\n";
}