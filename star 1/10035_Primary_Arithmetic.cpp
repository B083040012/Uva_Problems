//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//使用vector存取各個位數，再進行計算

int main(){
    long long input1,input2;
    while(1){
        cin >> input1 >> input2;
        if(input1==0 && input2==0) break;
        int count=0;
        if(input1<input2) swap(input1,input2); //判斷大小，使v1為較大數
        long long temp_c=0;
        while(input2!=0){
            temp_c=(input1%10+input2%10+temp_c)/10;;
            if(temp_c==1) count++;
            input1/=10;
            input2/=10;
        }
        while(input1!=0){
            temp_c=(input1%10+temp_c)/10;
            if(temp_c==1) count++;
            input1/=10;
        }
        if(count==0) cout << "No carry operation.\n";
        else if(count==1) cout << count << " carry operation.\n";
        else cout << count << " carry operations.\n";
    }
}