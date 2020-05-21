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

int main(int argc, char const *argv[]) {
    int n = 4,k = 3;
    int dp[100] = {0};
    //cin>>n>>k;
    cout<<ladderTD(n,k,dp)<<endl;
    cout<<clock()<<"ms";
    return 0;
}
