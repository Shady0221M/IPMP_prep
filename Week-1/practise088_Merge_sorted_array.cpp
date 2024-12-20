#include<iostream>
#include<vector>
using namespace std;
//O(n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){return;}
        else if(m==1 && nums1[0]==0){for(int i=0;i<n;i++) nums1[i]=nums2[i];}
        else{
            int i=0,j=0;
            vector<int> b;
            while(i<m && j<n){
                if(nums1[i]<nums2[j]){
                    b.push_back(nums1[i++]);
                }else{
                    b.push_back(nums2[j++]);
                }   
            }
            while(i<m){
                b.push_back(nums1[i++]);
            }
            while(j<n){
                b.push_back(nums2[j++]);
            }
            for(i=0;i<m+n;i++){
                nums1[i]=b[i];
            }
        }
    }
};