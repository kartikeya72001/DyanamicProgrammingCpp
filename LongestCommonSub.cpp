#include <iostream>
#include <ctime>
using namespace std;

int LCS(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int dp[100][100] = {0};
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int q = 0;
            if(s1[i-1] == s2[j-1])
            {
                q = 1+dp[i-1][j-1];
            }

            else
                q = max(dp[i-1][j],dp[i][j-1]);
            dp[i][j] = q;
        }
    }
    return dp[m][n];
}
string LCSString(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    string dp[100][100] = {""};
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            string q = "";
            if(s1[i-1] == s2[j-1])
            {
                q = dp[i-1][j-1]+s1[i-1];
            }

            else
                q =dp[i-1][j].length() > dp[i][j-1].length()? dp[i-1][j]:dp[i][j-1];
            dp[i][j] = q;
        }
    }
    return dp[m][n];
}

int main(int argc, char const *argv[]) {
    string s1 = "aabcd",s2 = "abccd";
    //cin>>s1>>s2;
    cout<<LCS(s1,s2)<<endl;
    cout<<clock()<<"ms";
    return 0;
}
