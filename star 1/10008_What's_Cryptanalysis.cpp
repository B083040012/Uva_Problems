#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int c;
    while(cin >> c){
        vector <char> sen;
        cin.ignore();
        for(int i=0;i<c;i++){
            string input,temp;
            getline(cin,input);
            transform(input.begin(),input.end(),back_inserter(temp),::tolower);
            for(int k=0;k<temp.length();k++){
                if(temp[k]>='a' && temp[k]<='z') sen.push_back(temp[k]);
            }
        }
        sort(sen.begin(),sen.end());
        vector <int> num_of_letter(26,0);
        for(int i=0;i<sen.size();i++) num_of_letter[sen[i]-97]++;
        while(1){
            int max_index=distance(num_of_letter.begin(),(max_element(num_of_letter.begin(),num_of_letter.end())));
            if(num_of_letter[max_index]==0) break;
            cout << (char)(max_index+65) << " " << num_of_letter[max_index] << endl;
            num_of_letter[max_index]=0;
        }
        sen.erase(sen.begin(),sen.end());
        num_of_letter.clear();
    }    
}