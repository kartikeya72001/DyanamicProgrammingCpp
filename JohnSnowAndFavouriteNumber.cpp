#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char const *argv[]) {
    int n,k,x;
    cin>>n>>k>>x;
    int *freq = new int[1500]();
    for(int i=0;i<n;i++)
    {
        int xi;
        cin>>xi;
        freq[xi]++;
    }

    int *temp = new int[1500]();
    while(k--)
    {
        for(int i=0;i<1500;i++)
            temp[i] = freq[i];

        int parity = 0;
        for(int i=0;i<1500;i++)
        {
            if(freq[i]>0)
            {
                int cur = i^x;
                int changeval = freq[i]/2;
                if(parity==0)
                    changeval+=(freq[i] & 1);

                temp[i] = temp[i] - changeval;
                temp[cur] = temp[cur] + changeval;
                parity ^= (freq[i] & 1);
            }
        }
        for(int i=0;i<1500;i++)
            freq[i] = temp[i];
    }
    int minval = INT_MAX, maxval = INT_MIN;
    for(int i=0;i<1500;i++)
    {
        if(freq[i]>0)
        {
            minval = min(minval,i);
            maxval = max(maxval,i);
        }
    }
    cout<<"Min is: "<<minval<<" and Max is: "<<maxval<<endl;
    return 0;
}
