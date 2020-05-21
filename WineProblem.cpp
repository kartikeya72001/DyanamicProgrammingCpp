#include <iostream>
#include <ctime>
#include <climits>
using namespace std;

int Wines(int *wines, int i, int j, int y, int dp[][100]) //Implementation using 2D dp
{
    if(i>j)
        return 0;

    if(dp[i][j]!=0)
        return dp[i][j];

    int a = wines[i]*y + Wines(wines,i+1,j,y+1,dp);
    int b = wines[j]*y + Wines(wines,i,j-1,y+1,dp);
    return dp[i][j] = max(a,b);
}

int WinesWithout(int *wines, int i, int j, int y) //Implementation without DP
{
    if(i>j)
        return 0;

    int a = wines[i]*y + WinesWithout(wines,i+1,j,y+1);
    int b = wines[j]*y + WinesWithout(wines,i,j-1,y+1);
    return max(a,b);
}

int main(int argc, char const *argv[]) {
    int wines[100]={2,3,5,1,4,7,6,3,8,2};
    int n = 10;
    int dp[100][100] = {0};
    cout<<Wines(wines,0,n-1,1,dp)<<endl;
    //cout<<WinesWithout(wines,0,n-1,1)<<endl;
    cout<<clock()<<"ms";
    return 0;
}
