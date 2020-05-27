#include <iostream>
using namespace std;

int fact(int n)
{
    if(n==0 or n==1)
        return 1;
    return n*fact(n-1);
}

int nPr(int n, int k)
{
    if(k==0)
        return 1;
    if(k==n)
        return fact(n);
    return (k*nPr(n-1,k-1)) + nPr(n-1,k);
}

int nPrDp(int n, int k)
{
    int dp[200][200] = {0};

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=min(i,k);j++)
        {
            if(j==0)
                dp[i][j] = 1;
            else
                dp[i][j] = (j*dp[i-1][j-1]) + dp[i-1][j];
        }
    }
    return dp[n][k];
}

int main(int argc, char const *argv[]) {
    int n,k;
    cin>>n>>k;
    cout<<nPr(n,k)<<endl;
    //cout<<nPrDp(n,k)<<endl;
    return 0;
}
