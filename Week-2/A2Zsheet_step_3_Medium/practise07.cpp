/*Rearrange Array Elements by Sign

Variety-1

Problem Statement:

There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

Note: Start the array with positive elements.*/
#include<iostream>
#include<vector>
using namespace std;
//O(2n) brute force separate arrays to collect positive and negatives then arrange them in a vecotr
//Space complexity O(2n)

//O(n) space and time complexity
vector<int> rearr_by_sign1(vector<int> &nums){
    int i,j,k,n=nums.size();
    vector<int> b(n,0);
    j=0;k=1;
    for(i=0;i<n;i++){
        if(nums[i]>0){b[j]=nums[i];j=j+2;}
        else{b[k]=nums[i];k=k+2;}
    }
    return b;
}

/*Variety-2
Problem Statement:
There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.

Note: Start the array with positive elements.*/
//No choice than to have two arrays fill them and then load it in new array

//O(2n)-Time complexity
//space complexity-O(2n)
void print_vector(vector<int> &nums){
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
    cout<<endl;
}
vector<int> rearr_by_sign(vector<int> &nums){
    int i,j,k,n=nums.size();
    vector<int> pos,neg;
    vector<int> b;
    j=0;k=1;
    for(i=0;i<n;i++){
        if(nums[i]>0){pos.push_back(nums[i]);}
        else{neg.push_back(nums[i]);}
    }
    print_vector(pos);
    print_vector(neg);
    if(pos.size()<neg.size()){
        for(i=0;i<pos.size();i++){
            b.push_back(pos[i]);
            b.push_back(neg[i]);
        }
        for(i=pos.size();i<neg.size();i++){
            b.push_back(neg[i]);
        }
    }else{
        for(i=0;i<neg.size();i++){
            b.push_back(pos[i]);
            b.push_back(neg[i]);
        }
        for(i=neg.size();i<pos.size();i++){
            b.push_back(pos[i]);
        }
    }
    print_vector(b);
    return b;
}

int main(){
    vector<int> nums={1,2,-4,-5,3,4};
    vector<int> b=rearr_by_sign(nums);
    for(int i=0;i<nums.size();i++) cout<<b[i]<<" ";
}