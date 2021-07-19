//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int high[10000]={0},L,H,R,start=0;
    while(cin >> L >> H >> R){
        for(int i=L;i<R;i++){
            if(high[i]<H) high[i]=H;
        }
    }
    for(int i=0;i<10000;i++){
        if(high[i]!=0){
            start=i;
            cout << i << " " << high[i];
            break;
        } 
    }
    for(int i=start+1;i<10000;i++){
        if(high[i]==high[i-1]) continue;
        else cout << " " << i << " " << high[i];
    }
    cout << endl;
}