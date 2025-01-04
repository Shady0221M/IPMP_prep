/*Subarray Sum in an Array

Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray.*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#include<climits>
//Kadane's algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,i,s=0,n=nums.size(),p=INT_MIN;
        for(i=0;i<n;i++){
            sum+=nums[i];
            if(sum>p){p=sum;}
            if(sum<0){
                sum=0;
            }
        }
        return p;
    }
};