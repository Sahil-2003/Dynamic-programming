#include<bits/stdc++.h>
using namespace std;

// Similar like previous problem.

int max_sum_inc_sunseque(int arr[], int n){
    vector <int> v;
    v.push_back(arr[0]);

    for(int i=1;i<n;i++){
        int m = i-1;
        int sum = 0;
        while(m>=0){
            if(arr[i] > arr[m]){
                if(sum < v[m]){
                    sum = v[m];
                }
            }
            m--;
        }
        v.push_back(sum+arr[i]);
    }
    int max = INT_MIN;
    for(auto itr:v){
        if(max < itr){
            max = itr;
        }
    }
    return max;
}

int main()
{
    int arr[] = {10,22,9,33,21,50,41,60,80,1};
    int n = 10;

    int num = max_sum_inc_sunseque(arr, n);
    cout<<"Length of longest increasing subsequence is:"<<num<<endl;
    return 0;
}