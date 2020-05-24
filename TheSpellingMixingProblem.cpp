#include <iostream>
#include <climits>
using namespace std;

int arr[1000];
long long dp[1000][1000] = {-1};

long long sumElements(int s, int e){
    long long ans = 0;
    for(int i=s;i<=e;i++){
        ans += arr[i];
        ans %= 100;
    }
    //cout<<"i,j: "<<s<<e<<" Sum: "<<ans<<endl;
    return ans;
}

long long Mixtures(int i, int j){
    if(i>=j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    dp[i][j] = INT_MAX;
    for(int k=i;k<=j;k++){
        dp[i][j] = min(dp[i][j], Mixtures(i,k)+Mixtures(k+1,j)+sumElements(i,k)*sumElements(k+1,j));
    }
    return dp[i][j];
}

int main(int argc, char const *argv[]) {
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        // cout<<"Arr: ";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j] = -1;
            }
        }
        cout<<Mixtures(0,n-1)<<endl;
    }
    return 0;
}
