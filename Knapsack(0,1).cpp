#include <iostream>
using namespace std;

int Kanpsack(int n, int s, int val[], int size[])
{
    
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

    cout<<Kanpsack(n,s,val,size)<<endl;

    return 0;
}
