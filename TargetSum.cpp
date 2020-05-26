#include <iostream>
#include <vector>
using namespace std;

int TargetSum(int n, int sum, int arr[])
{

}

int main(int argc, char const *argv[]) {
    int n, sum;
    cin>>n>>sum;
    int dp[100] = {0};
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<TargetSum(n,sum,arr)<<endl;
    return 0;
}
