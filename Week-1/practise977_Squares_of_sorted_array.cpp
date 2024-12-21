#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
//To furthur decrease go from first non negative numberi,j then go to end.
//Now I've used sliding window approach
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> b;
        int i=0,j=nums.size()-1;
        int n=nums.size();
        while(i<j){
            if(nums[i]*nums[i]<=nums[j]*nums[j]){
                b.push_back(nums[j]*nums[j--]);
            }
            else{
                b.push_back(nums[i]*nums[i++]);
            }
        }
        b.push_back(nums[j]*nums[j]);
        for(i=0;i<n/2;i++){
            j=b[i];
            b[i]=b[n-i-1];
            b[n-i-1]=j;
        }
        return b;

    }
};

int main(){
    vector<int> nums={-4,-1,0,3,10};
    Solution s;
    vector<int> ans=s.sortedSquares(nums);
    for(int i=0;i<ans.size();i++){cout<<ans[i]<<",";};
}