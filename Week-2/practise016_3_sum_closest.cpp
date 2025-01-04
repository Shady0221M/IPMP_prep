/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<climits>
#include<cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i,j,k,n=nums.size();
        int p=INT_MAX,diff=INT_MAX;
        i=0,j=i+1,k=n-1;
        for(i=0;i<n-2;i++){
            j=i+1;
            k=n-1;
            while(j<k){
                int sum=(nums[i]+nums[j]+nums[k]);
                if(sum>target){
                    int d=sum-target;
                    if(d<diff){diff=d;
                    p=sum;}
                    k--;
                }else{
                    int d=target-sum;
                    if(d<diff){diff=d;
                    p=sum;
                    }
                    j++;
                }
            }
        }
        return p;
    }
//Brute force
    int threeSumClosest(vector<int>& nums, int target) {
        int i,j,k,n=nums.size();
        int p=INT_MAX,diff=INT_MAX;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                for(k=j+1;k<n;k++){
                    int t=(nums[i]+nums[j]+nums[k]);
                    if(t>target){
                        int k=t-target;
                        if(k<diff){p=t;diff=k;}
                    }else{
                        int k=target-t;
                        if(k<diff){p=t;diff=k;}
                    }
                }
            }
        }
        return p;
    }
};