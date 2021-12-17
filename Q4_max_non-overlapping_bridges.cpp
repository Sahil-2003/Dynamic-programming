/*
--> Maximum Number of non-overlapping Bridges
1.  First we sort the north co-ord of the bridge array,
    Because for no-overlapping bridges -> condition is:-> 
    if(arr[1].n > arr[2].n) then (arr[1].s > arr[2].s)

2.  Hence we sort the north co-ord of Bridge array with the help of sort and mycompare function
3.  Then we fin LIS(Longest Increasing Subsequence) for south co-ord of the Bridge array.
4.  Max one is the answer.
*/

#include<bits/stdc++.h>
using namespace std;

class Bridge{
    public:
        int n;
        int s;
        Bridge(){}
        Bridge(int n, int s){
            this->n = n;
            this->s = s;
        }

        friend ostream & operator << (ostream &o, Bridge &b);
};

// Function to compare on basis of south co-ord if north -cord are equal
int mycompare(Bridge o1, Bridge o2){
    if(o1.n == o2.n){
        return o1.s < o2.s; 
    }
    return o1.n < o2.n;
}

int max_nonoverlapping_bridge(vector <Bridge> arr, int n){
    int *dp = new int[n];
    dp[0] = 1;

    for(int i=1;i<n;i++){
        int m = i-1;
        int max = 0;
        while(m>=0){
            if(arr[i].s >= arr[m].s){
                if(max < dp[m]){
                    max = dp[m];
                }
            }
            m--;
        }
        dp[i] = max+1;
    }

    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(max < dp[i]){
            max = dp[i];
        }
    }
    return max;
}

// Friend ostream operator for user-defined objects.
ostream & operator << (ostream & o, Bridge &b){
    o<<b.n<<" "<<b.s;
    return o;
}

int main(){
    int n;
    cin>>n;

    Bridge *bdg = new Bridge[n];

    int north, south;
    for(int i=0;i<n;i++){
        cout<<"Enter north and south co-ordinates:";
        cin>>north>>south;
        bdg[i] = Bridge(north, south);
    }
    
    vector <Bridge> arr;
    for(int i=0;i<n;i++){
        arr.push_back(bdg[i]);
    }

    sort (arr.begin(), arr.end(), mycompare);
    int num = max_nonoverlapping_bridge(arr, n);

    cout<<"Maximum number of overlapping Bridges is:"<<num<<endl;

    return 0;
}