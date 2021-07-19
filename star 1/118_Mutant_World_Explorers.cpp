//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int length,high,ini_x,ini_y;
    char ini_dir,dir_all[4];
    dir_all[0]='N';
    dir_all[1]='E';
    dir_all[2]='S';
    dir_all[3]='W';
    vector <int> lost_x;
    vector <int> lost_y;
    cin >> length >> high;
    while(cin >> ini_x >> ini_y >> ini_dir){
        int dir_index,lost=0;
        for(int i=0;i<4;i++) if(ini_dir==dir_all[i]) dir_index=i;
        string move;
        cin >> move;
        for(int i=0;i<move.length();i++){
            if(move[i]=='R'){
                dir_index++;
                if(dir_index>3) dir_index=0;
            } //if(dir_index++>3) dir_index=0;
            else if(move[i]=='L'){
                dir_index--;
                if(dir_index<0) dir_index=3;
            } //if(dir_index--<0) dir_index=3;
            else if(move[i]=='F'){
                int curr_x=ini_x,curr_y=ini_y,stop=0;
                if(dir_index==0) ini_y++;
                else if(dir_index==1) ini_x++;
                else if(dir_index==2) ini_y--;
                else ini_x--;
                if((ini_x>length) || (ini_y>high) || (ini_x*ini_y<0)){
                    for(int k=0;k<lost_x.size();k++){
                        if((curr_x==lost_x[k]) && (curr_y==lost_y[k])){
                            stop=1;
                            ini_x=curr_x;
                            ini_y=curr_y;
                            break;
                        }
                    }
                    if(stop==0){
                        cout << curr_x << " " << curr_y << " " << dir_all[dir_index] << " LOST\n";
                        lost_x.push_back(curr_x);
                        lost_y.push_back(curr_y);
                        lost=1;
                        break;
                    }
                }
            }
        }
        if(!lost) cout << ini_x << " " << ini_y << " " << dir_all[dir_index] << endl;
    }
}