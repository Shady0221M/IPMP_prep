/*Linear Search in C


145

7
Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

Examples:

Example 1:
Input: arr[]= 1 2 3 4 5, num = 3
Output: 2
Explanation: 3 is present in the 2nd index

Example 2:
Input: arr[]= 5 4 3 2 1, num = 5
Output: 0*/
#include <iostream> 
#include<vector>
#include<algorithm>
using namespace std;
int linear_search(vector<int> arr,int num){
    int i=0,n=arr.size();
    while(i<n){
        if(arr[i]==num){return i;}
        i++;
    }
    return -1;
}