// 解法:
// *題目所求為找出無向圖中經過最少node的環，!!不可兩點來回!!-->利用bfs求解
// *以各tree為root做bfs:
//     1.將root放入queue，dis設為1
//     2.將queue的front tree提出(curr)
//     3.掃過curr的neighbor(next):
//         若next為curr的parent，尋找下一個neighbor(不可兩點來回)
//         (a) 若還沒走過則將dis[next]設為dis[curr]+1，並把
//         (b) 若已經走過則環的cost為dis[curr]+dis[next]-->此環即是(root~curr(next)~root)
// 以各tree做bfs後找到最小的cost
//#include<bits/stdc++.h>        
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct tree{
    vector<int> conn;
    int prev;
    tree(){
        conn.clear();
        prev=-1;
    }
};

int bfs(int index,int size,vector<tree> &set){
    int ans=size+1;
    for(int ini=0;ini<size;ini++) set[ini].prev=-1;
    int dis[size]={0};
    queue<int> q;
    q.push(index),dis[index]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int conn_index=0;conn_index<set[curr].conn.size();conn_index++){
            int next_tree=set[curr].conn[conn_index];
            if(next_tree==set[curr].prev) continue;
            if(dis[next_tree]==0){
                set[next_tree].prev=curr;
                dis[next_tree]=dis[curr]+1;
                q.push(next_tree);
            }
            else{
                ans=min(ans,(dis[curr]+dis[next_tree]-1));
            }
        }
    }
    return ans;
}

int main(){
    int cases;
    cin >> cases;
    for(int c=0;c<cases;c++){
        int n,m;
        cin >> n >> m;
        vector<tree> treeSet(n);
        for(int M=0;M<m;M++){
            int u,v;
            cin >> u >> v;
            treeSet[u].conn.push_back(v);
            treeSet[v].conn.push_back(u);
        }
        // for(int i=0;i<n;i++){
        //     cout << i << "'s tree:" << treeSet[i].prev << endl;
        //     for(int j=0;j<treeSet[i].conn.size();j++){
        //         cout << treeSet[i].conn[j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans=n+1;
        for(int bfs_index=0;bfs_index<n;bfs_index++){
            ans=min(ans,bfs(bfs_index,n,treeSet));
        }
        cout << "Case " << c+1 << ": ";
        if(ans==n+1) cout << "impossible";
        else cout << ans;
        cout << endl;
    }
}