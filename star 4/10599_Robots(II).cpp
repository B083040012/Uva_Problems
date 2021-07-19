// 解法:
// *建立map紀錄garbage所在地、garSet記錄各個garbage座標和位置號碼並依位置號碼由小到大排列、
// cleaned_num紀錄經過i點時清理過garbage的數量、path_num紀錄[經過i點 and 有最多清理數量時]擁有的路徑數量、
// path[i]紀錄最多清理量路徑上，i點的前一個garbage index
// *終點為map[sizer][sizec]，因此將其push進garSet，若終點實際上不是garbage-->cleaned_num[gar_num-1]需減1、不須push終點進入ans_path
// *更新cleaned_num、path_num、path時必須注意:
//     若gar[x]在gar[y]左方-->gar[x]無法繼承gar[y]的路線，無須再做更新
//     否則:
//         (a) cleaned_num[x]==cleaned_num[y]+1:擁有相同最大清理量-->x點上路徑繼承y點上路徑(path_num[x]+=path_num[y])
//         (b) cleaned_num[x]<cleaned_num[y]+1:從y衍生的路徑擁有更多清理量
//             -->(1) 經過x點時可以有更大的清理量-->cleaned_num[x]=cleaned_num[y]+1
//                (2) 最多清理量路徑上，經過x點的前一點為y-->path[x]=y
//                (3) x點上路徑更新為y點上路徑(原本的路徑必須直接捨棄，因為清理量太少)-->path_num[x]=path_num[y]
// *最後以終點(gar-1)為主輸出答案(須注意)終點是否為garbage
// *為了可以達成升序輸出path座標的要求，先將path座標反向push進ans_path再一併輸出
//#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct garbage{
    int locx,locy,num;
    garbage(int x,int y,int sizec){
        locx=x,locy=y,num=(locx-1)*sizec+locy;
    }
};

int main(){
    int cases=1,sizer,sizec;
    while(cin >> sizer >> sizec){
        if(sizer==-1 && sizec==-1) return 0;
        bool map[sizer+5][sizec+5];
        vector<garbage> garSet;
        for(int inix=0;inix<sizer+5;inix++){
            for(int iniy=0;iniy<sizec+5;iniy++){
                map[inix][iniy]=false;
                // if(inix==sizer && iniy==sizec) map[inix][iniy]=true;
            }
        }

        int garx,gary;
        while(cin >> garx >> gary){
            if(!garx && !gary) break;
            map[garx][gary]=true;
        }

        for(int x=1;x<=sizer;x++){
            for(int y=1;y<=sizec;y++){
                if(map[x][y]) garSet.push_back(garbage(x,y,sizec));
            }
        }
        int gar_num=garSet.size();
        if(map[sizer][sizec]==false){
            gar_num++;
            garSet.push_back(garbage(sizer,sizec,sizec));
        }

        // int gar_num=garSet.size();
        int cleaned_num[gar_num+5]={1},path_num[gar_num+5]={1},path[gar_num+5]={-1};
        for(int ini=0;ini<gar_num+5;ini++){
            cleaned_num[ini]=path_num[ini]=1;
            path[ini]=-1;
        }
        for(int x=0;x<=gar_num;x++){
            for(int y=0;y<x;y++){
                if(garSet[x].locy<garSet[y].locy) continue;
                if(cleaned_num[x]-1==cleaned_num[y]) path_num[x]+=path_num[y];
                else if(cleaned_num[x]-1<cleaned_num[y]){
                    cleaned_num[x]=cleaned_num[y]+1;
                    path[x]=y;
                    path_num[x]=path_num[y];
                }
            }
        }
        if(map[sizer][sizec]==false) cleaned_num[gar_num-1]--;

        cout << "CASE#" << cases++ << ": " << cleaned_num[gar_num-1] <<  " " << path_num[gar_num-1];
        vector<int> ans_path;
        int path_index=gar_num-1;
        if(map[sizer][sizec]) ans_path.push_back(sizer*sizec);
        path_index=path[path_index];
        while(path_index!=-1){
            ans_path.push_back(garSet[path_index].num);
            path_index=path[path_index];
        }
        // for(int i=0,pr=0;pr<cleaned_num[gar_num-1] && i<=gar_num;i++){
        //     // cout << "pr:" << pr << endl;
        //     if(path[i]!=-1 && path[i]!=path[i-1]){
        //         cout << " " << garSet[path[i]].num;
        //         pr++;
        //     }
        // }
        for(int i=ans_path.size()-1;i>=0;i--){
            cout << " " << ans_path[i];
        }
        cout << endl;
    }
}