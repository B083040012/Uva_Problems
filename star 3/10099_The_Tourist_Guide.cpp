// 解法:
// 類似於uva 10048,利用floyd找出最多承載人數後，ceil(T/(dis[S][D]-1))即為答案(-1是因為導遊不能算進去)
// *floyd:
//     if(dis[x][mid]==INT16_MAX || dis[mid][y]==INT16_MAX) continue;
//     if(dis[x][y]==INT16_MAX) dis[x][y]=min(dis[x][mid],dis[mid][y]);
//     else dis[x][y]=max(dis[x][y],min(dis[x][mid],dis[mid][y]));
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int cases=0,N,R;
    while(cin >> N >> R){
        if(!N && !R) return 0;
        int **dis=new int*[N+5];
        for(int inix=0;inix<N+5;inix++){
            dis[inix]=new int[N+5];
            for(int iniy=0;iniy<N+5;iniy++){
                if(inix==iniy) dis[inix][iniy]=0;
                else dis[inix][iniy]=INT16_MAX;
            }
        }
        for(int r=0;r<R;r++){
            int c1,c2,p;
            cin >> c1 >> c2 >> p;
            dis[c1][c2]=dis[c2][c1]=p;
        }
        int S,D;
        double T;
        cin >> S >> D >> T;
        // Floyd
        for(int mid=1;mid<=N;mid++){
            for(int x=1;x<=N;x++){
                for(int y=1;y<=N;y++){
                    if(dis[x][mid]==INT16_MAX || dis[mid][y]==INT16_MAX) continue;
                    if(dis[x][y]==INT16_MAX) dis[x][y]=min(dis[x][mid],dis[mid][y]);
                    else dis[x][y]=max(dis[x][y],min(dis[x][mid],dis[mid][y]));
                }
            }
        }
        // cout << "test:" << dis[1][7] << endl;
        // int ans=T/dis[S][D];
        // if(T%dis[S][D]) ans++;
        cout << "Scenario #" << ++cases << endl;
        cout << "Minimum Number of Trips = " << ceil(T/(dis[S][D]-1)) << endl << endl;
    }    
}