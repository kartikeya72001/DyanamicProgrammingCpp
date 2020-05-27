#include <iostream>
#include <ctime>
using namespace std;

int fibdp(int n, int dp[])
{
    if(n==0 or n==1)
        return n;
    if(dp[n]!=0)
        return dp[n];
    int ans;
    ans = fibdp(n-1,dp)+(n-1)*fibdp(n-2,dp);
    return dp[n] = ans;
}

int fib(int n)
{
    if(n==0 or n==1)
        return n;
    int ans;
    ans = fib(n-1)+(n-1)*fib(n-2);
    return ans;
}

int main(int argc, char const *argv[]) {
    int n=3;
    int dp[100] = {0};
    //std::cin >> n;
    std::cout<<fibdp(n,dp)<<endl;
    //std::cout <<fib(n) << '\n';
    cout<<clock()<<"ms";
    return 0;
}

/*
Given n friends, each one can remain single or can be paired up with some other
friend. Each friend can be paired only once. Find out the total number of ways
in which friends can remain single or can be paired up.
*/
