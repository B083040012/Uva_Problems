//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int gcd(int a,int b){
    if(!b) return a;
    else return gcd(b,a%b);
}

int main(){
    vector<int> seq;
    int input;
    while(cin >> input){
        if(!input && !seq.size()) return 0;
        if(!input){
            int ans=abs(seq[1]-seq[0]);
            for(int i=2;i<seq.size();i++){
                ans=gcd(ans,abs(seq[i]-seq[i-1]));
            }
            cout << ans << endl;
            seq.clear();
        }
        else{
            seq.push_back(input);
        }
    }
}