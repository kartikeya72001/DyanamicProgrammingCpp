#include<iostream>
using namespace std;
int main() {
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int l=0,r=0;
	int zeros=0;
	int maxlength=0;
	int length=0;

    int maxLengthL = -1;
    int maxLengthR = -1;

	while(r<=n-1){
		if(a[r]==1){
			length=r-l+1;
			r++;
		}
		else{
			zeros++;
			while(zeros>k){
				if(a[l]==0)zeros--;
				l++;
			}
			length=r-l+1;
			r++;
		}

        if(length > maxlength) {
            maxlength = length;
            maxLengthR = r - 1;
            maxLengthL = l;
        }
	}

	cout<<maxlength<<endl;
	for(int i=0;i<maxLengthL;i++){
		cout<<a[i]<<" ";
	}
    if(maxLengthL != -1)
	for(int i = maxLengthL;i<=maxLengthR;i++){
		cout<<1<<" ";
	}
	for(int i=maxLengthR+1;i<n;i++){
     	cout<<a[i]<<" ";
	}
	return 0;
}
