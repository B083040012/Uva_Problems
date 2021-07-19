// 解法:
// *B為必走過的石頭(頭尾石必走，為B)
// *S為去程必走or回程必走(來回一趟所有S皆會被走過)
// -->可把全段拆為B-B分段並求出各分段解
// *B-B分段:
//     (1) 夾 0S:(B1-B2) --> Ans=B1~B2
//     (2) 夾 1S:(B1-S1-B2) --> Ans=B1~B2
//     (3) 夾 2S:(B1-S1-S2-B2) -->Ans=max(S1-B1,S2-B1,B2-S1,B2-S2)
//     (4) 夾 3S以上:模擬跳躍，且去程路線即決定回程路線:
//             a.起始跳到下一個石頭，接下來跳到下下一個石頭(確保回程時的跳躍距離不會太長)
//             b.起始跳到下下一個石頭，接下來跳到下下一個石頭
//         實際模擬a,b後發現，若B-B分段中有N個小石頭，則須計算長度皆為
//         (S1-B1),(S2-B1),(S3-S1),(S4-S2),....(Si-S(i-2)),(SN-S(N-2)),(B2-S(N-1)),(B2-SN)
//         -->用for迴圈計算，即可得出Ans
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
// #include<algorithm>
using namespace std;

int cal_max(vector<int> list,int size){
    // if(size==4) return max(max(list[head+2]-list[head],list[head+1]-list[head]),max(list[tail]-list[head+2],list[tail]-list[head+1]));
    // int temp1=max(list[head+1]-list[head],cal_max(list,head+1,tail,size-1));
    // int temp2=max(list[tail]-list[tail-1],cal_max(list,head,tail-1,size-1));
    // return max(temp1,temp2);
    // return temp2;
    int ans;
    for(int i=2;i<size;i++){
        ans=max(ans,list[i]-list[i-2]);
    }
    return ans;
}

int main(){
    int cases;
    while(cin >> cases){
        for(int j=0;j<cases;j++){
            int N,D,ans=0;
            vector<int> B_to_B;
            B_to_B.push_back(0);
            cin >> N >> D;
            if(N==0) ans=D;
            for(int i=0;i<N;i++){
                char S,trash;
                int M;
                cin >> S >> trash >> M;
                if(S=='B'){
                    if(B_to_B.size()<=2) ans=max(ans,M-B_to_B[0]);
                    else{
                        B_to_B.push_back(M);
                        int temp=cal_max(B_to_B,B_to_B.size());
                        ans=max(ans,temp);
                    }
                    if(i==N-1) ans=max(ans,D-M); 
                    B_to_B.clear();
                    B_to_B.push_back(M);
                }
                else{
                    B_to_B.push_back(M);
                    if(i==N-1){
                        B_to_B.push_back(D);
                        int temp=cal_max(B_to_B,B_to_B.size());
                        ans=max(ans,temp);
                        // if(B_to_B.size()==3) ans=max(ans,D-B_to_B[0]); 
                        // else if(B_to_B.size()>3) {
                        //     int temp=cal_max(B_to_B,B_to_B.size());
                        //     ans=max(ans,temp);
                        // }
                    }
                }
            }
            cout << "Case " << j+1 << ": " << ans << endl;        
        }
    }
}