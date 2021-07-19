//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    string num;
    while(cin >> num){
        if(num=="0") return 0;
        int sum=0;
        for(int i=0;i<num.size();i++){
            if(i%2) sum+=int(num[i]-'0');
            else sum-=int(num[i]-'0');
        }
        if(abs(sum)%11==0) cout << num << " is a multiple of 11.\n";
        else cout << num << " is not a multiple of 11.\n";
    }    
}