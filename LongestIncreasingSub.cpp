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
    int n = 5, arr[] = {1,3,5,4,7};
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }
    cout<<"LIS is: "<<LIS(n,arr)<<endl;
    cout<<clock()<<"ms";
    return 0;
}
/*//NLOG(N) LIS
#include <bits/stdc++.h>
using namespace std;

int LIS(int n, vector<int> nums)
{
    vector<int>lis;

    for(int i=0 ; i<n ;i++){
       auto it=lower_bound(begin(lis),end(lis),nums[i]);

       if(it==lis.end())lis.push_back(nums[i]);

       else *it=nums[i];
    }
    return lis.size();
}

int main(int argc, char const *argv[]) {
    int n;
	cin>>n;
	vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<LIS(n,arr)<<endl;
    //cout<<clock()<<"ms";
    return 0;
}

*/
