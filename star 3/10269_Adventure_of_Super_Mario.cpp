// 解法:
// 1.先利用floyd演算法將各點的最短距離求出，若要經過城堡則為無限大，存入dis(用於判斷是否可以使用跑鞋)
// 2.接著利用dijkstra算出dp[i][j](表示從第i點到終點(A+B點)，用過j次跑鞋的cost)
//     以k為中繼點:
//     (a) 若使用跑鞋次數不變，以k為中繼點cost較少
//         dp[i][j]=dp[k][j]+dis[k][i]
//     (b) 若從i到k可以使用跑鞋且跑鞋能可使用，且cost減少
//         dp[i][j+1]=dp[k][j]
// *最後能要從dp[1][i]中尋找最小解
//#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

struct node{
    int nodeIndex,shoeTime,cost;
    node(int n,int s,int c){
        nodeIndex=n,shoeTime=s,cost=c;
    }
    bool operator < (const node& r) const{
        return cost>r.cost;
    }
};

int dijkstra(int **dis,int tol,int time,int len){
    int dp[tol+5][time+5];
    for(int inix=1;inix<=tol;inix++){
        for(int iniy=0;iniy<=time;iniy++){
            dp[inix][iniy]=INT16_MAX;
        }
    }
    priority_queue<node> set;
    dp[tol][0]=0;
    set.push(node(tol,0,0));
    while(!set.empty()){
        int curr_index=set.top().nodeIndex,curr_time=set.top().shoeTime;
        // cout << "test:" << curr_index << " " << curr_time << " " << dp[curr_index][curr_time] << endl;
        set.pop();
        for(int n=1;n<=tol;n++){
            if(n==curr_index || dis[curr_index][n]==INT16_MAX) continue;
            // cout << dp[curr_index][curr_time]+dis[curr_index][n] << endl;
            // cout << dp[n][curr_time] << "\n\n\n";
            if(dp[n][curr_time]>dp[curr_index][curr_time]+dis[curr_index][n]){
                // cout << "in1 " << n << " ";
                dp[n][curr_time]=dp[curr_index][curr_time]+dis[curr_index][n];
                // cout << dp[n][curr_time] << endl;
                set.push(node(n,curr_time,dp[n][curr_time]));
            }
            if(dis[curr_index][n]<=len && curr_time<time && dp[n][curr_time+1]>dp[curr_index][curr_time]){
                // cout << "in2 " << n << " ";
                dp[n][curr_time+1]=dp[curr_index][curr_time];
                // cout << dp[n][curr_time+1] << endl;
                set.push(node(n,curr_time+1,dp[n][curr_time+1]));
            }
        }
    }
    int ans=INT16_MAX;
    for(int a=0;a<=time;a++){
        ans=min(ans,dp[1][a]);
    }
    return ans;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        int A,B,M,L,K;
        cin >> A >> B >> M >> L >> K;
        int tol=A+B;
        int **dis=new int*[tol+5];
        for(int inix=0;inix<=tol;inix++){
            dis[inix]=new int[tol+5];
            for(int iniy=0;iniy<=tol;iniy++){
                if(iniy==inix) dis[inix][iniy]=0;
                else dis[inix][iniy]=INT16_MAX;
            }
        }
        while(M--){
            int x,y,l;
            cin >> x >> y >> l;
            dis[x][y]=dis[y][x]=l;
        }
        for(int out=1;out<=A;out++){
            for(int x=1;x<=tol;x++){
                for(int y=1;y<=tol;y++){
                    if(x!=out && x!=y && dis[x][out]!=INT16_MAX && dis[out][y]!=INT16_MAX) 
                        dis[x][y]=min(dis[x][y],dis[x][out]+dis[out][y]);
                }
            }
        }
        // for(int x=1;x<=tol;x++){
        //     for(int y=1;y<=tol;y++){
        //         cout << dis[x][y] << " ";
        //     }
        //     cout << endl;
        // }
        int ans=dijkstra(dis,tol,K,L);
        cout << ans << endl;
    }
}