//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void find_fa(vector<long long>& array,long long input){
    int pre=1,next=1;
    while(next<=input){
        array.push_back(next);
        int temp=pre;
        pre=next;
        next+=temp;
    }
}

void algorithm(vector<long long> array,long long input){
    int i=array.size()-1;
    while(input!=0){
        if(i<0){
            cout << "error\n";
            return;
        }
        if(input>=array[i]){
            input-=array[i];
            cout << "1";
            i--;
            if(!input) break;
            cout << "0";
            i--;
        }
        else{
            cout << "0";
            i--;
        }
    }
    for(int k=i;k>=0;k--) cout << "0"; 
}

int main(){
    int n;
    while(cin >> n){
        for(int i=0;i<n;i++){
            long long input;
            cin >> input;
            vector<long long> fa_array;
            find_fa(fa_array,input);
            // for(int k=0;k<fa_array.size();k++){
            //     cout << fa_array[k] << " ";
            // }
            // cout << endl;
            cout << input << " = ";
            algorithm(fa_array,input);
            cout << " (fib)\n";
        }
    }    
}