// 解法:
// 邊輸入邊建立binary tree,若暫無賦予值則將node的value留空，並注意是否有重複賦值情況，
// 接著用迭代找出level order(此處要注意不可使用recursive)，把child存入queue(因為要照訪問順序輸出)，
// 並將值讀入vector，若vector裡有負值，則"not complete"，沒有負值則照順序輸出
// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
    int num;
    struct node *rch,*lch;
    node(int input,node*r,node*l):num(input),rch(r),lch(l){};
};

vector<int> order(struct node *root){
    struct node *current=root;
    queue<node*> tree;
    vector<int> ans;
    while(current){
        ans.push_back(current->num);
        if(current->lch) tree.push(current->lch);
        if(current->rch) tree.push(current->rch);
        if(tree.size()==0) return ans;
        current=tree.front();
        tree.pop();
    }
    return ans;
}

int main(){
    struct node *root=new struct node(-1,NULL,NULL); 
    string input;
    vector<int> ans;
    bool flag=true;
    while(cin >> input){
        if(input=="()"){
            // cout << "check:" << root->lch->num << " " << root->rch->num << endl;
            ans=order(root);
            if(find(ans.begin(),ans.end(),-1)!=ans.end() || !flag) cout << "not complete";
            else{
                for(int i=0;i<ans.size()-1;i++) cout << ans[i] << " ";
                cout << ans[ans.size()-1];
            }
            cout << endl;
            ans.clear();
            delete root;
            root=new struct node(-1,NULL,NULL);
            flag=true;
        }
        else{
            int temp=atoi(input.substr(input.find('(')+1,input.find(',')-input.find('(')).c_str());
            string child=input.substr(input.find(',')+1,input.find(')')-input.find(',')-1);
            struct node *current=root;
            if(child.length()>0){
                for(int i=0;i<child.length();i++){
                    if(child[i]=='L'){
                        if(!current->lch) current->lch=new struct node(-1,NULL,NULL);
                        current=current->lch;
                    }
                    else if(child[i]=='R'){
                        if(!current->rch) current->rch=new struct node(-1,NULL,NULL);
                        current=current->rch;
                    }
                }
            }
            if(current->num>0) flag=false;
            current->num=temp;
        }
    }

}