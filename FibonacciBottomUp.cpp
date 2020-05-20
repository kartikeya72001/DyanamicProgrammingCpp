#include <iostream>
#include <ctime>
using namespace std;

int fibBU(int n)
{
    int dp[100] = {0};
    dp[1] = 1;

    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int fibSpace(int n)
{
    if(n==0 or n==1)
        return n;
        int a = 0, b = 1;
        int c;
        for(int i=2;i<=n;i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n=40;
    int dp[100] = {0};
    //std::cin >> n;
    //std::cout<<fibdp(n,dp)<<endl;
    //std::cout <<fibBU(n) << '\n';
    cout<<fibSpace(n)<<endl;
    cout<<clock()<<"ms";
    return 0;
}
