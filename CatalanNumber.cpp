#include <iostream>
#include <ctime>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for(int i=1;i<=n;i++)
    {
      fact*=i  ;
    }
    return fact;
}

int Catalan(int n)
{
    int n2 =  factorial(2*n);
    int n1 = factorial(n);
    return n2/(n1*n1*(n+1));
}
int CatalanRecDp(int n,int dp[])
{
    if(n<=0)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += CatalanRecDp(n-i-1,dp)*CatalanRecDp(i,dp); //No. of subtrees less than root * No. of Subtrees greater than root
    }
    return dp[n] = ans;
}

int CatalanRec(int n)
{
    if(n<=0)
        return 1;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += CatalanRec(n-i-1)*CatalanRec(i); //No. of subtrees less than root * No. of Subtrees greater than root
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int n=15;
    //cin>>n;
    int dp[100] = {0};
    //cout<<Catalan(n)<<endl;
    //cout<<CatalanRec(n)<<endl;
    cout<<CatalanRecDp(n,dp)<<endl;
    cout<<clock()<<"ms";
    return 0;
}
