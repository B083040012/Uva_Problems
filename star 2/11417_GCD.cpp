//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int gcd(int a,int b){
    if(!b) return a;
    else return gcd(b,a%b);
}

int main(){
    int n;
    while(cin >> n){
        if(!n) return 0;
        int G=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++) G+=gcd(j,i);
        }
        cout << G << endl;
    }
}