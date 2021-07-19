//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    string input;
    while(cin >> input){
        if(input=="0") return 0;
        while(input.length()>1){
            int sum=0;
            for(int i=0;i<input.length();i++) sum+=input[i]-'0';
            input=to_string(sum);
        }
        cout << input << endl;
    }    
}