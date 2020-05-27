#include <iostream>
using namespace std;

int BellNumber(int n)
{
    int dp[100][100] = {0};
    dp[0][0] = 1;

    for(int i=1;i<n;i++)
    {
        dp[i][0] = dp[i-1][i-1];

        for(int j=1;j<=i;j++)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n-1][n-1];
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    cout<</*"Set Partitions for "<<n<<" is: "<<*/BellNumber(n)<<endl;
    return 0;
}

/*
1
1 2
2 3 5
5 7 10 15
15 20 27 37 52
*/
