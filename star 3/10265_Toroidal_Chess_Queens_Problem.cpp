//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> ans;

int **board=new int *[m];
for(int x=0;x<m;x++){
    board[x]=new int[n];
    for(int y=0;y<n;y++) board[x][y]=0;
}

bool check(int m ,int n){
    if(m<n) return check(n,m);
    if((m%n==0) || ((n%(m%n)==0) && m%n!=1)) return true;
    else return false;
}

void block(int **board,int x,int y,int m,int n){
    int tempx=(x+1)%m,tempy=(y+1)%n;
    while(tempx!=x){
        board[tempx][y]+=1;
        tempx=(tempx+1)%m;
    }
    // cout << "done\n";
    while(tempy!=y){
        board[x][tempy]+=1;
        tempy=(tempy+1)%n;
    }
    // cout << "done\n";
    tempx=(x+1)%m;
    tempy=(y+1)%n;
    while(!(tempx==x && tempy==y)){
        board[tempx][tempy]+=1;
        tempx=(tempx+1)%m;
        tempy=(tempy+1)%n;
        // cout << tempx << ' ' << tempy << endl;
    }
    // cout << "done\n";
    tempx=(x+1)%m;
    tempy=(y-1)%n;
    if(tempy==-1) tempy=n-1;
    // cout << tempx << ' ' << tempy << endl;
    while(!(tempx==x && tempy==y)){
        board[tempx][tempy]+=1;
        tempx=(tempx+1)%m;
        tempy=(tempy-1)%n;
        if(tempy==-1) tempy=n-1;
        // cout << tempx << ' ' << tempy << endl;
    }
    // cout << "done\n";
    return;
}

void cleanboard(int **board,int x,int y,int m,int n){
    int tempx=(x+1)%m,tempy=(y+1)%n;
    while(tempx!=x){
        board[tempx][y]-=1;
        tempx=(tempx+1)%m;
    }
    while(tempy!=y){
        board[x][tempy]-=1;
        tempy=(tempy+1)%n;
    }
    tempx=(x+1)%m;
    tempy=(y+1)%n;
    while(!(tempx==x && tempy==y)){
        board[tempx][tempy]-=1;
        tempx=(x+1)%m;
        tempy=(y+1)%n;
    }
    tempx=(x+1)%m;
    tempy=(y-1)%n;
    if(tempy==-1) tempy=n-1;
    while(!(tempx==x && tempy==y)){
        board[tempx][tempy]-=1;
        tempx=(x+1)%m;
        tempy=(y-1)%n;
        if(tempy==-1) tempy=n-1;
    }
}

int backtracking(int **board,int m,int n,int posx,int posy,int k){
    // cout << "in back:" << posx << ' ' << posy << endl;
    if(!k) return 1;
    int x,y;
    for(x=0;x<m;x++){
        for(y=0;y<n;y++){
            if(board[x][y]==0){
                posx=x,posy=y;
                board[x][y]+=1;
                block(board,posx,posy,m,n);
                // cout << "block done\n";
                if(backtracking(board,m,n,posx,posy,k-1)==0){
                    board[posx][posy]-=1;
                    cleanboard(board,posx,posy,m,n);
                }
                else{
                    // cout << posx << ' ' << posy;
                    ans.push_back(posy);
                    ans.push_back(posx);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int m,n,k;
    while(cin >> m >> n >> k){
        cout << "m=" << m << "n=" << n << "k=" << k << endl;
        ans.clear();
        if((m==1 || n==1) && k>1){
            cout << "0 0\n";
            continue;
        }
        else if(k==1){
            cout << "1 1\n";
            continue;
        }
        if(check(m,n)){
            board[0][0]+=1;
            block(board,0,0,m,n);
            // cout << "1 1\n";
            backtracking(board,m,n,0,0,k-1);
            ans.push_back(0);
            ans.push_back(0);
            for(int i=ans.size()-1;i>=0;i--){
                if(i%2==0) cout << ans[i]+1 << endl;
                else cout << ans[i]+1 << ' ';
            }
        }
        else{
            cout << "0 0\n";
        }
    }     
}