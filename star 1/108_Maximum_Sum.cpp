#include<iostream>
#include<vector>
using namespace std;

int main(){
    int size,ans=-100000000;
    cin >> size;
    int array[size][size];
    vector<int> test;
    for(int i=0;i<size;i++){
        for(int k=0;k<size;k++) cin >> array[i][k];
    }
    for(int i=0;i<size;i++){
        test.clear();
        test.resize(size,0);
        for(int k=i;k<size;k++){
            for(int j=0;j<size;j++){
                test[j]+=array[k][j];
            }
            int temp=0;
            for(int m=0;m<size;m++){
                temp+=test[m];
                if(temp>ans) ans=temp;
                if(temp<0) temp=0;
            }
        }
    }
    cout << ans  << endl;
}