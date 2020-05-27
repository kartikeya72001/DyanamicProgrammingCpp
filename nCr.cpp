#include <iostream>
using namespace std;

int nCr(int n, int k)
{
    if(k==n || k==0)
        return 1;
    return nCr(n-1,k-1) + nCr(n-1,k);
}

int nCrDp(int n, int k)
{
    int dp[200][200];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=min(i,k);j++)
        {
            if(j==0 || j==i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }
    return dp[n][k];
}

int main(int argc, char const *argv[]) {
    int n,k;
    cin>>n>>k;
    //cout<<nCr(n,k)<<endl;
    cout<<nCrDp(n,k);
    return 0;
}
