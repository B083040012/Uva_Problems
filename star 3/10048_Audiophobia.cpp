// 解法:
// *題目所求為找出最小的[路徑最大值]，利用floyd並在更新時先選出dis(x~out)及dis(out~y)的最大值，再和dis(x~y)比較是否何者較小
// *實作時先將自身到自身的cost設為0，其餘設為無限大
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int cases=0,C,S,Q;
    while(cin >> C >> S >> Q){
        if(C==0 && S==0 && Q==0) return 0;
        if(cases>0) cout << endl;
        cases++;
        int **dis=new int *[C+5];
        for(int inix=0;inix<C+5;inix++){
            dis[inix]=new int[C+5];
            for(int iniy=0;iniy<C+5;iniy++){
                if(inix==iniy) dis[inix][iniy]=0;
                else dis[inix][iniy]=INT16_MAX;
            }
        }
        for(int s=0;s<S;s++){
            int c1,c2,d;
            cin >> c1 >> c2 >> d;
            dis[c1][c2]=dis[c2][c1]=d;
        }
        for(int out=1;out<=C;out++){
            for(int x=1;x<=C;x++){
                for(int y=1;y<=C;y++){
                    int tmpEdge=max(dis[x][out],dis[out][y]);
                    dis[x][y]=min(dis[x][y],tmpEdge);
                }
            }
        }
        cout << "Case #" << cases << endl;
        for(int q=0;q<Q;q++){
            int c1,c2;
            cin >> c1 >> c2;
            if(dis[c1][c2]==INT16_MAX) cout << "no path\n";
            else cout << dis[c1][c2] << endl;
        }
    }
}