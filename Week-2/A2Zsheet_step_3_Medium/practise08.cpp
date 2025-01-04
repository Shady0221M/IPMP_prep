/*next_permutation : find next lexicographically greater permutation


545

11
Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,index,swap_index,n=nums.size();
        for(i=n-1;i>=1;i--){
            if(nums[i]>nums[i-1]){index=i-1;break;}
        }
        if(i==0){reverse(nums.begin(),nums.end());return;}
        for(i=n-1;i>index;i--){
            if(nums[i]>nums[index]){swap_index=i;break;}
        }
        int temp=nums[index];
        nums[index]=nums[swap_index];
        nums[swap_index]=temp;
        reverse(nums.begin()+index+1,nums.end());
    }
};