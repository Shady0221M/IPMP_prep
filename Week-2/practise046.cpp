/*Given an array nums of distinct integers, return all the possible 
permutations
. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
    void calc_permute(vector<int>&nums, vector<int> &used,vector<int> &s,vector<vector<int>> &array){
        if(s.size()==nums.size()){
            array.push_back(s);
            return;
        }else{
            for(int i=0;i<nums.size();i++){
                if(!used[i]){
                    used[i]=1;
                    s.push_back(nums[i]);
                    calc_permute(nums,used,s,array);
                    used[i]=0;
                    s.pop_back();
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size());
        vector<int> s;
        vector<vector<int>> array;
        calc_permute(nums,used,s,array);
        return array;
    }
};