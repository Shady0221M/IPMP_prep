/*Sort an array of 0s, 1s and 2s

Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
//O(n)Dutch national flag algo
    void swap(vector<int>& nums,int i,int j){
    int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
}
    void sortColors(vector<int>& nums) {
        int low,mid,high;
        low=0;
        mid=0;
        high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){swap(nums,low,mid);mid++;low++;}
            else if(nums[mid]==1){mid++;}
            else{
                swap(nums,mid,high);
                high--;
            }
        }
    }

    //O(2n)
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        int n=nums.size(),i;
        for(i=0;i<n;i++){
            if(nums[i]==0) a++;
            else if(nums[i]==1) b++;
            else c++;
        }
        i=0;
        while(a!=0){nums[i++]=0;a--;}
        while(b!=0){nums[i++]=1;b--;}
        while(c!=0){nums[i++]=2;c--;}
    }
};
