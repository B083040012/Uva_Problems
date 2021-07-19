// 解法:
// *本題解答即需要算出2~n所有因數的和-->可利用(各因數出現次數)*(該因數)即可算出
// *faster:將所有出現相同次數的因數相加再乘上出現次數
// *實作:for迴圈進入因數i(1開始)，i的出現次數times為(n/i)，擁有相同出現次數times的因數為i~(n/times)(即floor)；
//       求i~floor總和(vecs_sum)，乘上times-->加入ans-->i設為floor
// *題目要求從2開始算(2~n)，因此ans要減去1
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(!n) return 0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long ceil=i,times=n/i,floor=n/times;
            long long vecs_sum=(ceil+floor)*(floor-ceil+1)/2;
            ans+=times*vecs_sum;
            i=floor;
        }
        cout << ans-1 << endl;
    }
}