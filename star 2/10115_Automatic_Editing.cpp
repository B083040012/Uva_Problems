// 解法:
// 將Find和Replace-by分別存入vector，並利用string的find、erase和insert函式完成替換
// *須注意cin後必須清空緩衝區才能getline
// *getline會讀到前一行的newline，ignore、erase和remove newline皆沒有效果，
//  因此加入input[pointer]!=find[i][0]條件判斷(該newline無法用input[pointer]顯示)
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int rule;
    while(cin >> rule){
        cin.ignore();
        if(!rule) return 0;
        vector<string> find,replace_by;
        string input;
        for(int i=0;i<rule;i++){
            getline(cin,input);
            find.push_back(input);
            getline(cin,input);
            replace_by.push_back(input);
            // cout << find[0] << endl;
        }
        getline(cin,input);
        // cout << input << endl;
        // input.erase(std::remove(input.begin(), input.end(), '\r'), input.end());
        int i=0;
        while(i<rule){
            // cout << "i=" << i << endl;
            // cout << "find:" << find[]
            string check=input;
            size_t pointer=input.find(find[i]);
            // cout << "pointer:" << find[i].length() << endl;
            if(pointer==string::npos){
                i++;
                continue;
            }
            if(input[pointer]!=find[i][0]){
                i++;
                continue;
            }
            // cout << "pointer:" << pointer << endl;
            input.erase(pointer,find[i].length());
            input.insert(pointer,replace_by[i]);
            if(check==input){
                i++;
                // continue;
            }
            // cout << input << endl;
        }
        cout << input << endl;
    }    
}