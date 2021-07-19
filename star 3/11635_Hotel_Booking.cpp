// TLE Problem,not solved yet !!!

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;

struct city{
    vector<pair<int,int>> con;
    city(){
        con.clear();
    }
};

void Dijkstra(int start,int* map,city* citySet){
    for(int ini=0;ini<n;ini++) map[ini]=INT32_MAX;
    map[start]=0;
    bool visited[n]={false};
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> travel;
    // while(!travel.empty()) travel.pop();
    travel.push(make_pair(0,start));
    while(!travel.empty()){
        // cout << travel.top().second << endl;
        int curr_city=travel.top().second;
        travel.pop();
        if(visited[curr_city]) continue;
        visited[curr_city]=true;
        // cout << "visited:" << visited[curr_city] << endl;
        // cout << "curr_city:" << curr_city << endl;
        for(auto ptr=0;ptr<citySet[curr_city].con.size();ptr++){
            int tmp_city=citySet[curr_city].con[ptr].first;
            // cout << tmp_city << endl;
            int tmp_len=citySet[curr_city].con[ptr].second+map[curr_city];
            if(map[tmp_city]>tmp_len){
                map[tmp_city]=tmp_len;
                travel.push(make_pair(tmp_len,tmp_city));
            }
        }
        // cout << "done\n";
    }
}

int main(){
    while(cin >> n){
        if(!n) return 0;
        struct city citySet[n];
        int map[n][n];
        int hotel_num,path_num;
        cin >> hotel_num;
        int hotel_temp=hotel_num;
        bool hotel_index[n]={false};
        hotel_index[0]=hotel_index[n-1]=true;
        for(int h=0;h<hotel_num;h++){
            int input;
            cin >> input;
            if(input==1 || input==n) hotel_temp--;
            hotel_index[input-1]=true;
        }
        cin >> path_num;
        for(int p=0;p<path_num;p++){
            int sou,des,dis;
            cin >> sou >> des >> dis;
            citySet[sou-1].con.push_back(make_pair(des-1,dis));
            citySet[des-1].con.push_back(make_pair(sou-1,dis));
        }
        // for(int c=0;c<n;c++){
        //     cout << c << ":" << endl;
        //     for(auto ptr=0;ptr<citySet[c].con.size();ptr++){
        //         cout << citySet[c].con[ptr].first << " " << citySet[c].con[ptr].second << endl;
        //     }
        // }
        int temp[105][105];
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                temp[i][j]=100000000;
            }
        }
        int xptr=0,yptr=0;
        for(int dijk=0;dijk<n;dijk++){
            // cout << "dijk:" << dijk << endl;
            Dijkstra(dijk,map[dijk],citySet);
            if(hotel_index[dijk]){
                temp[xptr][xptr]=0;
                for(int i=0;i<n;i++){
                    if(hotel_index[i]){
                        if(map[dijk][i]<=600) temp[xptr][yptr]=1;
                        yptr++;
                    }
                }
                // cout << "test1:" << yptr << endl;
                xptr++;
                yptr=0;
            }
        }
        // cout << "test:" << xptr << endl;
        // for(int x=0;x<n;x++){
        //     for(int y=0;y<n;y++){
        //         if(x==y) continue;
        //         else if(map[x][y]<=600 && (hotel_index[x] && hotel_index[y])) map[x][y]=1;
        //         else map[x][y]=100000000;
        //     }
        // }
        // for(int x=0;x<3;x++){
        //     for(int y=0;y<3;y++){
        //         cout << temp[x][y] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "done\n";
        // if(map[0][n-1]==1){
        //     cout << "1\n";
        //     continue;
        // }
        n=hotel_temp+2;
        // cout << "n:" << n << endl;
        int ans[n];
        for(int i=0;i<n;i++) ans[i]=100000000;
        ans[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> travel;
        bool visited[n]={false};
        travel.push(make_pair(0,0));
        while(!travel.empty()){
            int curr=travel.top().second;
            // cout << curr << endl;
            if(visited[curr]) continue;
            travel.pop();
            visited[curr]=true;
            for(int i=0;i<n;i++){
                // if(temp[curr][i]==100000000 || map[curr][i]==0) continue;
                int tmp_len=ans[curr]+temp[curr][i];
                // cout << "i:" << i << endl;
                // cout << "test:" << tmp_len << endl;
                if(ans[i]>tmp_len){
                    ans[i]=tmp_len;
                    travel.push(make_pair(tmp_len,i));
                }
            }
        }
        (ans[n-1]!=100000000) ? cout << ans[n-1]-1 << endl : cout << "-1\n";
    }
}