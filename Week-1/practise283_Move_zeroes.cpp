#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        while(i<n){
            if(nums[i]!=0){nums[j++]=nums[i];}
            i++;
        }
        while(j<n){
            nums[j++]=0;
        }
    }
};