// 解法:
// *一開始在own列表中尋找(和>50且最小)的組合，利用列舉方式會TLE
// *後來使用dp，針對(100.00-target)~100.00看看是否有own相符，有相符者標1，最後由50.01以上開始尋找，最小者即為最佳share
// *為避免double運算出錯，各小數*100變為整數
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;

// void get_subset(int target,int l,int r,vector<int> own,priority_queue<int,vector<int>,greater<int>> &co_sum,int sum=0){
//     // cout << "sum:" << sum << endl;
//     if(l>r){
//         if(sum>(5001-target) && sum<=(10000-target)){
//             co_sum.push(sum);
//             cout << "push in:" << sum << endl;
//         }
//         return;
//     }
//     get_subset(target,l+1,r,own,co_sum,sum+own[l]);
//     get_subset(target,l+1,r,own,co_sum,sum);
// }

// int get_share(int target,vector<int> own){
//     priority_queue<int,vector<int>,greater<int>> co_sum;
//     get_subset(target,0,own.size()-1,own,co_sum);
//     return co_sum.top();
// }

int main(){
    int  n,x;
    while(cin >> n >> x){
        if(!n && !x) return 0;
        vector<int> own;
        // priority_queue<int,vector<int>,greater<int>> co_sum;
        for(int in=0;in<n;in++){
            int input,share=0;
            char trash;
            cin >> input >> trash;
            share+=input*100;
            cin >> input;
            share+=input;
            own.push_back(share);
        }
        // cout << "done\n" << own[0] << endl;
        if(own[x-1]>5001){
            cout << "100.00\n";
            continue;
        }
        int target=own[x-1];
        // cout << "erase:" << *(own.begin()+(x-1)) << endl;
        own.erase(own.begin()+(x-1));
        int percent[10001]={};
        percent[0]=1;
        for(int own_num=0;own_num<own.size();own_num++){
            for(int remain_share=(10000-target-own[own_num]);remain_share>=0;remain_share--){
                if(percent[remain_share]) percent[remain_share+own[own_num]]=1;
            }
        }
        int ans_share=5001-target;
        while(!percent[ans_share]) ans_share++;
        // cout << "done\n";
        // int remain_share=get_share(target,own);
        // cout << "remain_share:" << remain_share << endl;
        double ans=(double)(target*100)/(ans_share+target);
        cout << std::fixed << std::setprecision(2) << ans << endl;
    }    
}