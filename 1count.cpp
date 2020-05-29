#include <iostream>
using namespace std;

int Count(int *arr, int n, int k)
{
    int dp[1000];
    dp[0] = 0;
    int cur = arr[0];
    int ans = 0;
    int i;
    for(i;i<=n;i++)
    {
        if(ans/2 == k || ans/2==k-1)
            break;
        if(arr[i] == !cur)
        {
            dp[i] += dp[i-1]+1;
            cur = arr[i];
            ans++;
        }
        else
        {
            dp[i] = 0;
            ans=0;
        }
    }
    // for(int j=0;j<i;j++)
    //     cout<<dp[j]<<" ";
    // cout<<endl;
    return dp[i-1];
}

int main(int argc, char const *argv[]) {
    int n, arr[100000],k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<Count(arr,n,k)<<endl;
    return 0;
}
/*
10 2
1 0 0 1 0 1 0 1 0 1
*/
