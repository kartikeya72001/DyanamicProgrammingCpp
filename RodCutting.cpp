#include <iostream>
#include <ctime>
using namespace std;

int RodCuttingTD(int n, int price[], int dp[])
{
    if(n==0)
        return 0;

    if(dp[n]!=0)
        return dp[n];
    int maxp = 0;
    for(int i=1;i<=n;i++){
        int profit = price[i-1] + RodCuttingTD(n-i,price,dp);
        maxp = max(maxp,profit);
    }
    return dp[n] = maxp;
}
int RodCutting(int n, int price[])
{
    if(n==0)
        return 0;

    int maxp = 0;
    for(int i=1;i<=n;i++){
        int profit = price[i-1] + RodCutting(n-i,price);
        maxp = max(maxp,profit);
    }
    return maxp;
}

int main(int argc, char const *argv[]) {
    int n=4, price[] = {2,3,2,5};
    int dp[100] = {0};
    //cout<<RodCutting(n,price)<<endl;
    cout<<RodCuttingTD(n,price,dp)<<endl;
    cout<<clock()<<"ms"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    return 0;
}
