//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string input1,input2;
    while(getline(cin,input1),getline(cin,input2)){
        // if(input1=="" || input2==""){
        //     cout << endl;
        //     continue;
        // }
        int ptr1=0,ptr2=0;
        sort(input1.begin(),input1.end());
        sort(input2.begin(),input2.end());
        for(int i=0;i<26,ptr1<input1.length(),ptr2<input2.length();i++){
            while(input1[ptr1]<'a'+i && ptr1<input1.length()) ptr1++;
            while(input2[ptr2]<'a'+i && ptr2<input2.length()) ptr2++;
            while(input1[ptr1]=='a'+i && input2[ptr2]=='a'+i){
                cout << char('a'+i);
                ptr1++; ptr2++;
            }
        }
        cout << endl;
    }
}