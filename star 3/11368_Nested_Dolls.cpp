// 解法:
// *利用greedy method+sort解題:
//     1.先將doll依照h降序排列、h若相同則w升序排列；另建立一ans vector，儲存最終的nested dolls
//     2.依照排列完的dolls依序訪問(h最大的dolls[0]先push進ans)，因為doll採用h降序，因此只需要考慮ans中的w是否大於dolls的w
//         -->尋找ans中大於且最接近dolls[i].w的nested doll(ans[tmp])-->因為dolls採w升序，因此ans中的w是升序排列好的，可用binary search等方式尋找
//         (a) ans中的nested dolls之w皆小於dolls[i].w-->沒有nested doll裝得下dolls[i]
//                 -->將dolls[i] push 進 ans 成為新的nested doll最外層
//         (b) ans[tmp] 裝得下 dolls[i]-->將ans[tmp]之(w,h)更新為dolls[i]之(w,h) (其實更新w就好，因為只要判定w)
//                 -->ans[tmp] 之 w為此nested doll 最小層的w
//     3.ans的size即為最後的nested doll數量
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct doll{
    int h,w;
    doll(){
        h=0;
        w=0;
    }
};

bool cmp(doll d1,doll d2){
    if(d1.h==d2.h) return d1.w<d2.w;
    else return d1.h>d2.h;
}

int main(){
    int cases;
    cin >> cases;
    for(int c=0;c<cases;c++){
        int doll_num;
        cin >> doll_num;
        vector<doll> dolls(doll_num);
        vector<doll> ans;
        for(int in=0;in<doll_num;in++){
            cin >> dolls[in].w >> dolls[in].h;
        }
        sort(dolls.begin(),dolls.end(),cmp);
        // for(int i=0;i<dolls.size();i++){
        //     cout << dolls[i].w << " " << dolls[i].h << endl;
        // }
        ans.push_back(dolls[0]);
        for(int index=1;index<dolls.size();index++){
            int tmp=-1;
            for(int t=0;t<ans.size();t++){
                if(ans[t].w>dolls[index].w){
                    tmp=t;
                    break;
                }
            }
            if(tmp==-1) ans.push_back(dolls[index]);
            else ans[tmp].w=dolls[index].w;
        }
        cout << ans.size() << endl;
    }    
}