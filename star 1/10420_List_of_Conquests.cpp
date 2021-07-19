//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int c;
    while(cin >> c){
        vector <string> name_of_con;
        for(int i=0;i<c;i++){
            string input_con,input_name;
            cin >> input_con;
            input_con.erase(0,input_con.find_first_not_of(" "));
            getline(cin,input_name);
            name_of_con.push_back(input_con);
            sort(name_of_con.begin(),name_of_con.end());
        }
        int count=1;
        for(int i=0;i<name_of_con.size();i++){
            if(name_of_con[i]==name_of_con[i+1]){
                if(i==name_of_con.size()-2){
                    cout << name_of_con[i] << " " << ++count << endl;
                    break;
                } 
                count++;
            }
            else{
                if(i==name_of_con.size()-1) count=1;
                cout << name_of_con[i] << " " << count << endl;
                count=1;
            }
        }
    }
}