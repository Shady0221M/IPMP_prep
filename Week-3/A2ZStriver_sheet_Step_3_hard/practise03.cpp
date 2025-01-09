/*3 Sum : Find triplets that add up to a zero

Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to
 give a sum of zero. In short, you need to return an array of all the unique 
triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero*/

#include<climits>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> b;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j,k;
        while(i<n){
            j=i+1;
            k=n-1;
            
                while(j<k){
                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum==0){
                        b.push_back(vector<int> {nums[i], nums[j], nums[k]});
                        //cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                        int z=nums[j];
                        while(j<k && z==nums[j]){j++;}
                        z=nums[k];
                        while(j<k && z==nums[k]){k--;}
                    }else if(sum<0){int z=nums[j];
                        while(j<k && z==nums[j]){j++;}}
                    else{
                        int z=nums[k];
                        while(j<k && z==nums[k]){k--;}
                    }
                    
                }
            
            int y=nums[i];
            while(i<n && y==nums[i]){i++;}
        }
        return b;
    }
};