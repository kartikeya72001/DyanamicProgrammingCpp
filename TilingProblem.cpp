#include <iostream>
using namespace std;

int Tiling(int n, int m)
{
    int dp[100] = {0};
    dp[0]= 0;
    for(int i=1;i<m;i++)
        dp[i] = 1;
    dp[m] = 2;
    for(int i = m+1;i<=n;i++)
    {
        dp[i] = dp[i-1]+dp[i-m];
    }
    return dp[n];
}

int main(int argc, char const *argv[]) {
    int n,m;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cout<<Tiling(n,m)<<endl;
    }
    return 0;
}
