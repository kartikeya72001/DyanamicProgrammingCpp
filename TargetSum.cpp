#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
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

bool TargetSumBu(vector <int> a, int sum)
{
    bool dp[a.size() + 1][sum+1];
    memset(dp, false, sizeof(dp));

    for(int i = 0; i < a.size() + 1; i++)
        dp[i][0] = true;
    for(int i = 1; i < sum+1; i++)
        dp[0][i] = false;
    for(int i = 0; i < a.size() + 1; i++){
        for(int j = 1; j < sum+1; j++){
            if(j < a[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }

        }
    }
    return dp[a.size()][sum];
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
