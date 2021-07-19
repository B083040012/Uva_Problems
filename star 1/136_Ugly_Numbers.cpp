#include<bits/stdc++.h>
// #include<iostream>
// #include<cmath>
// #include<vector>
using namespace std;

int main(){
    // my way:take too much time!!!
    // int count=1;
    // for(int i=2;;i++){
    //     int temp=i;
    //     while(temp%2==0) temp/=2;
    //     while(temp%3==0) temp/=3;
    //     while(temp%5==0) temp/=5;
    //     if(temp==1) count++;
    //     if(count==1300){
    //         cout << "The 1500'th ugly number is " << i << endl;
    //         break;
    //     }
    // }
    const int factor[3]={2,3,5};
    priority_queue<long long,vector<long long>,greater<long long>> ans;
    set<long long> check;
    ans.push(1);
    check.insert(1);
    for(int k=0;k<1500;k++){
        long long order_num=ans.top();
        ans.pop();
        if(k==1499){
                cout << "The 1500'th ugly number is " << order_num << "." << endl;
                break;
            }
        for(int i=0;i<3;i++){
            long long ans_num=factor[i]*order_num;
            if(!check.count(ans_num)){
                ans.push(ans_num);
                check.insert(ans_num);
            }
        }
    }
}