// 解法:
// 1. 建立table(輸入用)、sub_tree(查看子樹用)、tun_list(每條tunnel的起終點和person數)
// 2. sub_tree預設為每個city獨立，各自為一個子樹；依照table建立tun_list(看upper_tri即可)
// 3. sort tun_list(len->s->e)
// 4. 從最小person樹的tun開始連，出現ring跳過，得出答案
// *本題用kruskal算法找出最小樹(https://zh.wikipedia.org/zh-tw/%E5%85%8B%E9%B2%81%E6%96%AF%E5%85%8B%E5%B0%94%E6%BC%94%E7%AE%97%E6%B3%95)
// *需特別注意int、char轉string的方法。
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct tun{
    int len,s,e;
    tun(int len,int s,int e):len(len),s(s),e(e){};
};

bool my_sort(struct tun t1,struct tun t2){
    if(t1.len==t2.len && t1.s==t2.s) return (t1.e<t2.e);
    if(t1.len==t2.len) return (t1.s<t2.s);
    return (t1.len<t2.len);
}

int main(){
    int cases;
    while(cin >> cases){
        for(int i=0;i<cases;i++){
            int city;
            cin >> city;
            vector<string> sub_tree;
            vector<tun> tun_list;
            int table[city][city];
            // vector<int> tun_len; 
            for(int j=0;j<city;j++){
                char ch=char('A'+j);
                string temp(1,ch);
                sub_tree.push_back(temp);
            }
            // for(int j=0;j<city;j++) cout << sub_tree[j] << endl;
            for(int row=0;row<city;row++){
                for(int col=0;col<city-1;col++){
                    char trash;
                    cin >> table[row][col] >> trash;
                    // cout << table[row][col] << endl;
                }
                cin >> table[row][city-1];
            }
            for(int row=0;row<city;row++){
                for(int col=row+1;col<city;col++){
                    if(table[row][col]){
                        struct tun temp(table[row][col],row,col);
                        tun_list.push_back(temp);
                    }
                }
            }
            sort(tun_list.begin(),tun_list.end(),my_sort);
            // for(int j=0;j<tun_list.size();j++) cout << tun_list[j].len << endl;
            cout << "Case " << i+1 << ":\n";
            for(int k=0;k<tun_list.size() /*|| sub_tree.size()==1*/;k++){
                char s_city=char('A'+int(tun_list[k].s)),e_city=char('A'+int(tun_list[k].e));
                size_t s_point=-1,e_point=-1;
                for(int ch=0;ch<sub_tree.size()/* || (s_point>0 && e_point>0)*/;ch++){
                    if(sub_tree[ch].find(s_city)!=string::npos) s_point=ch;
                    if(sub_tree[ch].find(e_city)!=string::npos) e_point=ch;
                }
                if(s_point==e_point) continue;
                else{
                    cout << s_city << "-" << e_city << " " << tun_list[k].len << endl;
                    sub_tree[s_point]+=sub_tree[e_point];
                    sub_tree.erase(sub_tree.begin()+e_point);
                }
            }
        }
    }    
}