#include <iostream>
using namespace std;
int dp[10000][10000]={};
int optimalGameTD(int *coins,int i,int j)
{
    if(i>j)
        return 0;

    if(dp[i][j]!=0)
        return dp[i][j];

    int sum=0;
    int s1=coins[i] + min(optimalGameTD(coins,i+2,j),optimalGameTD(coins,i+1,j-1));
    int s2=coins[j] + min(optimalGameTD(coins,i,j-2),optimalGameTD(coins,i+1,j-1));
    sum += max(s1,s2);
    return dp[i][j]=sum;
}

int main() {
    int n;
    cin>>n;
    int *coins=new int[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
        sum+=coins[i];
    }
    int ans=optimalGameTD(coins,0,n-1);
    cout<<max(ans,sum-ans)<<endl;
}
