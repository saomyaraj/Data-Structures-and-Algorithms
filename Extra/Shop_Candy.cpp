class Solution
{
public:
#include<bits/stdc++.h>
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int i=0,j=N-1;
        int mincount=0;
        while(i<=j){
            mincount+=candies[i];
            i=i+1;
            j=j-K;
        }
        i=0;j=N-1;
        int maxcount=0;
        while(i<=j){
            maxcount+=candies[j];
            i=i+K;
            j=j-1;
        }
        vector<int> ans;
        ans.push_back(mincount);
        ans.push_back(maxcount);
        return ans;
    }
};