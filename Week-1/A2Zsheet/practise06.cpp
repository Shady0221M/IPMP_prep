/*Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.

Examples:

Example 1:
Input: N = 7, array[] = {1,2,3,4,5,6,7} , k=2 , right
Output: 6 7 1 2 3 4 5
Explanation: array is rotated to right by 2 position .

Example 2:
Input: N = 6, array[] = {3,7,8,9,10,11} , k=3 , left 
Output: 9 10 11 3 7 8
Explanation: Array is rotated to right by 3 position.*/
#include <iostream> 
#include<vector>
#include<algorithm>
using namespace std;
//lor==1 left ; lor==0 right
class Solution{
    public:
    vector<int> rotateArrayd(vector<int>& arr, int n,int k,int lor) {
        k=k%n;
        if (lor==0){
            reverse(arr.begin()+n-k,arr.end());
            reverse(arr.begin(),arr.begin()+n-k);
            reverse(arr.begin(),arr.end());
        }else{
            reverse(arr.begin(),arr.begin()+k);
            reverse(arr.begin()+k,arr.end());
            reverse(arr.begin(),arr.end());
        }
        return arr;
        
    }

    vector<int> rotateArrayd1(vector<int>& arr, int n,int k,int lor) {
        k=k%n;
        int*b=(int*)malloc(sizeof(int)*n);
        int i;
        if(lor==0){
            for(i=n-k;i<n;i++){
                b[i-n+k]=arr[i];
            }
            for(i=0;i<n-k;i++){
                b[i+n-k]=arr[i];
            }
        }else{
            for(i=k;i<n;i++){
                b[i-k]=arr[i];
            }
            for(i=0;i<k;i++){
                b[i+n-k]=arr[i];
            }
        }
        vector<int> ans(b,b+n);
        return ans;
        
    }
};
int main(){
    vector<int> nums={1,2,3,4,5};
    int k=2;
    Solution s;
    vector<int> b=s.rotateArrayd(nums,5,k,0);
    for(int i=0;i<5;i++){cout<<b[i]<<" ";}
}
