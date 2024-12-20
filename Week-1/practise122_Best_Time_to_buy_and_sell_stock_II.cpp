#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,n=prices.size();
        int m=prices[0],profit=0;
        for(i=1;i<n;i++){
            if(prices[i]<prices[i-1]){
                profit+=(prices[i-1]-m);
                m=prices[i];
            }
        }
        profit+=prices[i-1]-m;
        return profit;
    }
};