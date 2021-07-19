//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
using namespace std;

void algorithm(long long num){
    if(num==0) return;
    else if(num<100){
        cout << " " << num;
        return;
    }
    else if(num<1000){
        algorithm(num/100);
        cout << " shata";
        num%=100;
    }
    else if(num<100000){
        algorithm(num/1000);
        cout << " hajar";
        num%=1000;
    }
    else if(num<10000000){
        algorithm(num/100000);
        cout << " lakh";
        num%=100000;
    }
    else{
        algorithm(num/10000000);
        cout << " kuti";
        num%=10000000;
    }
    algorithm(num);
}

int main(){
    long long input;
    int i=1;
    while(cin >> input){
        cout << setw(4) << i << ".";
        if(input==0){
            cout << " 0\n";
            i++;
            continue;
        }
        algorithm(input);
        cout << endl;
        i++;
    }
}