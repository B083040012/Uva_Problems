// 解法:
// (1) 建立31623(sqrt(10^9)) 以下之質數表
// (2) 輸入上下界L,U
// (3) 傳入count_divisor尋找質因數
// (4) num的因數個數為各(質因數個數+1)的乘積
// (5) 利用for迴圈找出最多divisor之數字

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> build_prime_list(){
    vector <int> list;
    bool visit[31623]={false};
    // bool visit[31623];
    // for(int i=0;i<31623;i++) visit[i]=false;
    for(int i=2;i<=31623;i++){
        if(!visit[i]){
            list.push_back(i);
            for(int j=2*i;j<=31623;j+=i){
                visit[j]=1;
            }
        }
    }
    return list;
}

int count_divisor(int num,vector<int> prime_list){
    int count=1,temp_count=1;
    for(int i=0;i<prime_list.size() && num>1;i++){
        // cout << "i:" << i << endl;
        // cout << "num:" << num << endl;
        while((num%prime_list[i])==0){
            temp_count++;
            num/=prime_list[i];
        }
        if(temp_count>1){
            count*=temp_count;
            temp_count=1;
        }
    }
    // cout << "count:" << count << endl;
    return count;
}

int main(){
    int N;
    vector<int> prime_list=build_prime_list();
    // for(int i=0;i<10;i++) cout << prime_list[i] << endl;
    while(cin >> N){
        for(int i=0;i<N;i++){
            int L,U,max_ans,max_dis=0;
            cin >> L >> U;
            for(int j=L;j<=U;j++){
                // cout << "j :" << j << endl;
                int divisor_num=count_divisor(j,prime_list);
                if(divisor_num>max_dis){
                    max_dis=divisor_num;
                    max_ans=j;
                }
            }
            cout << "Between " << L << " and " << U << ", " << max_ans << " has a maximum of " << max_dis << " divisors.\n";
        }
    }
}