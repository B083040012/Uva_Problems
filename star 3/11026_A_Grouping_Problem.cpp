// 解法:
// *本題利用dp演算法,dp[i][j]代表[前i個數字][取j個數字作為subset]的情況下的fitness
// *dp formula:
//     (a) j=0 --> dp[i][j]=1  (方便後續(b)狀況時相乘不會出錯)
//     (b) j<=i--> dp[i][j]=dp[i-1][j-1]*element[i](代表有第i個元素在內的subset,(a)便是要應對此情形)
//                          +dp[i-1][j](代表沒有第i個元素在內的subset)
//     (c) o.w -->dp[i][j]=0
// *要在dp運算時mod以防overflow
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    long long N,M;
    while(cin >> N >> M){
        if(!N && !M) return 0;
        long long ele[N+5],**dp=new long long*[N+5];
        for(int inix=0;inix<N+5;inix++){
            dp[inix]=new long long[N+5];
            for(int iniy=0;iniy<N+5;iniy++){
                if(iniy==0) dp[inix][iniy]=1;
                else dp[inix][iniy]=0;
            }
        }
        for(int n=1;n<=N;n++){
            cin >> ele[n];
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dp[i][j]=((dp[i-1][j-1]*ele[i])%M+dp[i-1][j])%M;
            }
        }
        long long ans=-1;
        for(int j=1;j<=N;j++){
            ans=max(ans,dp[N][j]);
        }
        cout << ans << endl;
    }    
}