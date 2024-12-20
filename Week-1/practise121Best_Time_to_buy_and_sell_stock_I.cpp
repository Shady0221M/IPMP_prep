#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //O(n^2)
    int maxProfit1(vector<int>& prices) {
        int i,j,m;
        int n=prices.size();
        vector<int> b;
        for(i=0;i<n-1;i++){
            m=prices[i];
            for(j=i+1;j<n;j++){
                if(prices[j]>m) m=prices[j];
            }
            b.push_back(m-prices[i]);
        }
        b.push_back(0);
        m=b[0];
        for(i=0;i<n;i++){
            if(b[i]>m)  m=b[i];
        }
        return m;
    }
    //O(n)
    int maxProfit(vector<int>& prices) {
        int i,m,profit=0;
        int n=prices.size();
        m=prices[0];
        for(i=1;i<n;i++){
            if(prices[i]<m) m=prices[i];
            if(prices[i]-m>profit) profit=prices[i]-m;
        }
        return profit;
    }
};
int main(){
    vector<int> nums={7,1,5,3,6,4};
    cout<<"Hello"<<endl;
    Solution s;
    cout<<s.maxProfit(nums);
}