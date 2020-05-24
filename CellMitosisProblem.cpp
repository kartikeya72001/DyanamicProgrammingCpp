#include <iostream>
using namespace std;

long long Mitosis(int n, int x, int y, int z)
{
    int dp[100] = {0};
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
            dp[i] = min(dp[i/2]+x,dp[i-1]+y);
        else
            dp[i] = min(dp[i-1]+y,dp[(i+1)/2]+z);
    }
    return dp[n];
}

int main(int argc, char const *argv[]) {
    int n, x, y, z;
    cin>>n>>x>>y>>z;
    cout<<"Min Cost: "<<Mitosis(n,x,y,z);
    return 0;
}
