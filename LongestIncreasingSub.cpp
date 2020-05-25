#include <iostream>
#include <ctime>
using namespace std;

int LIS(int n,int arr[])
{
    int dp[101] = {1};
    int sol = -1;
    for(int i=1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(arr[j] <= arr[i])
            {
                int curlen = 1+dp[j];
                dp[i] = max(curlen,dp[i]);
            }
        }
        sol = max(sol,dp[i]);
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    //cout<<endl;
    return sol;
}

int main(int argc, char const *argv[]) {
    int n = 10, arr[] = {10,22,9,33,21,50,41,60,80,6};
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }
    cout<<"LIS is: "<<LIS(n,arr)+1<<endl;
    cout<<clock()<<"ms";
    return 0;
}
