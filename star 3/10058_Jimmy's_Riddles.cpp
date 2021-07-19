// 解法:
// *拆解statement:
//     statement=(action),(action),(action)...
//              =(ac_list verb ac_list),(ac_list verb ac_list),(ac_list verb ac_list)...
//              =[(actor and actor...) verb (actor and actor...)],[(actor and actor...) verb (actor and actor...)],[(actor and actor...) verb (actor and actor...)]...
//              -->actor=(noun) or (a noun) or (the noun)
// *實作:利用function一層層分割input,判斷是否合法
// *該學學正則運算式了
//#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

string NOUN[8]={"tom","jerry","goofy","mickey","jimmy","dog","cat","mouse"};
string VERB[8]={"hates","hate","loves","love","knows","know","likes","like"};
string ARTICLE[2]={"a","the"};

bool check_actor(vector<string> actor){
    for(int index=0;index<actor.size();index++){
        if(actor[index].length()==0) continue;
        if(actor[index][0]==' ') actor[index]=actor[index].substr(1);
        // cout << "actor[index]:" << actor[index] << "--" << endl;
        // for(int i=0;i<actor[index].length();i++){
        //     if(actor[index][i]==' ') actor[index].erase(actor[index].begin()+i);
        // }
        // if(actor[index][actor[index].length()-1]==' ') actor[index].erase(actor[index].end()-1);
        // cout << "actor[index]:" << actor[index] << "--" << endl;
        if(actor[index][0]=='a' && actor[index][1]==' '){
            actor[index]=actor[index].substr(1);
        }
        else if(actor[index].substr(0,3)=="the" && actor[index][3]==' '){
            actor[index]=actor[index].substr(3);
        }
        for(int i=0;i<actor[index].length();i++){
            if(actor[index][i]==' ') actor[index].erase(actor[index].begin()+i);
        }
        if(actor[index][actor[index].length()-1]==' ') actor[index].erase(actor[index].end()-1);
        // cout << "actor[index] after:" << actor[index] << endl;
        size_t test;
        int i;
        for(i=0;i<8;i++){
            test=actor[index].find(NOUN[i]);
            if(test!=string::npos && NOUN[i].compare(actor[index])==0){
                // cout << "in\n";
                break;
            }
            // cout << "test:" << test << endl;
            // if(actor[index][test]!=actor[index][0]) return false;
        }
        if(i==8){
            // cout << "noun error\n";
            return false;
        }
    }
    return true;
}

bool check_alist(vector<string> alist){
    for(int index=0;index<alist.size();index++){
        // cout << "alist[index]:" << alist[index] << endl;
        int i;
        for(i=0;i<alist[index].length();i++){
            if(alist[index][i]!=' ') break;
        }
        if(i==alist[index].length()) return false;
        size_t pre=0,pos=0;
        vector<string> actor;
        pos=alist[index].find("and");
        while(pos!=string::npos){
            string sub_actor=alist[index].substr(0,pos);
            // cout << "sub_actor:" << sub_actor << endl;
            // remove(sub_actor.begin(),sub_actor.end(),' ');
            actor.push_back(sub_actor);
            alist[index]=alist[index].substr(pos+4);
            // cout << "alist[index]_after:"<< alist[index] << endl;
            pos=alist[index].find("and");
        }
        actor.push_back(alist[index]);
        if(!check_actor(actor)) return false;
    }
    return true;
}

bool check_action(vector<string> action){
    for(int index=0;index<action.size();index++){
        // cout << "action[index]:" << action[index] << endl;
        if(action[index].find(",")!=string::npos){
            // cout << "find ,\n";
            return false;
        }
        vector<string> A_list;
        size_t pre=0,pos=0;
        int i;
        for(i=0;i<8;i++){
            pos=action[index].find(VERB[i]);
            if(pos!=string::npos) break;
        }
        // cout << action[index][pos+VERB[i].length()] << endl;
        if(pos==string::npos || action[index][pos+VERB[i].length()]!=' '){
            // cout << "no verb\n";
            return false;
        }
        while(pos!=string::npos){
            string sub_alist=action[index].substr(pre,pos-1);
            string verb=action[index].substr(pos,action[index].find(" ")+1);
            A_list.push_back(sub_alist);
            action[index]=action[index].substr(pos+VERB[i].length()+1);
            pre=pos+VERB[i].length()+1;
            // pos=action[index].find(" ");
            // action[index]=action[index].substr(pos+1);
            // cout << "sub_alist:" << sub_alist << endl;
            // cout << "verb:" << verb << endl;
            // cout << "action[index]:" << action[index] << endl;
            for(i=0;i<8;i++) pos=action[index].find(VERB[i]);
        }
        A_list.push_back(action[index]);
        if(!check_alist(A_list)) return false;
    }
    return true;
}

bool check_statement(string input){
    vector<string> action;
    size_t pre=0,pos=0;
    pos=input.find(",");
    while(pos!=string::npos){
        string sub_action=input.substr(0,pos);
        // cout << "sub_action:" << sub_action << endl;
        if(sub_action.find(",")!=string::npos){
            // cout << "find ,\n";
            return false;
        }
        // remove(sub_action.begin(),sub_action.end(),' ');
        action.push_back(sub_action);
        input=input.substr(pos+1);
        pos=input.find(",");
    }
    action.push_back(input);
    return check_action(action);
}

int main(){
    string input;
    while(getline(cin,input)){
        if(check_statement(input)) cout << "YES I WILL\n";
        else cout << "NO I WON'T\n";
    }
}