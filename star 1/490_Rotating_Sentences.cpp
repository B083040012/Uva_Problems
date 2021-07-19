//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    vector <string> sen_array;
    string input;
    int max_size=0;
    while(getline(cin,input)){
        // if(input.length()>100){
        //     sen_array.push_back(input.substr(0,100));
        //     sen_array.push_back(input.substr(101));
        //     max_size=100;
        //     continue;
        // }
        sen_array.push_back(input);
        if(input.length()>max_size) max_size=input.length();
        if(cin.peek()==EOF) break;
    }
    for(int k=0;k<max_size;k++){
        for(int i=sen_array.size()-1;i>=0;i--){
            if(sen_array[i].length()<=k && i==0) continue;
            else if(sen_array[i].length()<=k) cout << " ";
            else cout << sen_array[i][k];
        }
        cout << endl;
    }
}