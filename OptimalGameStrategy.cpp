#include <iostream>
using namespace std;
int dp[10000][10000]={};
int optimalGameTD(int *coins,int i,int j)
{
    if(i>j)
        return 0;

    if(dp[i][j]!=0)
        return dp[i][j];

    int sum=0;
    int s1=coins[i] + min(optimalGameTD(coins,i+2,j),optimalGameTD(coins,i+1,j-1));
    int s2=coins[j] + min(optimalGameTD(coins,i,j-2),optimalGameTD(coins,i+1,j-1));
    sum += max(s1,s2);
    return dp[i][j]=sum;
}

int main() {
    int n;
    cin>>n;
    int *coins=new int[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
        sum+=coins[i];
    }
    int ans=optimalGameTD(coins,0,n-1);
    cout<<max(ans,sum-ans)<<endl;
}

/*
Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally.

Input Format
First line contains the number of coins 'n'.
Second line contains n space separated integers where ith index denotes the value of ith coin.

Constraints
1 < N <= 30 , N is always even
0 <= Ai <= 1000000

Output Format
Print a single line with the maximum possible value that Piyush can win with.

Sample Input
4
1 2 3 4
Sample Output
6
Explanation
Piyush will pick the coin 4. Then Nimit can pick either 1 or 3. In both the cases piyush picks coin 2 and wins with a total of 6.
*/
