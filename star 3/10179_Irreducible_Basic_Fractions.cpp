// 解法:
// *利用歐拉函式解題:https://zh.wikipedia.org/wiki/%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0
// *質數建表至1000000000^0.5即可，除完這範圍內的質因數本身也會是質數了
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<long long> prime;
bool visited[32000]={false};

int main(){
    for(int i=0;i<32000;i++) visited[i]=false;
    for(int i=2;i<32000;i++){
        if(visited[i]) continue;
        prime.push_back(i);
        for(int j=i;j<32000;j+=i) visited[j]=true;
    }
    // for(int i=0;i<prime.size();i++) cout << prime[i] << endl;
    // cout << prime[3432] << endl;

    int input;
    while(cin >> input){
        if(!input) return 0;
        vector<int> prime_vec;
        int temp=input;
        for(int i=0;temp>1,i<prime.size();i++){
            if(temp%prime[i]==0){
                prime_vec.push_back(prime[i]);
                while(temp%prime[i]==0) temp/=prime[i];
                // cout << i << endl;
            }
            // cout << i << endl;
        }
        if(temp>1) prime_vec.push_back(temp);
        // for(int i=0;i<prime_vec.size();i++) cout << prime_vec[i] << endl;
        long long ans=input;
        for(int i=0;i<prime_vec.size();i++){
            ans=(ans/prime_vec[i])*(prime_vec[i]-1);
            // cout << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}