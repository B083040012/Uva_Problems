// 解法:
// 1.建立兩陣列分別存放兩地圖的城鎮，並檢查圖1的城鎮是否都有出現在圖2
// 2.建立map將城鎮編號，圖2才出現的城鎮放在最後，以便後續運算
// 3.建立三個二維陣列map1、map2、map2New
//     map1將圖1有道路連結的城鎮index標記(1為通路，0為不通)
//     map2將圖2有道路連結的城鎮index標記
//     map2New僅將圖2中包含新城鎮的道路連結標記
//     *三個陣列中，每個城鎮到自身也需編號為1
// 4.map2=map2*[map2New^(新城鎮數量)]，利用新的map2即可看出舊城鎮之間是否仍為通路
// 5.利用map1和新的map2比對(map1為通路者新map2也必須為通路)，即可得出答案
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
// #include<set>
using namespace std;

int **matrixMul(int **map2,int **map2New,int size){
    int **result=new int *[size];
    for(int i=0;i<size;i++){
        result[i]=new int[size];
    }
    for(int row=0;row<size;row++){
        for(int col=0;col<size;col++){
            int sum=0;
            for(int mul=0;mul<size;mul++){
                sum+=map2[row][mul]*map2New[mul][col];
            }
            result[row][col]=sum;
        }
    }
    return result;
}

int main(){
    string id1,id2;
    while(cin >> id1){
        if(id1=="END") return 0;
        vector<string> city1,city2;
        vector<pair<string,string>> road1,road2;
        string input;
        cin.ignore();
        while(getline(cin,input)){
            if(input=="* * *") break;
            string c1,c2;
            c1=input.substr(0,input.find(" "));
            c2=input.substr(input.find(" ")+1);
            if(find(city1.begin(),city1.end(),c1)==city1.end()){
                city1.push_back(c1);
            }
            if(find(city1.begin(),city1.end(),c2)==city1.end()){
                city1.push_back(c2);
            }
            road1.push_back(make_pair(c1,c2));
        }
        cin >> id2;
        cin.ignore();
        while(getline(cin,input)){
            if(input=="* * *") break;
            string c1,c2;
            c1=input.substr(0,input.find(" "));
            c2=input.substr(input.find(" ")+1);
            if(find(city2.begin(),city2.end(),c1)==city2.end()){
                city2.push_back(c1);
            }
            if(find(city2.begin(),city2.end(),c2)==city2.end()){
                city2.push_back(c2);
            }
            road2.push_back(make_pair(c1,c2));
        }
        // for(int i=0;i<city1.size();i++){
        //     cout << city1[i] << endl;
        // }
        // cout << "\n\n";
        // for(int i=0;i<city2.size();i++){
        //     cout << city2[i] << endl;
        // }
        // for(int i=0;i<road2.size();i++){
        //     cout << road2[i].first << " " << road2[i].second << endl;
        // }
        bool flag=false;
        map<string,int> cityNum;
        for(int city1_i=0;city1_i<city1.size();city1_i++){
            string tmp=city1[city1_i];
            int city2_i;
            for(city2_i=0;city2_i<city2.size();city2_i++){
                if(city2[city2_i]==tmp){
                    iter_swap(city2.begin()+city2_i,city2.begin()+city1_i);
                    cityNum[tmp]=city1_i;
                    break;
                }
            }
            if(city2_i==city2.size()){
                flag=true;
                // cout << "not hit:" << tmp << endl;
            }
        }
        if(flag){
            cout << "NO: " << id2 << " is not a more detailed version of " << id1 << endl;
            continue;
        }
        for(int city2_i=city1.size();city2_i<city2.size();city2_i++){
            cityNum[city2[city2_i]]=city2_i;
        }
        // for(int i=0;i<city2.size();i++){
        //     cout << city2[i] << endl;
        // }
        // for(auto ptr=cityNum.begin();ptr!=cityNum.end();ptr++){
        //     cout << ptr->first << " " << ptr->second << endl;
        // }
        int **map1=new int *[city1.size()];
        int **map2=new int *[city2.size()];
        int **map2New=new int *[city2.size()];
        for(int i=0;i<city1.size();i++){
            map1[i]=new int[city1.size()];
            for(int j=0;j<city1.size();j++){
                if(i==j) map1[i][j]=1;
                else map1[i][j]=0;
            }
        }
        for(int i=0;i<city2.size();i++){
            map2[i]=new int[city2.size()];
            map2New[i]=new int[city2.size()];
            for(int j=0;j<city2.size();j++){
                if(i==j){
                    map2[i][j]=map2New[i][j]=1;
                }
                else{
                    map2[i][j]=map2New[i][j]=0;
                }
            }
        }
        for(int r=0;r<road1.size();r++){
            string c1=road1[r].first,c2=road1[r].second;
            map1[cityNum[c1]][cityNum[c2]]=map1[cityNum[c2]][cityNum[c1]]=1;
        }
        for(int r=0;r<road2.size();r++){
            string c1=road2[r].first,c2=road2[r].second;
            int n1=cityNum[c1],n2=cityNum[c2];
            map2[n1][n2]=map2[n2][n1]=1;
            if(n1>=city1.size() || n2>=city1.size()){
                map2New[n1][n2]=map2New[n2][n1]=1;
            }
        }
        // cout << "\n\nmap1\n";
        // for(int i=0;i<city1.size();i++){
        //     for(int j=0;j<city1.size();j++){
        //         cout << map1[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "\n\nmap2:\n";
        // for(int i=0;i<city2.size();i++){
        //     for(int j=0;j<city2.size();j++){
        //         cout << map2[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "\n\nmap2New:\n";
        // for(int i=0;i<city2.size();i++){
        //     for(int j=0;j<city2.size();j++){
        //         cout << map2New[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int mul=0;mul<(city2.size()-city1.size());mul++){
            map2=matrixMul(map2,map2New,city2.size());
        }
        // cout << "\n\nresult:\n";
        // for(int i=0;i<city2.size();i++){
        //     for(int j=0;j<city2.size();j++){
        //         cout << map2[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int x=0;x<city1.size();x++){
            for(int y=0;y<city1.size();y++){
                if(map1[x][y]==1 && map2[x][y]==0){
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag){
            cout << "NO: " << id2 << " is not a more detailed version of " << id1 << endl;
        }
        else{
            cout << "YES: " << id2 << " is a more detailed version of " << id1 << endl;
        }
    }
}