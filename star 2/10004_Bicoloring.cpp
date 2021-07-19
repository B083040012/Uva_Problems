// 解法:
// 建立node，含color(1 or -1，未上色為0)和相連node編號，輸入時建立各node的相鄰node編號，
// 接著選定編號0的node顏色為1，開始上色及檢查是否bicolorable
// 從編號0(已上色)開始:
//     *若是從訪問vector中選定的訪問對象，須從vector中移除，並從訪問array中標示已訪問
//     (1) 遇到未上色鄰node，上和當前node相反色
//         *此時要記錄node已上色，且若尚未訪問，要排入訪問vector
//     (2) 遇到已上色鄰node，檢查是否撞色(撞色-->break停止:not bicolorable)
//     (3) 從訪問vector中選擇已上色卻尚未訪問的node
// 全部node訪問完後停止-->bicolorable
// *除了一開始的上色外，其他node不能隨意上色，必須循著chain慢慢上相反色
// *若node上未上色，訪問它會失去意義，不能進行(1)和(2)
// *若edge數==0-->bicolorable

// bsf、dfs可解

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int color=0;
    vector<int> neibor_node; 
};

vector<node> node_set;
// bfs新解vvvvvvvvv
bool bfs(int index){
    for(int i=0;i<node_set[index].neibor_node.size();i++){
        int neibor_num=node_set[index].neibor_node[i];
        if(node_set[neibor_num].color==0){
            node_set[neibor_num].color=node_set[index].color*-1;
            if(bfs(neibor_num)==false) return false;
        }
        if(node_set[neibor_num].color==node_set[index].color){
            return false;
        }
    }
    return true;
}
// 新解^^^^^^^^^^^
int main(){
    int n,edge,count=0;
    while(cin >> n >> edge){
        if(edge==0){
            cout << "BICOLORABLE.\n";
            continue;
        }
        // vector<node> node_set(n);
        node temp;
        for(int i=0;i<n;i++) node_set.push_back(temp);
        bool ans=true;
        for(int i=0;i<edge;i++){
            int node1,node2;
            cin >> node1 >> node2;
            node_set[node1].neibor_node.push_back(node2);
            node_set[node2].neibor_node.push_back(node1);
        }
        node_set[0].color=1;
        ans=bfs(0);
        // 迭代舊解vvvvvvvvvvvvvvvvv
        // bool drawn[n],visit[n];
        // vector<int> can_visit;
        // for(int i=0;i<n;i++) drawn[i]=visit[i]=false;
        // drawn[0]=1;
        // for(int i=0;find(visit,visit+n,false)!=(visit+n);i=can_visit[0]){
        //     visit[i]=1;
        //     if(can_visit.size()>0) can_visit.erase(can_visit.begin());
        //     for(int j=0;j<node_set[i].neibor_node.size();j++){
        //         int neibor_num=node_set[i].neibor_node[j];
        //         if(node_set[neibor_num].color==0){
        //             node_set[neibor_num].color=node_set[i].color*-1;
        //             drawn[neibor_num]=1;
        //             if(visit[neibor_num]==0) can_visit.push_back(neibor_num);
        //         }
        //         else if(node_set[neibor_num].color*node_set[i].color==1){
        //             ans=false;
        //             break;
        //         }
        //     }
        //     if(!ans) break;
        // }
        // 舊解^^^^^^^^^^^^^^^^^^^
        if(ans) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
        count++;
        node_set.clear();
    }
}