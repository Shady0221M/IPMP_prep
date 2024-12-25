/*Find the number that appears once, and the other numbers twice


240

3
Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

Examples
Example 1:
Input Format:
 arr[] = {2,2,1}
Result:
 1
Explanation:
 In this array, only the element 1 appear once and so it is the answer.

Example 2:
Input Format:
 arr[] = {4,1,2,1,2}
Result:
 4
Explanation:
 In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.*/
#include <iostream> 
#include<vector>
#include<algorithm>
using namespace std;
//O(n)
//Xor function
int find_once_among_pairs(vector<int> &nums){
    int x=nums[0];
    for(int i=1;i<nums.size();i++){
        x=x^nums[i];
    }
    return x;
}
//Can also use hashing!
//Array hashing O(3*n)
//Using map O(nlogm) m-size of hash-map

//O(nlogn)
int find_once_among_pairs1(vector<int> &nums){
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int i=0;i<n-1;i=i+2){
        if(nums[i]==nums[i+1]) continue;
        else{return nums[i];}
    }
    return nums[n-1];
}
int main(){
    vector<int> nums={1,2,3,3,1,5,5};
    cout<<find_once_among_pairs(nums);
}