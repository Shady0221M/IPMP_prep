/*Count Maximum Consecutive One's in the array


302

9
Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

Examples:

Example 1:

Input: prices = {1, 1, 0, 1, 1, 1}

Output: 3

Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Input: prices = {1, 0, 1, 1, 0, 1} 

Output: 2

Explanation: There are two consecutive 1's in the array. */
#include <iostream> 
#include<vector>
using namespace std;
int max_cons_ones(vector<int> &arr){
    int i=0,j,p=0,n=arr.size();
    while(i<n){
        if(arr[i]==1){
            j=0;
            while(i<n && arr[i]==1) {i++;j++;}
            if(j>p) p=j;
        }else{
            while(i<n && arr[i]==0) i++;
        }
    }
    return p;

}
int main(){
    vector<int> nums={1,0,1,1,0,1};
    cout<<max_cons_ones(nums);
}