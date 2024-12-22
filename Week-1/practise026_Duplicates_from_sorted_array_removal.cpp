#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0,k=0,n=nums.size();
        while(i<n && j<n){
            if(i+1<n && nums[i]==nums[i+1]){
                j=i+1;
                while(j<n && (nums[j]==nums[i]) )   {j++;}
                nums[k++]=nums[i];
                if(j!=n){i=j;}
            }else{
                    nums[k++]=nums[i++];
                
                
            }
            
        }
        return k;
        
    }
};
int main(){
    Solution s;
    vector<int> nums={1,1,2};
    int k=s.removeDuplicates(nums);
    cout<<k<<endl;
    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }
}