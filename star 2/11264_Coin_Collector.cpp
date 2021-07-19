// 解法:
// *此題採貪心(greedy)演算法，亦即若有更大的幣值，應無條件納入考慮，再根據算法決定是否選定當前幣值
// *最大幣值和最小幣值(??????)必選:若以選定之幣值總和=sum，則(sum+max)為最佳解
// *type[0]~type[j]已選定之幣值總和=Sum[0,j]
// *思路: 設有n種幣值(0~n-1)，type[0]、type[n-1]已選定，若決定是否選擇type[i]，
//     --> 假設選定type[i]
//         1. Sum[0,i-1]+type[i]>=type[i+1]，則會被type[i+i]換走-->不能選擇type[i]
//             (應無條件考慮較大幣值(greedy))
//         2. Sum[0,i-1]+type[i]<type[i+1]，則不受type[i+1]干擾-->可以選擇type[i]
// 由幣值小到大重複以上思路
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int cases;
    while(cin >> cases){
        for(int i=0;i<cases;i++){
            vector <int> coin;
            int type;
            cin >> type;
            for(int j=0;j<type;j++){
                int input;
                cin >> input;
                coin.push_back(input);
            }
            int pre_sum=0;
            // for(int j=0;j<coin.size()-1;j++){
            //     pre_sum+=coin[j];
            //     if(pre_sum>=coin[j+1]){
            //         // cout << "erase:" << coin[j+1] << endl;
            //         coin.erase(coin.begin()+j+1);
            //         pre_sum-=coin[j];
            //         j--;
            //     }
            // }
            for(int j=0;j<coin.size()-1;j++){
                pre_sum+=coin[j];
                // cout << "pre_sum:" << pre_sum << endl;
                if(pre_sum>=coin[j+1]){
                    // cout << "erase:" << coin[j] << endl;
                    pre_sum-=coin[j];
                    coin.erase(coin.begin()+j);
                    j--;
                }
            }
            // for(int j=0;j<coin.size();j++) cout << coin[j] << endl;
            cout << coin.size() << endl;
            coin.clear();
        }
    }    
}