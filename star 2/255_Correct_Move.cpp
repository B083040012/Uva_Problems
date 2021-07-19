// 解法:
// 輸入三個座標(king,be_qu,af_qu)
// 1.判定Illegal state:起始相同位置king==be_qu
// 2.判定Illegal move:
//     (1)queen 移動方向是否合理
//     (2)king 是否位於queen移動路徑上
//         *queen 橫向移動:(be_qu-king)*(af_qu-king)>0
//         *queen 縱向移動:!((be_qu-king)%8==0 && ((be_qu-king)*(af_qu-king)<=0))
//     (3)af_queen是否和king重疊:af_qu-king==0
// 3.判定Move not allowed:將king可走座標存入king_path，並用for迴圈檢查各點是否等於af_qu
// 4.判定stop/continue:stop的情形皆為特殊解，條列出即可，剩餘的解為continue

//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int king,be_qu,af_qu;
    while(cin >> king >> be_qu >> af_qu){
        int king_path[5]={king-8,king-1,king+1,king+8,king};
        if(king%8==0) king_path[1]=-1;
        else if((king+1)%8==0) king_path[2]=-1;
        int hori_qu=8*(be_qu/8);
        int qu_dir;
        if((af_qu>=hori_qu && af_qu<=hori_qu+7) && ((be_qu-king)*(af_qu-king)>0)) qu_dir=1;
        else if(((af_qu-be_qu)%8==0) && !((be_qu-king)%8==0 && ((be_qu-king)*(af_qu-king)<=0))) qu_dir=1;
        else qu_dir=0;
        if(king==be_qu) cout << "Illegal state\n";
        else if(!qu_dir || be_qu==af_qu) cout << "Illegal move\n";
        else{
            int i;
            for(i=0;i<5;i++){
                if(af_qu==king_path[i]){
                    cout << "Move not allowed\n";
                    break;
                }
            }
            if(i<5) continue;
            if((king==0 && af_qu==9) || (king==7 && af_qu==14) || (king==56 && af_qu==49) || (king==63 && af_qu==54)){
                cout << "Stop\n";
            }
            else cout << "Continue\n";
        }
    }    
}