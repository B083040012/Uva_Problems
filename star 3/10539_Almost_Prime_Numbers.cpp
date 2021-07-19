// 解法:
// *建立一範圍2~1e6(12/2)的質數表，
//     先針對[1~high]進行判斷，    若(質數^n)在範圍內-->ans++
//     再針對[1~low-1]進行判斷，   若(質數^n)在範圍內-->ans--
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    vector<int> prime;
    bool visited[(int)1e6]={false};
    for(int i=2;i<1e6;i++){
        if(visited[i]) continue;
        prime.push_back(i),visited[i]=true;
        for(int j=i*2;j<1e6;j+=i) visited[j]=true;
    }
    // for(int i=0;i<10;i++){
    //     cout << prime[i] << endl;
    // }
    int cases;
    cin >> cases;
    for(int c=0;c<cases;c++){
        long long low,high,ans=0;
        cin >> low >> high;

        for(int i=0;pow(prime[i],2)<high;i++){
            // if(prime[i]<low) continue;
            long long tmp=prime[i];
            // tmp=floor(pow(high,(1.0/prime[i])))-1;
            // tmp-=floor(pow(low-1,(1.0/prime[i])));
            // cout << "tmp:" << tmp << endl;
            while((tmp*prime[i])<=high){
                ans++;
                tmp=tmp*prime[i];
            }
            // ans+=tmp;
        }
        for(int i=0;pow(prime[i],2)<low;i++){
            long long tmp=prime[i];
            while((tmp*prime[i])<low){
                ans--;
                tmp=tmp*prime[i];
            }
            // ans-=tmp;
        }

        cout << ans << endl;
    }    
}