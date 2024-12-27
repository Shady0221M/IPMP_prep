/*Longest Subarray with given Sum K(Positives)
558

7
Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

Examples
Example 1:
Input Format: N = 3, k = 5, array[] = {2,3,5}
Result: 2
Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

Example 2:
Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
Result: 3
Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.*/
#include <iostream> 
#include<vector>
#include<map>
using namespace std;
int longestSubarrayWithSumK(vector<int> &a, long long k) {
    int i,j,n=a.size(),s,sum=0,p=0;
    i=0,s=0;
    while(i<n){
        if(a[i]>k){
            sum=0;
            if(1>p){p=1;}
        }
        else{
            sum+=a[i];
            if(sum==k){
                if(i-s+1>p){
                    p=(i-s+1);
                }
            }else if(sum>k){
                while(sum>k && s<=i){
                    sum-=a[s++];
                    if(sum==k){
                        if(i-s+1>p){
                            p=(i-s+1);
                        }
                    }
                
                }
            }
        }
        i++;
        //cout<<sum<<endl;
    }
    return p;
}
//O(n)
int longestSubarrayWithSumK3(vector<int> a, long long k) {
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
//O(n^2)
int longestSubarrayWithSumK2(vector<int> a, long long k) {
    int i,j,n=a.size(),p=0;
    for(i=0;i<n;i++){
        int sum=0;
        for(j=i;j<n;j++){
            sum+=a[j];
            if(sum==k && (j-i+1)>p){p=(j-i+1);}
        }
    }
    return p;
}
//O(n^3)
int longestSubarrayWithSumK1(vector<int> a, long long k) {
    // Naive method
    int i,j,n=a.size(),p=0;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++) sum+=a[k];
            if(sum==k && (j-i+1)>p){p=j-i+1;}
        }
    }
    return p;
}
int main(){
    vector<int> nums={1,2,3,1,1,1,1};
    cout<<longestSubarrayWithSumK(nums,3)<<endl;
}