/*A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100*/


/*Three points to note:-
        ---->Find the index after which the numbers are in decreasing order if it is -1 then reverse the array and return
        ---->Now to the sub array right to index find the smallest no. greater than the arr[index],swap them
        ---->Now reverse the elemtents to the right of index.(Sortbut since theya are already in descending order just reverse it)


*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
//O(n)
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