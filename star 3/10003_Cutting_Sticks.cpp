// 解法:
// 採用dp算法，將各切點之間的最小cost算出(相鄰切點cost=0)，切斷段落數(cut_len)2~n+1由小到大分別計算start~(start+cut_len)所需最小cost
// *min cost of(start~start+cut_len)=min(min_cost[start][k]+min_cost[k][start+cut_len]+len(stick[start+cut_len]-stick[start]))
// 最後得出min cost of(0~n+1)
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int l;
    while(cin >> l){
        if(!l) return 0;
        int n;
        cin >> n;
        int part_len[n+2][n+2];
        for(int i=0;i<n+2;i++){
            for(int j=0;j<n+2;j++) part_len[i][j]=0;
        }
        int stick[n+2];
        stick[0]=0;
        stick[n+1]=l;
        for(int i=1;i<n+1;i++) cin >> stick[i];
        for(int cut_len=2;cut_len<n+2;cut_len++){
            for(int start=0;start<n+1;start++){
                // cout << "start:" << start << endl;
                int end=start+cut_len;
                // cout << "end:" << end << endl;
                if(end>n+1) break;
                part_len[start][end]=INT32_MAX;
                for(int cut_point=start+1;cut_point<end;cut_point++){
                    // cout << stick[start] << " " << stick[end] << endl;
                    int min_cost=part_len[start][cut_point]+part_len[cut_point][end]+(stick[end]-stick[start]);
                    // cout << "min:" << min_cost << endl;
                    part_len[start][end]=min(part_len[start][end],min_cost);
                }
            }
        }
        cout << "The minimum cutting is " << part_len[0][n+1] << "."<< endl;
    }
    // int l,n;
    // while(cin >> l >> n){
    //     vector<int> part_len;
    //     int reg=0,ans=0;
    //     for(int i=0;i<n;i++){
    //         int input;
    //         cin >> input;
    //         part_len.push_back(input-reg);
    //         reg=input;
    //     }
    //     part_len.push_back(l-reg);
    //     for(int i=0;i<part_len.size();i++) cout << part_len[i] << " ";
    //     cout << endl;
    //     for(int i=0;i<n;i++){
    //         // cout << "i:" << i << endl;
    //         int min_temp=l+1,pointer;
    //         for(int j=0;j<part_len.size()-1;j++){
    //             if(part_len[j]+part_len[j+1]<min_temp){
    //                 min_temp=part_len[j]+part_len[j+1];
    //                 pointer=j;
    //             }
    //         }
    //         // cout << "pointer=" << pointer << endl;
    //         // cout << "min=" << min_temp << endl;
    //         part_len.insert(part_len.begin()+pointer,min_temp);
    //         cout << "erase:" << part_len[pointer+1] << " " << part_len[pointer+2] << endl;
    //         part_len.erase(part_len.begin()+pointer+1,part_len.begin()+pointer+3);
    //         // cout << "erase1\n";
    //         ans+=min_temp;
    //         for(int k=0;k<part_len.size();k++) cout << part_len[k] << " ";
    //         cout << endl;
    //     }
    //     cout << "The minimum cutting is " << ans << endl;
    // }
}