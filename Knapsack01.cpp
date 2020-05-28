#include <iostream>
using namespace std;

int Kanpsack(int w, int size[], int val[], int n)
{
    if(n==0 || w==0)
        return 0;

    if(size[n-1] > w)
        return Kanpsack(w,size,val,n-1);
    else
        return max((val[n-1]+Kanpsack(w-size[n-1],size,val,n-1)),Kanpsack(w,size,val,n-1));
}

int KanpsackDp(int w, int size[], int val[], int n)
{
    int i,j;
    int dp[n+1][w+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(size[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], (dp[i-1][j-size[i-1]]+val[i-1]));
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}

int KanpsackMemo(int w, int wt[], int val[], int n, int dp[][100])
{
    if(n<0 || w<=0)
        return 0;
    if(dp[n][w]!=0)
        return dp[n][w];

    if(wt[n]>w)
    {
        dp[n][w] = max(dp[n][w],KanpsackMemo(w,wt,val,n-1,dp));
        return dp[n][w];
    }
    else
    {
        dp[n][w] = max((val[n]+KanpsackMemo(w-wt[n],wt,val,n-1,dp)),KanpsackMemo(w,wt,val,n-1,dp));
        return dp[n][w];
    }
}

int main(int argc, char const *argv[]) {
    int n,s;
    cin>>n>>s;
    int val[1000], size[1000];
    for(int i=0;i<n;i++)
    {
        cin>>size[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }

    int dp[100][100];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
            dp[i][j] = 0;
    }

    //cout<<Kanpsack(s,size,val,n)<<endl;
    //cout<<KanpsackDp(s,size,val,n)<<endl;
    cout<<KanpsackMemo(s,size,val,n-1,dp)<<endl;

    return 0;
}
/*
3
50
10 20 30
60 100 120
220
*/
