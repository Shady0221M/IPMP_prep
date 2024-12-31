/*Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
class Solution {
public:
    void swap(vector<int> &nums,int i,int j){
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }
    void calc_permute(vector<int> &nums,int index,set<vector<int>> &array){
        //cout<<index<<endl;
        if(index==nums.size()){
            vector<int> ans(nums.begin(),nums.end());
            array.insert(ans);
            //cout<<"Hurray"<<endl;
            //cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
            cout<<array.size()<<endl;
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums,index,i);
            //cout<<"After swap"<<endl;
            //cout<<nums[0]<<" "<<nums[1]<<" "<<nums[2]<<endl;
            calc_permute(nums,index+1,array);
            swap(nums,index,i);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      set<vector<int>> array;
      calc_permute(nums,0,array);
      vector<vector<int>> ans(array.begin(),array.end());
      return ans;  
    }
};
int main(){
    vector<int> nums={1,1,2};
    Solution s;
    vector<vector<int>> ans;
    ans=s.permuteUnique(nums);
}