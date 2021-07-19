//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
//#include<cstring>
using namespace std;

int main(){
    string input;
    int count=0;
    while(getline(cin,input)){
        vector<char> sen;
        for(int i=0;i<input.size();i++){
            if(input[i]=='"' && count==0){
                count=1;
                sen.push_back('`');
                sen.push_back('`');
            }
            else if(input[i]=='"' && count==1){
                count=0;
                sen.push_back('\'');
                sen.push_back('\'');
            }
            else sen.push_back(input[i]);
        }
        for(int i=0;i<sen.size();i++) cout << sen[i];
        cout << endl;
        if(cin.peek()==EOF) break;
        sen.clear();
    }   
}