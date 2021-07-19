// 解法:
// *本題為求點對點的最短距離，因此採用Dijkstra演算法，需要多建立visited(確認node是否在集合內)、dijkstra(標示(1,1)到(i,j)的最短距離)
// *考慮不要超出邊界，因此在maze外多建立一圈-1防止越界
// *用priority_queue讓集合內的路線以距離大小排列，每一次都取最短距離的點
// *pair array在global宣告會報錯(?
// *https://zh.wikipedia.org/wiki/%E6%88%B4%E5%85%8B%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
    int x,y,dis;
    node(int x,int y,int dis):x(x),y(y),dis(dis){};
    bool operator < (const node &rnode) const{
        return dis>rnode.dis;
    }
};

int main(){
    pair<int,int> move[4]={make_pair(1,0),make_pair(-1,0),make_pair(0,-1),make_pair(0,1)};
    int cases;
    while(cin >> cases){
        for(int i=0;i<cases;i++){
            int row,col;
            cin >> row >> col;
            int map[row+2][col+2];
            bool visited[row+2][col+2]={false};
            for(int i=0;i<row+2;i++){
                for(int j=0;j<col+2;j++){
                    if(!i || !j || i==row+1 || j==col+1){
                        map[i][j]=-1;
                        visited[i][j]=true;
                    }
                    else{
                        cin >> map[i][j];
                    }
                }
            }
            int dijkstra[row+1][col+1];
            for(int j=0;j<row+1;j++){
                for(int l=0;l<col+1;l++) dijkstra[j][l]=INT32_MAX;
            }
            dijkstra[1][1]=map[1][1];
            
            priority_queue<node> n_queue;
            n_queue.push(node(1,1,map[1][1]));
            while(!n_queue.empty()){
                // cout << "in" << endl;
                node curr=n_queue.top();
                n_queue.pop();
                if(visited[curr.x][curr.y]) continue;
                visited[curr.x][curr.y]=true;
                for(int mi=0;mi<4;mi++){
                    int tx=curr.x+move[mi].first;
                    int ty=curr.y+move[mi].second;
                    if(visited[tx][ty] || map[tx][ty]==-1) continue;
                    int temp_dis=curr.dis+map[tx][ty];
                    if(temp_dis<dijkstra[tx][ty]){
                        dijkstra[tx][ty]=temp_dis;
                        node temp_node(tx,ty,dijkstra[tx][ty]);
                        n_queue.push(temp_node);
                    }
                }
            }
            cout << dijkstra[row][col] << endl;
        }
    }
}