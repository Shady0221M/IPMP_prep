/*Longest Subarray with sum K | [Postives and Negatives]


167

5
Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

Examples
Example 1:
Input Format:
 N = 3, k = 5, array[] = {2,3,5}
Result:
 2
Explanation:
 The longest subarray with sum 5 is {2, 3}. And its length is 2.

Example 2:
Input Format
: N = 3, k = 1, array[] = {-1, 1, 1}
Result:
 3
Explanation:
 The longest subarray with sum 1 is {-1, 1, 1}. And its length is 3.*/
#include <iostream> 
#include<vector>
#include<map>

using namespace std;
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int i,n=a.size(),p=0,sum=0;
    map<long long,int> hash;
    for(i=0;i<n;i++){
        sum+=a[i];
        if(sum==k){
            if(i+1>p) p=i+1;
        }
        if(hash.find(sum-k)!=hash.end()){
            int j=hash[sum-k];
            if(i-j>p) p=i-j;
        }
        if(hash.find(sum)==hash.end()){
            hash[sum]=i;
        }
        
    }
    return p;
}