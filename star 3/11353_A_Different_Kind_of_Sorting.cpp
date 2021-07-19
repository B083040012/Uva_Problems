// 解法:
// (1) 建立一table，存放pair(質因數個數、數字本身)，且質因數個數一開始預設為1；一邊篩選質數一邊對該質數的倍數進行分解
//     EX:2為質數-->對各個2的倍數(temp)進行分解-->將table[temp].first更新為(temp/i)，表示temp的質因數個數為(1(2所貢獻)+(temp/i)的質因數個數)，
//     因此若table[temp].first非1則不用更新(已經更新過了)
// (2) 全部分解過後從頭開始更新質因數個數:
//     (a) 質數的質因數已經為1，不用更新
//     (b) 非質數則更新為(1+table[table[current].first].first)-->table[current].first即為前述的(temp/i)，此時他的質因數個數早已更新為正確答案
// (3) 依照質因數個數重新排列，使用者輸入即為index-->輸出table[input].second
//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}

int main(){
    vector<pair<int,int>> table(2000001);
    for(int i=0;i<2000001;i++){
        table[i]=make_pair(1,i);
    }
    bool visited[2000001]={false};
    table[1].second=1; visited[1]=true;
    for(int i=2;i<2000001;i++){
        if(!visited[i]){
            for(int temp=i;temp<2000001;temp+=i){
                visited[temp]=true;
                if(table[temp].first==1) table[temp].first=temp/i;  // table[temp]=table[temp/i]+1
            }
        }
    }
    for(int i=4;i<2000001;i++){
        if(table[i].first!=1){
            table[i].first=table[table[i].first].first+1;
        }
    }
    sort(table.begin(),table.end(),cmp);
    int cases=0,input;
    while(cin >> input){
        if(!input) return 0;
        cout << "Case " << cases+1 << ": " << table[input].second << endl;
        cases++;
    }
}