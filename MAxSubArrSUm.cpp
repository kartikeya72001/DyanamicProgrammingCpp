#include <iostream>
#include <ctime>
using namespace std;

int maxSum(int a[], int n)
{
    int dp[100] = {0};
    dp[0] = a[0]>0?a[0]:0;

    int maxsofar = dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i] = dp[i-1]+a[i];
        if(dp[i]<0)
            dp[i] = 0;
        maxsofar = max(dp[i],maxsofar);
        //cout<<"Max: "<<maxsofar<<" DP: "<<dp[i]<<endl;
    }
    return maxsofar;
}

int maxSumSpaceOpt(int a[], int n)
{
    int cs = 0;
    int ms = 0;

    for(int i=0;i<n;i++)
    {
        cs += a[i];
        if(cs<0)
            cs = 0;
        ms = max(ms,cs);
    }
    return ms;
}

int main(int argc, char const *argv[]) {
    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n = sizeof(arr)/sizeof(int);
    // cout<<maxSum(arr,n)<<endl;
    cout<<maxSumSpaceOpt(arr,n)<<endl;
    cout<<clock()<<"ms";
    return 0;
}
