#include<bits/stdc++.h>
using namespace std;

void minjump(int arr[], int n){
    int *dp = new int [n];
    dp[n-1] = 0;
    for(int i=n-2;i>=0;i--){
        if(arr[i] == 0){ // If arr[i] = 0, means jump cannot be taken.
            dp[i] = -1;
            // continue;
        }
        else{
            int m = i+1;
            int max = INT_MAX;
            int temp = i+arr[i];
            if(temp > n-1){  // Since jump should not exceed the array length.
                temp = n-1;
            }
            while(m <= temp){
                if(max > dp[m] && dp[m] != -1){   // if in comparison at some point dp[m] = -1, 
                    max = dp[m];                  // Jump cannot be taken from that point.
                }
                m++;
            }
            if(max != INT_MAX){
                dp[i] = max+1;
            }
            else{             // If no such point is finded out from where jump can be taken than 
                dp[i] = -1;   // Value for that particular index will also be -1.
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
}

int main()
{
    int arr[] = {3,3,0,2,1,2,4,2,0,0};
    int n = 10;
    minjump(arr, n);
    return 0;
}