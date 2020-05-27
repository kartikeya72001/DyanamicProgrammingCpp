#include <iostream>
#include <cstring>
using namespace std;

int dp[105][105];

int Palindrome(string s)
{
    memset(dp,0,sizeof(dp));
    int n = s.length();
    for(int i=0;i<n;i++)
        dp[i][i] = 1;
    for(int j = 2;j<=n;j++)
    {
        for(int i = 0;i<=n-j;i++)
        {
            int k = i+j-1;
            if(s[i]==s[k])
                dp[i][k] = dp[i+1][k-1]+2;
            else
            dp[i][k] = max(dp[i+1][k],dp[i][k-1]);
        }
    }
    return dp[0][n-1];
}

int main(int argc, char const *argv[]) {
    string s;
    cin>>s;
    cout<<Palindrome(s);
    return 0;
}
