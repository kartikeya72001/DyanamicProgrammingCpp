#include <iostream>
using namespace std;

int uniquePaths(int m, int n)
{
    int dp[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            if(i==0 or j==0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"No. of Ways: ";
    return dp[m-1][n-1];
}

int main(int argc, char const *argv[]) {
    int n,m;
    cin>>n>>m;
    cout<<"Matrix: "<<endl;
    cout<<uniquePaths(m,n)<<endl;
    return 0;
}
