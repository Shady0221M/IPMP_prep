#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> b;
        int i;
        int n=nums.size();
        for(i=0;i<n;i++){
            if(i==0) b.push_back(nums[0]);
            else b.push_back(nums[i]+b[i-1]);
        }
        return b;
    }
};