// 解法:
// *最大值求解:先完成所有加法運算，再進行乘法運算
// *最小值求解:先完成所有乘法運算，再進行加法運算
// (1) 讀入字串，分割operator和number分別存入vector
//     (注意number的vector型態為long long，否則會爆掉)
// (2) 最大/最小值求解:在operator vector中find '*'/'+'，接著運算相對應位置的num vector，
//     算完erase operator和舊number，直到沒有'*'/'+'，最後對num vector全部進行'+'/'*'運算
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long cal_min(vector<long long> num_temp,vector<char> op_temp){
    long long sum=0;
    vector<long long> num=num_temp;
    vector<char> op=op_temp;
    while(1){
        vector<char>::iterator it=find(op.begin(),op.end(),'*');
        if(it==op.end()) break;
        long long num_po=it-op.begin();
        num[num_po+1]*=num[num_po];
        // cout << num[num_po] << endl;
        num.erase(num.begin()+num_po);
        op.erase(it);
    }
    for(long long i=0;i<num.size();i++) sum+=num[i];
    return sum;
}

long long cal_max(vector<long long> num_temp,vector<char> op_temp){
    long long product=1;
    vector<long long> num=num_temp;
    vector<char> op=op_temp;
    while(1){
        vector<char>::iterator it=find(op.begin(),op.end(),'+');
        if(it==op.end()) break;
        int num_po=it-op.begin();
        num[num_po+1]+=num[num_po];
        // cout << num[num_po+1] << endl;
        num.erase(num.begin()+num_po);
        op.erase(it);
    }
    for(int i=0;i<num.size();i++) product*=num[i];
    return product;
}

int main(){
    int cases;
    while(cin >> cases){
        for(int i=0;i<cases;i++){
            string input;
            vector<long long> num;
            vector<char> op;
            int pointer=0;
            cin >> input;
            while(input[pointer]!='+' && input[pointer]!='*' && pointer<input.length()) pointer++;
            num.push_back(atoi((input.substr(0,pointer)).c_str()));
            // cout << "check\n";
            while(pointer<input.length()){
                // cout << "pointer:" << pointer << endl;
                op.push_back(input[pointer]);
                pointer++;
                int begin=pointer;
                while((input[pointer]!='+' && input[pointer]!='*') && pointer<input.length()) pointer++;
                num.push_back(atoi((input.substr(begin,pointer-begin)).c_str()));
            }
            // for(int j=0;j<num.size();j++) cout << "num:" << num[j] << endl;
            // for(int j=0;j<op.size();j++) cout << "op" << op[j] << endl;
            cout << "The maximum and minimum are " << cal_max(num,op) << " and " << cal_min(num,op) << "." << endl;
        }
    }    
}