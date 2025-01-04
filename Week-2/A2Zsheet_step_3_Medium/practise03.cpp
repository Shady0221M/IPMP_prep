/*Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.*/
//Already done in leetcode
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
//Some spl algo
int majorityElement(vector<int> v) {
	int k=v[0],freq=1;
	int i,n=v.size();
	for(i=1;i<n;i++){
		if(v[i]==k) freq++;
		else{
				freq--;
				if(freq==0){
					k=v[i+1];
					freq=0;
				}
		}
	}
	return k;
}