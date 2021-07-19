// 解法:
// *此題相當於-->求出leaf數量為N的樹中有幾個不是二元樹
// *二元樹數量=Catalan Number:C(0)=C(1)=1,C(i)=C(i-1)*(4i-2)/(i+1)
// *全部可能的樹數量=Schröder–Hipparchus Number:S(1)=S(2)=1,S(i)=((6i-9)*S(i-1)-(i-3)*S(i-2))/i
// *須注意Catalan是從C(0)開始，Schröder–Hipparchus是從S(1)開始，因此在計算上需要注意
// *實作:利用vector建表(遞迴速度太慢)，在輸出相減結果
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<long long> catalan;
    for(int i=0;i<27;i++){
        if(i<2) catalan.push_back(1);
        else{
            long long c;
            c=(catalan[i-1]*(4*i-2))/(i+1);
            catalan.push_back(c);
        }
    }
    // for(int i=0;i<27;i++) cout << catalan[i] << endl;
    // cout << "catalan done\n" << endl;
    vector<long long> hippar;
    for(int i=0;i<27;i++){
        if(i<3) hippar.push_back(1);
        else{
            long long s;
            s=(((6*i-9)*hippar[i-1])-((i-3)*hippar[i-2]))/i;
            hippar.push_back(s);
        }
    }
    // for(int i=0;i<27;i++) cout << hippar[i] << endl;
    // cout << "hippar done\n" << endl;
    long long n;
    while(cin >> n){
        cout << hippar[n]-catalan[n-1] << endl;
        // cout << catalan[n]-hippar[n] << endl;
    }    
}