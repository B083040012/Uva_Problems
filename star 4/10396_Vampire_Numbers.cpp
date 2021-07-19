// 解法:
// *本題使用暴力解，針對每一個fang候選人，進行相乘是否為vampire number的判斷:
//     (1) 兩fang候選人不得皆為10的倍數
//     (2) 兩fang候選人不得皆為奇數
//     (3) 建一check表，判斷各個位數的出現頻率，判斷vam_can是否為vampire number
// 利用set<int> 紀錄input為4,6,8時的答案，再照input輸出答案
//#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;

void cal(int c,set<int> *ans){
    int ans_index=c/2-2;
    int fang_deg=c/2;
    for(int fangx=pow(10,fang_deg-1);fangx<pow(10,fang_deg);fangx++){
        for(int fangy=fangx;fangy<pow(10,fang_deg);fangy++){
            if((!(fangx%10) && !(fangy%10)) || ((fangx%2) && (fangy%2))) continue;
            int fang1=fangx,fang2=fangy,vam_can=fang1*fang2;
            // if(fang1==21 && fang2==60){
            //     cout << "in\n";
            // }
            // cout << "fang1:" << fang1 << " fang2:" << fang2 << endl;
            int check[10];
            for(int ini=0;ini<10;ini++) check[ini]=0;
            while(fang1) check[fang1%10]+=1,fang1/=10;
            while(fang2) check[fang2%10]+=1,fang2/=10;
            while(vam_can) check[vam_can%10]-=1,vam_can/=10;
            // if(fangx==18 && fangy==80){
            //     cout << "in\ncheck:\n";
            //     for(int i=0;i<10;i++) cout << i << ":" << check[i] << endl;
            // }
            int c;
            for(c=0;c<10;c++){
                if(check[c]!=0) break;
            }
            if(c==10){
                // cout << "hit:" << fangx*fangy << endl;
                // cout << "fang:" << fangx << " " << fangy << endl;
                ans[ans_index].insert(fangx*fangy);
            }
        }
    }
}

int main(){
    set<int> ans[3];
    for(int c=4;c<=8;c+=2) cal(c,ans);
    // cout << "cal done\n";
    int input;
    while(cin >> input){
        input=(input/2)-2;
        for(auto ptr=ans[input].begin();ptr!=ans[input].end();ptr++){
            cout << *(ptr) << endl;
        }
        cout << endl;
    }
}