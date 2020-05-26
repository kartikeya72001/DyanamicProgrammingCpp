#include <iostream>
#include <ctime>
#include <climits>
using namespace std;

int PathToOne(int n) //Bottom Up Approach
{
    if(n==1 or n==2)
        return n-1;
    int dp[100] = {0};

    for(int i=2;i<=n;i++)
    {
        if(i%2==0 and i%3==0)
            dp[i] = min(dp[i-1],min(dp[i/2],dp[i/3]))+1;
        else if(i%2==0)
            dp[i] = min(dp[i-1],dp[i/2])+1;
        else if(i%3==0)
            dp[i] = min(dp[i-1],dp[i/3])+1;
        else
            dp[i] = dp[i-1]+1;
    }
    return dp[n];
}

int minStepsToOne(int n)
{
    if(n==1)
        return 0;

    int a,b,c,count=0;
    a=b=c=INT_MAX;
    if(n%3==0)
        a=minStepsToOne(n/3);
    else if(n%2==0)
        b=minStepsToOne(n/2);
    c=minStepsToOne(n-1);
    count = min(min(a,b),c)+1;


    return count;
}

int minSteps(int n, int dp[]) //Top Down Approach
{
    if(n==1)
        return 0;

    if(dp[n]!=0)
        return dp[n];
    int a,b,c;
    a = b = c = INT_MAX;

    if(n%3==0){
        a = minSteps(n/3,dp)+1;
    }
    if(n%2==0){
        b = minSteps(n/2,dp)+1;
    }
    c = minSteps(n-1,dp)+1;

    int ans = min(min(a,b),c);
    return dp[n] = ans;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n=10;
    int dp[101] = {0};
    //cin>>n;
    //cout<<PathToOne(n)<<endl;
    //cout<<minSteps(n,dp)<<endl;
    cout<<minStepsToOne(n)<<endl;
    cout<<clock()<<"ms";
    return 0;
}
