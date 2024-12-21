#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    //O(1)-space complexity   O(n) time complexity
    int majorityElement(vector<int>& nums) {
        //Moore's voting algorithm
        int m=nums[0],n=nums.size();
        int freq=0;
        for(int i=0;i<n;i++){
            if(nums[i]==m){
                freq++;
            }else{
                freq--;
                if(!freq){
                    m=nums[i+1];
                }
            }
        }        
        //if a majority (i.e. freq>n/2 appears it must be m else it doesnt exist)
        //to confirm m-majority
        freq=0;
        for(int i=0;i<n;i++){
            if(nums[i]==m) freq++;
        }
        if(freq>n/2) return m;
        else return -1;//indicating absence of an element appearing more than n/2 times
    }
    //O(nlogn)-time complexity-using hashing(map)
    int majorityElement1(vector<int>& nums) {
        map<int,int> a;
        int i,n=nums.size();
        for(i=0;i<n;i++){
            a[nums[i]]++;
        }
        int m=nums[0];
        cout<<m<<endl;
        cout<<a[m]<<endl;
        for(auto it:a){
            cout<<it.first<<"  "<<it.second<<endl;
            if(it.second>n/2) m=it.first;
        }
        return m;
    }
};
int main(){
    vector<int> nums={3,2,3,3,5,3};
    Solution s;
    cout<<s.majorityElement(nums);
}