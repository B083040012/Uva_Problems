//!!!!!!!!!!! Must Review !!!!!!!!!!!!!!!!
// 1.判別雙位數以上string-->int
// 2.擷取string
// 3.判別非string、int之文字


//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string input;
    vector <string> str_stack;
    while(getline(cin ,input)){
        if(input=="0") return 0;
        int pre_ptr=0,re_ptr=0;
        while(pre_ptr<input.length()){
            // cout << pre_ptr << endl;
            if(input[pre_ptr]>='1' && input[pre_ptr]<='9'){
                re_ptr=pre_ptr;
                while(input[re_ptr]>='0' && input[re_ptr]<='9'){
                    re_ptr++;
                }
                if(re_ptr==input.length()) re_ptr++;
                int index=atoi(input.substr(pre_ptr,(re_ptr-pre_ptr)).c_str());
                string contain=str_stack[index-1];
                cout << contain;
                // cout << "in" << endl;
                // cout << "\n\nerase:" << str_stack[index-1] << "\n\n";
                str_stack.erase(str_stack.begin()+index-1);
                str_stack.insert(str_stack.begin(),contain);
                pre_ptr=re_ptr;
            }
            else if((input[pre_ptr]>='a' && input[pre_ptr]<='z') || (input[pre_ptr]>='A' && input[pre_ptr]<='Z')){
            // while((input[pre_ptr]>='a' || input[pre_ptr]<='z') && (input[pre_ptr]>='A' || input[pre_ptr]<='Z')){
                re_ptr=pre_ptr;
                while((input[re_ptr]>='a' && input[re_ptr]<='z') || (input[re_ptr]>='A' && input[re_ptr]<='Z')){
                    // cout << re_ptr << endl;
                    re_ptr++;
                }
                if(re_ptr==input.length()) re_ptr++;
                string temp=input.substr(pre_ptr,(re_ptr-pre_ptr));
                // cout << temp << endl;
                vector <string>::iterator sig=find(str_stack.begin(),str_stack.end(),temp);
                str_stack.insert(str_stack.begin(),temp);
                // if(sig==str_stack.end()){
                //     // cout << "add" << endl;
                //     str_stack.insert(str_stack.begin(),temp);
                // }
                // else{
                //     // cout << "not found" << endl;
                //     str_stack.erase(sig,sig);
                //     str_stack.insert(str_stack.begin(),temp);
                // }
                cout << temp;
                pre_ptr=re_ptr;
                // cout << pre_ptr << endl;
                if(pre_ptr>input.length()-1) break;
            }
            else{
                // cout << "in" << endl;
                cout << input[pre_ptr];
                pre_ptr++;
            }
            for(int i=0;i<str_stack.size();i++){
                cout << "\nstack[" << i << "] :" << str_stack[i] << "\n\n";
            }
        }
        cout << endl;
    }
}