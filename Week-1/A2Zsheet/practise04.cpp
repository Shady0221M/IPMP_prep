/*Remove Duplicates in-place from Sorted Array


454

18
Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

Note: Return k after placing the final result in the first k slots of the array.*/

#include <iostream> 
#include<vector>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	int z,i=0,j=0;
	while(i<n){
		if(i+1<n && arr[i]==arr[i+1]){
			int z=arr[i];
			while(i<n && z==arr[i]) i++;
			j++;
			
		}else{
			i++;j++;
		}
	}
	return j;

}