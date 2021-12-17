#include<bits/stdc++.h>
using namespace std;

/*
    ****Method****
1.  In this code first we make a vector of same length as that of array.
2.  At each index in vector we store the length of the subsequence -->
    which is Longest, Increasing Subsequence and it is ended by the element arr[index].
3.  Reason to perform 2. operation is the comparison which is made at line no. 20.

*/
int long_subsequence(int arr[], int n){
    vector <int> v;
    v.push_back(1);

    for(int i=1;i<n;i++){
        int m = i-1;
        int max = 0;

        while(m>=0){
            if(arr[i]>=arr[m]){
                if(max < v[m]){
                    max = v[m];
                }
            }
            m--;
        }
        v.push_back(max+1);
    }

    int max = INT_MIN;
    for(auto itr:v){
        if(max<itr){
            max = itr;
        }
    }
    return max;
}

int main()
{
    int arr[] = {10,22,9,33,21,50,41,60,80,1};
    int n = 10;

    int num = long_subsequence(arr, n);
    cout<<"Length of longest increasing subsequence is:"<<num<<endl;
    return 0;
}