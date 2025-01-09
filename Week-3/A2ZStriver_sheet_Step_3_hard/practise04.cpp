/*4 Sum | Find Quads that add up to a target value



Problem Statement: Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.*/
#include<climits>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i=0,j,k,l;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> b;
        for(i=0;i<n-3;){
            for(j=i+1;j<n-2;){
                k=j+1;
                l=n-1;
                set<int> s;
                while(k<l){
                    long long int sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        b.push_back({nums[i],nums[j],nums[k],nums[l]});
                        cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<" "<<nums[l]<<endl;
                        int z=nums[k];
                        while(k<l && nums[k]==z) k++;
                        z=nums[l];
                        while(k<l && z==nums[l]) l--;
                    }else if(sum<target){
                        int z=nums[k];
                        while(k<l && nums[k]==z) k++;
                    }
                    else{
                        int z=nums[l];
                        while(k<l && nums[l]==z) l--;
                    }
                }
                int y=nums[j];
                while(j<n-2 && y==nums[j]) {j++;}
            }
            int y=nums[i];
            while(i<n-3 && y==nums[i]) {i++;}
            
        }
        return b;
    }
};