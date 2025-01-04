/*Count Subarray sum Equals K

Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.

A subarray is a contiguous non-empty sequence of elements within an array.*/

//Already done in leetcode

 #include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,sum=0;
        int n=nums.size();
        map<int,int> hash;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k) ans++;
            if(hash.find(sum-k)!=hash.end()){
                ans+=hash[sum-k];
            }
            hash[sum]++;
        }
        return ans;
    }
};