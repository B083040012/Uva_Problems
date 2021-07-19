// 解法:
// *本題採用Dijkstra演算法，不過因應題意而有變形
// *思路:今有起終點start,end，且必有一點路徑上的最大node k(k可為start或end)；
// 則列舉各點當作路徑上的最大值(即在做Dijkstra時忽略更大的點)，尋找其跟start,end的最短距離(Dijkstra)，
// 最後cost=dis(start~k)+weight(k)+dis(k~end)
// *實作:利用struct建立各點之間的關係，並列舉各點(此點為路徑最大值)到每一個點的最短路徑，
// 到不了則len=infinity，和自己len=0，最後用for迴圈尋找有最短路徑的點k，得出路徑長
// *注意Dijkstra是從具有最短路線的node開始延伸，因此要用priority_queue(用距離排序)

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> p;

int C,R,Q;

struct node{
    int w;
    vector<p> con;
    node():w(0){
        con.clear();
    }
};

void dijkstra(int index,int* len,node* n_set){
    for(int i=1;i<=C;i++) len[i]=INT32_MAX;
    len[index]=0;
    bool visited[C+1]={0};
    priority_queue<p,vector<p>,greater<p>> node_travel;
    while(!node_travel.empty()) node_travel.pop();
    node_travel.push(make_pair(0,index));
    while(!node_travel.empty()){
        int curr=node_travel.top().second;
        node_travel.pop();
        if(visited[curr]) continue;
        visited[curr]=1;
        for(auto ptr=0;ptr<n_set[curr].con.size();ptr++){
            int temp_node=n_set[curr].con[ptr].first;
            if(n_set[temp_node].w>n_set[index].w) continue;
            int temp_len=n_set[curr].con[ptr].second+len[curr];
            if(temp_len<len[temp_node]){
                // if(index==1){
                //     cout << "curr:" << curr << endl;
                //     cout << "temp_node:" << temp_node << endl;
                //     cout << "temp_len:" << temp_len << endl;
                // }
                len[temp_node]=temp_len;
                node_travel.push(make_pair(temp_len,temp_node));
            }
        }
        // cout << "\n\n";
    }
    // for(int i=1;i<=C;i++) cout << "len:" << len[i] << endl;
    // cout << "end\n";
}

int main(){
    int cases=0;
    while(cin >> C >> R >> Q){
        if(C+R+Q==0) return 0;
        struct node n_set[C+1];
        int len[C+1][C+1];
        for(int i=1;i<=C;i++) cin >> n_set[i].w;
        // for(int i=1;i<=C;i++) cout << n_set[i].w << " ";
        for(int R_in=0;R_in<R;R_in++){
            int a,b,l;
            cin >> a >> b >> l;
            n_set[a].con.push_back(make_pair(b,l));
            n_set[b].con.push_back(make_pair(a,l));
            // cout << n_set[a].con[0].first << endl;
        }
        for(int max_in=1;max_in<=C;max_in++) dijkstra(max_in,len[max_in],n_set);
        if(cases>0) cout << "\n";
        cout << "Case #" << cases+1 << endl;
        for(int Q_in=0;Q_in<Q;Q_in++){
            int start,end,middle,ans=INT32_MAX;
            cin >> start >> end;
            for(middle=1;middle<=C;middle++){
                if(len[middle][start]==INT32_MAX || len[middle][end]==INT32_MAX) continue;
                ans=min(ans,n_set[middle].w+len[middle][start]+len[middle][end]);
                // if(cases==0) cout << "middle=" << middle << " " << "ans=" << ans << endl;
            }
            if(ans==INT32_MAX) cout << "-1\n";
            else cout << ans << endl;
        }
        cases++;
    }
}