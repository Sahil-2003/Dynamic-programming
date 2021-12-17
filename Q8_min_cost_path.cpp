#include<bits/stdc++.h>
using namespace std;

class Pair{
    private:
        string psf;
        int a;
        int b;
    public:
        Pair(string psf, int a, int b){
            this->psf = psf;
            this->a = a;
            this->b = b;
        }
};

int main()
{
    const int m = 5;
    const int n = 5;
    int arr[m][n] = {
                        2,6,1,1,3,
                        9,1,1,0,5,
                        0,7,5,2,0,
                        4,3,0,4,7,
                        2,0,1,4,1
    };

    int dp[m][n];
    for(int i=4;i>=0;i--){
        for(int j=4;j>=0;j--){
            if(i == 4 && j == 4){
                dp[i][j] = arr[i][j];
            }
            else if(i == 4){
                dp[i][j] = arr[i][j] + dp[i][j+1];
            }
            else if(j == 4){
                dp[i][j] = arr[i][j] + dp[i+1][j];
            }
            else{
                dp[i][j] = arr[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    
    return 0;
}    