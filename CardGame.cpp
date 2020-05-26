#include <iostream>
#include <vector>
using namespace std;

int maxScore(vector<int>& card, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> aage(k);
        vector<int> peeche(k);
        aage[0] = card[0];
        peeche[0] = card[card.size()-1];

        for(int i=1;i<k;++i)
            aage[i] = card[i]+aage[i-1];
        for(int i=1;i<k;++i)
            peeche[i] = card[card.size()-i-1]+peeche[i-1];

        int maxnum = peeche[k-1];
        if(aage[k-1]>maxnum)
            maxnum = aage[k-1];
        for(int i=0;i<k-1;++i){
            int y = peeche[i]+aage[k-i-2];
            if(y>maxnum){
                maxnum = y;
            }
        }
        return maxnum;
}
int maxPoints1(int cards[], int idx1, int k, int dp1[]) {
    if(k == 0)
        return 0;

     if(dp1[idx1] != 0)
            return dp1[idx1];


    dp1[idx1] += cards[idx1] + maxPoints1(cards, idx1 + 1, k - 1, dp1);

    return dp1[idx1];
}
int maxPoints2(int cards[], int idx2, int k, int dp2[]) {
    if(k == 0)
        return 0;

     if(dp2[idx2] != 0)
        return dp2[idx2];

    dp2[idx2] += cards[idx2] + maxPoints2(cards, idx2 - 1, k - 1, dp2);

    return dp2[idx2];
}

int Solver(int cards[], int k, int dp1[], int dp2[], int n)
{
   return max(maxPoints1(cards,0,k,dp1), maxPoints2(cards,n-1,k,dp2));
}

int main() {
    int cards[]={1,79,80,1,1,1,200,1};
    int n = sizeof(cards)/sizeof(int);
    int k=3;
    int dp1[100000] = {0};
    int dp2[100000] = {0};
    cout<<(Solver(cards,k,dp1,dp2,n))<<endl;

    for(int i=0;i<n;i++)
        cout<<(dp1[i])<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<(dp2[i])<<" ";
}
/*
There are several cards arranged in a row, and each card has an associated number of points The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.



Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
*/
