// 解法:
// *本題採用dp法，cost[i][j]為{在第i個加油站(起點為0)、剩餘j油量時}所必須花費的最少成本
// *思路:要在第i個加油站、剩餘j油量，會有兩種情形(第i和第i-1個加油站距離為dis):
//     (1)在第(i-1)個加油站把油加到(j+dis)，開到第i個加油站時即剩(j)               -->cost[i][j]=cost[i-1][j+dis]
//     (2)在第(i-1)個加油站把油加到(j+dis-k)，開到第i個加油站時再加(k)，同樣剩餘(j) -->cost[i][j]=min(cost[i][j-k]+k*gas_price[i])
//        *不可直接用cost[i-1][j+dis-k]+k*gas_price[i]計算，因為不知道這k的油量是不是全部都從第i個加油站來
//        *(2)可以不用找k個值，因為cost[i][j-1]已經存了0~j-1的最小花費，只需要比較j-1~j這1的油要從(i-1)加還是(i)加
//     -->cost[i][j]=min(cost[i-1][j+dis],cost[i][j-1]+k*gas_price[i])
// -->實作:利用雙層for迭代，除cost[0][100]=0外，其他皆設為INF(即impossible)，
//         for: i 遞增，代表各加油站狀況:
//                 cost[i][0]必=cost[i-1][dis] (i站不加油)
//                 for: j 遞增1，代表決定這多出1的油要在(i-1)加還是在(i)加:
//                         若(j+dis>200)，代表無法在(i-1)站加油-->比較cost[i][j]和cost[i][j-1]+k*gas_price[i]
//                         否則-->比較cost[i-1][j+dis]和cost[i][j-1]+k*gas_price[i]
//         最後在cost[last_gas][100]~cost[last_gas][200]之間找出最小值即可
// *須注意:
//     (1)中途沒有加油站-->不可能(抵達目的地)or(到達且剩餘100)-->impossible
//     (2)加油站之間dis超過200-->impossible
//     (3)last_gas和目的地距離>100-->不可能(到達且剩餘100)-->impossible
//     (4)last_gas和目的地距離>0-->ans須加上多加的油
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 100000000
typedef pair<int,int> gasPair; 

int main(){
    int cases;
    vector<gasPair> gas_info;
    cin >> cases;
    while(getchar() != '\n');
    for(int ca=0;ca<cases;ca++){
        // cout << "cases:" << ca << endl;
        gas_info.clear();
        gas_info.push_back(make_pair(0,0));
        int main_dis,gas_num=0;
        char temp[50];
        cin >> main_dis;
        while(getchar() != '\n');
        while(fgets(temp,50,stdin) && temp[0]!='\n'){
            int gas_dis,gas_p;
            sscanf(temp,"%d %d",&gas_dis,&gas_p);
            gas_info.push_back(make_pair(gas_dis,gas_p));
            gas_num++;
        }
        if(gas_info.size()==1){
            cout << "Impossible\n\n";
            continue;
        }
        int cost[gas_num+10][210];
        for(int i=0;i<gas_num+1;i++){
            for(int j=0;j<201;j++){
                if(i==0 && j==100) cost[i][j]=0;
                else cost[i][j]=INF;
            }
        }
        int last_gas=gas_info.size()-1,error_flag=0;
        for(int gasNum=1;gasNum<gas_info.size();gasNum++){
            if(gas_info[gasNum].first>main_dis){
                last_gas=gasNum-1;
                break;
            }
            int sub_dis=gas_info[gasNum].first-gas_info[gasNum-1].first;
            if(sub_dis>200){
                cout << "Impossible\n\n";
                error_flag=1;
                break;
            }
            cost[gasNum][0]=cost[gasNum-1][sub_dis];
            for(int gasAmount=1;gasAmount<201;gasAmount++){
                if((gasAmount+sub_dis)>200){
                    cost[gasNum][gasAmount]=min(cost[gasNum][gasAmount],
                                            cost[gasNum][gasAmount-1]+gas_info[gasNum].second);
                }
                else{
                    cost[gasNum][gasAmount]=min(cost[gasNum-1][gasAmount+sub_dis],
                                            cost[gasNum][gasAmount-1]+gas_info[gasNum].second);
                }
            }
        }
        if(error_flag) continue;
        int ans=INF;
        for(int findAns=100;findAns<201;findAns++){
            ans=min(ans,cost[last_gas][findAns]);
        }
        if(gas_info[last_gas].first<main_dis && ans!=INF){
            int remain=main_dis-gas_info[last_gas].first;
            if(remain>100){
                cout << "Impossible\n\n";
                continue;
            }
            ans+=remain*gas_info[last_gas].second;
        }
        (ans!=INF) ? cout << ans << endl : cout << "Impossible\n";
        if(ca<cases-1) cout << '\n';
    }
    return 0;
}