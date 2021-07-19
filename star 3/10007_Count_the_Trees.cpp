// Still thinking about how to deal with large(>long long) Catalan number...
// Come back later,sorry!!

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

vector<vector<int>> count;

int dig_len(int n){
    int c=0;
    while(n>0){
        c++;
        n/=10;
    }
    return c;
}

// vector<int> vec_div(vector<int> v,int d){
//     int dig=dig_len(d),pointer=v.size()-1,remain=0;
//     vector<int> ans;
//     while(pointer>0){

//     }   
// }

void set_count(){
    for(int i=0;i<=300;i++){
        cout << "i:" << i << endl;
        vector<int> curr;
        if(i==0){
            curr.push_back(1);
            count.push_back(curr);
        }
        else{
            int pro=4*(i-1)+2,div=i+1;
            cout << "count[i-1]:";
            for(int j=0;j<count[i-1].size();j++) cout << count[i-1][j];
            cout << endl;
            for(int j=0;j<count[i-1].size();j++) curr.push_back(pro*count[i-1][j]);
            cout << "before curr:";
            for(int j=0;j<curr.size();j++) cout << curr[j];
            cout << endl;
            for(int j=0;j<curr.size();j++){
                if(curr[j]>9){
                    if(j==curr.size()-1){
                        curr.push_back(curr[j]/10);
                        curr[j]%=10;
                    }
                    else{
                        curr[j+1]+=curr[j]/10;
                        curr[j]%=10;
                    }
                }
            }
            for(int j=0;j<curr.size()/2;j++) swap(curr[j],curr[curr.size()-j-1]);
            cout << "after curr:";
            for(int j=0;j<curr.size();j++) cout << curr[j];
            cout << endl;
            // vec_div();
            count.push_back(curr);
        }
    }
}

int main(){
    int n;
    set_count();
}



































// string large_product(string n1,string n2){
//     if(n1.length()<n2.length()) return large_product(n2,n1);
//     char ans[n1.length()+n2.length()];
//     for(int i=0;i<n1.length()+n2.length();i++) ans[i]='0';
//     ans[n1.length()+n2.length()]='\0';
//     // cout << ans << endl;
//     for(int i=0;i<n2.length();i++){
//         int n2_dig=n2[i]-'0';
//         for(int k=0;k<n1.length();k++){
//             int temp=(n2_dig*(n1[k]-'0'));
//             // cout << "temp" << temp << endl;
//             if(temp==10) ans[i+k]=((ans[i+k]-'0')+1)+'0';
//             else{
//                 ans[i+k]=((ans[i+k]-'0')+(temp/10))+'0';
//                 ans[i+k+1]=((ans[i+k+1]-'0')+(temp%10))+'0';
//             }
//         }
//         // cout << "after" << ans << endl;
//     }
//     for(int i=n1.length()+n2.length()-1;i>=0;i--){
//         if((ans[i]-'0')>9){
//             // cout << "i" << i << " " << ans[i] << endl;
//             ans[i-1]=((ans[i]-'0')/10+ans[i-1]-'0')+'0';
//             ans[i]=((ans[i]-'0')%10)+'0';
//         }
//     }
//     if(ans[0]=='0'){
//         for(int i=1;i<n1.length()+n2.length();i++) ans[i-1]=ans[i];
//         ans[n1.length()]='\0';
//     }
//     return ans;
// }

// string large_plus(string n1,string n2){
//     if(n1.length()<n2.length()) return large_plus(n2,n1);
//     char sum[n1.length()+1];
//     sum[n1.length()+1]='\0';
//     string n1r=n1,n2r=n2;
//     for(int i=0;i<n1r.length()/2;i++) swap(n1r[i],n1r[n1r.length()-i-1]);
//     // cout << "n1r:" << n1r << endl;
//     for(int i=0;i<n2r.length()/2;i++) swap(n2r[i],n2r[n2r.length()-i-1]);
//     // cout << "n2r:" << n2r << endl;
//     for(int i=0;i<n1r.length()+1;i++) sum[i]='0';
//     for(int i=0;i<n1r.length();i++){
//         if(i>=n2r.length()) sum[i]=n1r[i];
//         else sum[i]=((n1r[i]-'0')+(n2r[i]-'0'))+'0';
//         // cout << ((n1r[i]-'0')+(n2r[i]-'0')) << endl;
//     }
//     // cout << "sum" << sum << endl;
//     for(int i=0;i<n1.length()+1;i++){
//         if(sum[i]-'0'>9){
//             sum[i+1]=((sum[i]-'0')/10+(sum[i+1]-'0'))+'0';
//             sum[i]=((sum[i]-'0')%10)+'0';
//         }
//     }
//     for(int i=0;i<(n1.length()+1)/2;i++) swap(sum[i],sum[n1.length()-i]);
//     if(sum[0]=='0'){
//         for(int i=1;i<n1.length()+1;i++) sum[i-1]=sum[i];
//         sum[n1.length()]='\0';
//     }
//     return sum;
// }

// // string large_fac(int n){
// //     string fac="1";
// //     for(int i=2;i<=n;i++){
// //         fac=large_product(fac,to_string(i));
// //         // cout << fac << endl;
// //     }
// //     return fac;
// // }

// // long long fac(long long n){
// //     if(n==1) return 1;
// //     return n*fac(n-1);
// // }

// // long long cal_trees(long long n){
// //     if(n<=1) return 1;
// //     long long sum=0;
// //     for(int i=0;i<n;i++) sum+=(cal_trees(i)*cal_trees(n-i-1));
// //     // cout << "sum:" << sum << endl;
// //     // cout << "fac:" << fac(n) << endl;
// //     return sum;
// // }

// int main(){
//     int n;
//     vector<string> count;
//     vector<string> fac;
//     count.push_back("1");
//     count.push_back("1");
//     fac.push_back("1");
//     // cout << large_plus("9999","5675") << endl;
//     // for(int i=1;i<=300;i++){
//     //     fac.push_back(large_product(fac[i-1],to_string(i)));
//     // }
//     // for(int i=2;i<=300;i++){
//     //     // cout << "i:" << i << endl;
//     //     string sum="0";
//     //     // sum=large_product(to_string(((4*(i-1))+2)/((i-1)+2)),count[i-1]);
//     //     for(int k=0;k<i;k++){
//     //         sum=large_plus(sum,large_product(count[k],count[i-k-1]));
//     //     }
//     //     count.push_back(sum);
//     //     // cout << "in" << endl;
//     // }
//     // cout << "done\n";
//     cout << large_product("1000","99") << endl;
//     while(cin >> n){
//         if(!n) return 0;
//         cout << large_product(count[n],fac[n]) << endl;
//         cout << count[n] << " " << fac[n] << endl;
//     }
// }