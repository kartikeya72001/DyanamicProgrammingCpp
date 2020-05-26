#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

bool TargetSum(int n, int sum, vector<int> arr)
{
    if(sum==0)
        return true;
    if(n==0 && sum!=0)
        return false;

    if(arr[n-1]>sum)
        return TargetSum(n-1, sum, arr);
    else
        return TargetSum(n-1,sum,arr) || TargetSum(n-1,sum-arr[n-1],arr);
}
bool TargetSumDp(int n, int sum, vector<int> arr, bool dp[][1000])
{
    if(sum==0)
        return true;
    if(n==0 && sum!=0)
        return false;

    if(dp[n][sum]!=false)
        return dp[n][sum];

    if(arr[n-1]>sum)
        return dp[n][sum] = TargetSum(n-1, sum, arr);
    else
        return dp[n][sum] = TargetSum(n-1,sum,arr) || TargetSum(n-1,sum-arr[n-1],arr);
}

int main(int argc, char const *argv[]) {
    int n = 5, sum = 10;
    // cin>>n>>sum;
    bool dp[1000][1000] = {false};
    vector<int> arr = {1,2,3,4,5};
    // for(int i=0;i<n;i++)
    //     cin>>arr[i];
    // if(TargetSum(n,sum,arr))
    //     cout<<"Yes"<<endl;
    // else
    //     cout<<"No"<<endl;
    //
    if(TargetSumDp(n,sum,arr,dp))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    cout<<clock()<<"ms";
    return 0;
}
