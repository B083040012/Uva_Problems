#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

//尋找中位數

double find_midd(int *array,int tol){
    //先進行sort
    for(int i=0;i<tol-1;i++){
        for(int k=i+1;k<tol;k++){
            if(array[i]>array[k]){
                swap(array[i],array[k]);
            }
        }
    }
    //依據size(奇偶數)回傳
    if(tol%2==0) return (array[tol/2-1]+array[tol/2])/2;
    else return array[tol/2];
}

int main(){
    int case_num;
    while(cin >> case_num){
        int rel_num;
        double midd;
        long long dis[case_num]={0};
        for(int i=0;i<case_num;i++){
            cin >> rel_num;
            int street_num[rel_num];
            for(int k=0;k<rel_num;k++){
                cin >> street_num[k];
            }
            midd=find_midd(street_num,rel_num);
            for(int j=0;j<rel_num;j++){
                dis[i]+=abs(midd-street_num[j]);
            }
        }
        for(int i=0;i<case_num;i++){
            cout << dis[i] << endl;
        }
    }
}