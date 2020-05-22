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

int RodCuttingBU(int n, int price[])
{
    int dp[100] = {0};
    for(int i=1;i<=n;i++){
        int best = 0;
        for(int j=1;j<=i;j++)
            best = max(best, price[j-1] + dp[i-j]);
        dp[i] = best;
    }
    return dp[n];
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
    int n=4, price[] = {1,3,2,5};
    int dp[100] = {0};
    cout<<"Recursion:   "<<RodCutting(n,price)<<endl;
    cout<<"TD: "<<RodCuttingTD(n,price,dp)<<endl;
    cout<<"BU: "<<RodCuttingBU(n,price)<<endl;
    cout<<clock()<<"ms"<<endl;
    return 0;
}
