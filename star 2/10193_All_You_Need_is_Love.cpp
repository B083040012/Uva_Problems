// 解法:
// 令使用者輸入兩字串s1,s2，先把兩字串轉換成十進位制(binary_to_decimal)，
// 接著找出兩數字的公因數，此處一開始使用for迴圈尋找得到Time limit exceeded，
// 為了降低複雜度最終使用輾轉相除尋找最大公因數，若最大公因數>1有解，反之則無。
//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

int binary_to_decimal(string input){
    int sum=0;
    for(int i=input.length()-1;i>=0;i--){
        if(input[i]=='1') sum+=pow(2,input.length()-1-i);
    }
    return sum;
}

int find_love(int s1,int s2){
    if(s1<s2) return find_love(s2,s1);
    if(!s2 && s1==1) return 0;
    else if(!s2 && s1) return 1;
    else return find_love(s2,s1%s2);
}

int main(){
    int pair;
    while(cin >> pair){
        for(int i=0;i<pair;i++){
            string s1,s2;
            cin >> s1 >> s2;
            cout << "Pair #" << i+1 << ": ";
            // cout << binary_to_decimal(s1) << '\n' << binary_to_decimal(s2) << endl;
            if(find_love(binary_to_decimal(s1),binary_to_decimal(s2))) cout << "All you need is love!\n"; 
            else cout << "Love is not all you need!\n";
        }
    }    
}