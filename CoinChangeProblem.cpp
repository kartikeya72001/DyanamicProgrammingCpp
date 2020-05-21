#include <iostream>
#include <climits>
#include <ctime>
using namespace std;

int coinChangeTD(int n, int t, int *coins, int dp[])
{
    if(n==0)
        return 0;

    if(dp[n]!=0)
        return dp[n];

    int ans = INT_MAX;
    for(int i=0;i<t;i++)
    {
        if(n-coins[i]>=0)
        {
            int subprob = coinChangeTD(n-coins[i],t,coins,dp);
            ans = min(ans,subprob+1);
        }
    }
    dp[n] = ans;
    return dp[n];
}

int coinChangeBU(int N, int T, int *coins)
{
    int dp[100] = {0};

    for(int n=1;n<=N;n++)
    {
        dp[n] = INT_MAX;
        for(int i=0;i<T;i++)
        {
            if(n-coins[i]>=0)
            {
                int subp = dp[n-coins[i]];
                dp[n] = min(dp[n],subp+1);
            }
        }
    }
    return dp[N];
}

int main(int argc, char const *argv[]) {
    int n=15,t=3;
    int coins[100]={1,5,7};
    int dp[100] = {0};
    //cin>>n>>t;
    // for (size_t i = 0; i < t; i++) {
    //     cin>>coins[i];
    // }

    //cout<<coinChangeTD(n,t,coins,dp)<<endl;
    cout<<coinChangeBU(n,t,coins)<<endl;
    cout<<clock()<<"ms";
    return 0;
}
