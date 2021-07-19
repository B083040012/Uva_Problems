// 解法:
// *每一次的溝通都是在刪去具有[唯一name或extention](depend on是第幾次溝通)的file
//     -->第一次溝通是由extention 的client發起
//         -->第奇數次尋找具有唯一name的file並刪去
//            第偶數次尋找具有唯一extention的file並刪去
// *實作:利用struct存file的name、ex以及是否有".",兩個map存name、ex出現的次數,每一次找到具有唯一的file便將map中的次數-1並從fileSet中erase                                
//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

struct file{
    string name,ex;
    bool dot;
    file(string n,string e,bool d){
        name=n,ex=e,dot=d;
    }
};

int main(){
    int cases;
    cin >> cases;
    for(int ca=0;ca<cases;ca++){
        int N,M;
        cin >> N >> M;
        vector<file> fSet;
        map<string,int> nameSet,exSet;
        for(int n=0;n<N;n++){
            string input,name,ex;
            cin >> input;
            size_t ptr=input.find(".");
            // cout << "input:" << input << endl;
            // cout << "done\n";
            if(ptr==string::npos){
                // cout << "here1\n";
                nameSet[input]+=1;
                exSet["\0"]+=1;
                file tmp(input,"\0",false);
                fSet.push_back(tmp);
            }
            else{
                // cout << "here2\n";
                nameSet[input.substr(0,ptr)]+=1;
                exSet[input.substr(ptr+1)]+=1;
                file tmp(input.substr(0,ptr),input.substr(ptr+1),true);
                fSet.push_back(tmp);
            }
            // cout << fSet[n].name << " " << fSet[n].ex << endl;
            // if(n==1) cout << (fSet[n].ex==fSet[n-1].ex) << endl;
        }
        // cout << "nameSet:\n";
        // for(auto& ptr:nameSet){
        //     cout << ptr.first << " " << ptr.second << endl;
        // }
        // cout << "exSet:\n";
        // for(auto& ptr:exSet){
        //     cout << ptr.first << " " << ptr.second << endl;
        // }
        for(int m=0;m<M;m++){
            if(m%2){
                for(int index=0;index<fSet.size();index++){
                    string tmp_ex,tmp_name;
                    tmp_ex=fSet[index].ex;
                    tmp_name=fSet[index].name;
                    if(nameSet[tmp_name]==1){
                        nameSet[tmp_name]--;
                        exSet[tmp_ex]--;
                        // cout << "erase:" << tmp_name << " " << tmp_ex << endl;
                        fSet.erase(fSet.begin()+index);
                        index--;
                    }
                    else if(nameSet[tmp_name]>1){
                        continue;
                    }
                }
            }
            else{
                // cout << "in\n";
                for(int index=0;index<fSet.size();index++){
                    string tmp_ex,tmp_name;
                    tmp_ex=fSet[index].ex;
                    tmp_name=fSet[index].name;
                    // cout << "test:" << tmp_name << " " << tmp_ex << endl;
                    if(exSet[tmp_ex]==1){
                        // cout << "\n\n\nhit\n\n";
                        nameSet[tmp_name]--;
                        exSet[tmp_ex]--;
                        // cout << "erase:" << tmp_name << " " << tmp_ex << endl;
                        fSet.erase(fSet.begin()+index);
                        index--;
                    }
                    else if(exSet[tmp_ex]>1){
                        continue;
                    }
                }
            }
        }
        // cout << "erase done\n";
        cout << fSet.size() << endl;
        for(auto& ptr:fSet){
            if(ptr.dot) cout << ptr.name << "." << ptr.ex << endl;
            else cout << ptr.name << endl;
        }
        if(ca<cases-1) cout << endl;
    }
}