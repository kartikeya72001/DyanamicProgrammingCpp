#include <iostream>
#include <vector>
using namespace std;

int MatrixChainMult(vector<int> v)
{
    int dp[100][100] = {0};
    int n = v.size()-1;
    for(int i=1;i<n;i++)
    {
        int r = 0,c = i;
        while(c<n)
        {
            int val = 1e8;
            for(int j = r;j<c;j++)
            {
                val = min(val,dp[r][j]+dp[j][c]+(v[r]*v[j+1]*v[c+1]));
            }
            dp[r][c] = val;
            r++, c++;
        }
    }
    return dp[0][n-1];
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    std::vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<"best solution is: "<<MatrixChainMult(v);
    return 0;
}
