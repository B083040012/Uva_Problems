#include<iostream>
using namespace std;

int algorithm(int n){
    if(n==1) return 1;
    else{
        int count=1;
        if(n%2) return count+=algorithm(3*n+1);
        else return count+=algorithm(n/2);
    }
}

int main(){
    int i,j,max=0,temp;
    while(cin >> i >> j){
        int i_ch=i;
        int j_ch=j;
        if(i>j) swap(i_ch,j_ch);
        max=0;
        for(int k=i_ch;k<=j_ch;k++){
            temp=algorithm(k);
            max=(max<temp)?temp:max;
        }
        cout << i << " " << j << " " << max << endl;
    }
}