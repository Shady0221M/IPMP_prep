/*Majority Elements(&gt;N/3 times) | Find the elements that appears more than N/3 times in the array

Problem Statement: Given an array of N integers. 
Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.*/

#include<climits>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> majorityElement(vector<int> v) {
	vector<int> b;
	int el1=INT_MIN,el2=INT_MIN,count1,count2;
	count1=0;
	count2=0;
	int k=(floor(((double)v.size())/3));
	for(int i=0;i<v.size();i++){
		if(count1==0 && v[i]!=el2){el1=v[i];count1=1;}
		else if(count2==0 && v[i]!=el1){el2=v[i];count2=1;}
		else if(v[i]==el1) count1++;
		else if(v[i]==el2) count2++;
		else {count1--;count2--;}
	}
	count1=0;count2=0;
	for(int i=0;i<v.size();i++){
		if(v[i]==el1) count1++;
		else if(v[i]==el2) count2++;
	}
	if(count1>k && count2>k){b.push_back(el1);b.push_back(el2);sort(b.begin(),b.end());}
	else if(count1>k){b.push_back(el1);}
	else if(count2>k){b.push_back(el2);}
	
	return b;
}