// 解法:
// *利用dp演算法計算，dp[i][j]代表從第i個字到第j個字若要形成回文所需要的最小cost
// *實作:
//     dp[i][j]預設皆為0
//     for sub_len=1~(word_len-1):
//         for start=0~(word_len-1):
//             end=start+sub_len
//             (a) 若word[start]==word[end]，dp[start][end]的cost和dp[start+1][end-1]一樣
//                                           -->dp[start][end]=dp[start+1][end-1]
//             (b) 若word[start]!=word[end]，dp[start][end]可能為
//                 (1) 將第start個字remove or 將和第start一樣的字add到end+1的位置-->=dp[start+1][end]+1
//                 (2) 將第end個字remove or 將和第end一樣的字add到start-1的位置-->=dp[start][end-1]+1
//                 (3) 將第start/end個字replace成第end/start個字-->=dp[start+1][end-1]+1
//                 -->從(1)、(2)、(3)中取出最小值
//     dp[0][word_len-1]即為答案
//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int cases;
    cin >> cases;
    cin.ignore();
    for(int c=0;c<cases;c++){
        string input;
        cin >> input;
        int **dp=new int*[input.length()+5];
        for(int i=0;i<input.length();i++){
            dp[i]=new int[input.length()+5];
            for(int j=0;j<input.length();j++){
                dp[i][j]=0;
            }
        }
        // int dp[input.length()+5][input.length()+5];
        // cout << "here\n";
        for(int i=0;i<input.length();i++){
            for(int j=0;j<input.length();j++){
                dp[i][j]=0;
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        // cout << "todo\n";
        for(int len=1;len<input.length();len++){
            for(int start=0;start<input.length()-1;start++){
                int end=start+len;
                // cout << start << " " << end << endl;
                if(end>=input.length()) break;
                if(input[start]==input[end]){
                    dp[start][end]=dp[start+1][end-1];
                }
                else{
                    dp[start][end]=min(dp[start+1][end],dp[start][end-1]);
                    dp[start][end]=min(dp[start][end],dp[start+1][end-1])+1;
                }
            }
            // cout << "\n\n...\n\n";
            // for(int i=0;i<input.length();i++){
            //     for(int j=0;j<input.length();j++){
            //         cout << dp[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }
        // cout << "done\n";
        // cout << "\n\nafter...\n\n";
        // for(int i=0;i<input.length();i++){
        //     for(int j=0;j<input.length();j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << "Case " << c+1 << ": " << dp[0][input.length()-1];
        if(c<cases) cout << endl;
    }
}