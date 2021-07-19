// 解法:
// *-O3編譯
// *先建立歐拉函式表phi，接著由小而大更新depthphi表:
//     depthphi更新方法:depthphi[i]=1 (歐拉step1) + depthphi[phi[i]] (eular(i)的depth)
// 接著由小而大更新sum表:
//     sum[i]表示sum(depthphi[1]+...depthphi[i]) --> 因此sum[i]=sum[i-1]+depthphi[i]
// 最後ans=sum[n]-sum[m-1] (sum(depthphi[1]+...depthphi[n])-sum(depthphi[1]+...depthphi[m-1]))
// *特別注意歐拉建表方法!!!
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

#define size 2000005
#define ll long long

int main(){
    int *phi=new int[size];
    int *depthphi=new int[size];
    int *sum=new int[size];

    // eular 建表
    for(int p=1;p<size;p++){
        phi[p]=p;
    }
    for(int p=2;p<size;p++){
        if(phi[p]==p){
            for(int p2=p;p2<size;p2+=p){
                phi[p2]=(phi[p2]/p)*(p-1);
            }
        }
    }
    // for(int i=1;i<10;i++) cout << phi[i] << endl;
    // cout << "phi done\n";

    depthphi[1]=0;
    sum[1]=0;
    for(int dep=2;dep<=size;dep++){
        // cout << "phi[dep]=" << phi[dep] << endl;
        depthphi[dep]=depthphi[phi[dep]]+1;
        // cout << depthphi[dep] << endl;
        sum[dep]=sum[dep-1]+depthphi[dep];
    }
    // cout << "depthphi/sum done\n";
    
    int cases;
    cin >> cases;
    while(cases--){
        int m,n;
        cin >> m >> n;
        cout << sum[n]-sum[m-1] << endl;
    }
}