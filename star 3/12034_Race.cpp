// 解法:
// *採用dp算法，ways[i][j]表示i匹馬，j個名次有幾種組合
// *ways[i][j]可由兩種情形獲得:
//     (a)第i匹馬和原有名次並列:即為ways[i-1][j]並把第i匹馬併入j個名次中-->ways[i-1][j]*j
//     (b)第i匹馬不和原有名次並列:即為ways[i-1][j-1]並把第i匹馬插入j個名次間距中-->ways[i-1][j-1]*j
// -->ways[i][j]=(ways[i-1][j-1]+ways[i-1][j])*j
// *直接宣告int [1001][1001]會crash，用dynamic array較為保險

//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    // int ways[1000][1000];
    int **ways=new int*[1001];
    for(int i=0;i<1002;i++){
        ways[i]=new int[1001];
        for(int j=0;j<1002;j++) ways[i][j]=0;
    }
    // cout << "done\n";
    ways[1][1]=1;
    for(int horse_num=2;horse_num<=1000;horse_num++){
        // ways[horse_num][1]=1;
        for(int pos_num=1;pos_num<=horse_num;pos_num++){
            ways[horse_num][pos_num]=((ways[horse_num-1][pos_num-1]+ways[horse_num-1][pos_num])*pos_num)%10056;
            // cout << horse_num << " " << pos_num << " " << ways[horse_num][pos_num] << endl;
        }
    }
    int cases;
    while(cin >> cases){
        for(int ca=0;ca<cases;ca++){
            int ans=0,input;
            cin >> input;
            for(int i=1;i<=input;i++){
                ans+=ways[input][i];
                // cout << "test:" << ways[input][i] << endl;
            }
            cout << "Case " << ca+1 << ": " << ans%10056 << endl;
        }
    }
}