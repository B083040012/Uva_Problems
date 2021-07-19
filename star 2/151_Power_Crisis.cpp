// Josephus Problem
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int recur_josephus(int n,int k){
    if(n==1) return 0;
    return (recur_josephus(n-1,k)+k)%n;
}

int check_josephus(int input){
    int k;
    for(k=1;;k++){
        if(recur_josephus(input-1,k)==11) break;
    }
    return k;
}

int main(){
    int N;
    while(cin >> N){
        if(!N) return 0;
        cout << check_josephus(N) << endl;
    }
}