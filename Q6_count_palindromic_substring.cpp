#include<bits/stdc++.h>
using namespace std;

int find_substr(string str){
    bool dp[str.length()][str.length()];

    for(int i=0;i<str.length();i++){
        for(int j=0;j<str.length();j++){
            if(i>j){
                dp[i][j] = 0;
            }
            else if(i == j){
                dp[i][j] = 1;
            }
        }
    }

    for(int i=str.length()-1;i>=0;i--){
        for(int j = str.length()-1;j>=i+1;j--){
            if((i+1) == j){
                if(str[i] == str[j]){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
            else{
                if(str[i] == str[j]){
                    if(dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
    }

    int count = 0;
    for(int i=0;i<str.length();i++){
        for(int j=i;j<str.length();j++){
            if(dp[i][j] == 1){
                count++;
            }
        }
    }
    return count;
}

int main()
{
    string str = "aaaabbaa";
    int num = find_substr(str);
    cout<<num;
    return 0;
}