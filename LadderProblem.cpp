#include <iostream>
#include <ctime>
using namespace std;

int ladderTD(int n, int k, int dp[])
{
    if(n==0)
        return 1;

    if(dp[n]!=0)
    {
        return dp[n];
    }
    int ways = 0;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        {
            ways+=ladderTD(n-i,k,dp);
        }
    }
    return dp[n] = ways;
}

int ladderBU(int n, int k)
{
    int dp[100] = {0};
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        dp[i] = 0;
        for(int j = 1;j<=k;j++)
        {
            if(i-j>=0)
                dp[i] += dp[i-j];
        }
    }

    return dp[n];
}

int ladderBUOpt(int n, int k)
{
    int dp[100] = {0};
    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        if(i-k-1<0)
            dp[i] = 2*dp[i-1];
        else
            dp[i] = 2*dp[i-1]-dp[i-k-1];
    }

    return dp[n];
}

int main(int argc, char const *argv[]) {
    int n = 4,k = 3;
    int dp[100] = {0};
    //cin>>n>>k;
    //cout<<ladderBU(n,k)<<endl;
    cout<<ladderBUOpt(n,k)<<endl;
    //cout<<ladderTD(n,k,dp)<<endl;
    cout<<clock()<<"ms";
    return 0;
}
