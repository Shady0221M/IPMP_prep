#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>

using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> b;
        int i,k,j;
        int n=nums.size();
        b.push_back(nums[0]);
        for(i=1;i<n;i++){
            b.push_back(nums[i]);
            nums[i]=nums[i-1]*nums[i];
        }
        
        for(i=0;i<n;i++){cout<<b[i]<<" ";}
        cout<<endl;
        for(i=0;i<n;i++){cout<<nums[i]<<" ";}
        cout<<endl;
        
        nums[n-1]=b[n-1];
        b[n-1]=nums[n-2];
        i=n-2;
        while(i>0){
            k=b[i];
            b[i]=nums[i-1]*nums[i+1];
            nums[i]=nums[i+1]*k;
            i--;
            for(j=0;j<n;j++){cout<<b[j]<<" ";}
            cout<<endl;
            for(j=0;j<n;j++){cout<<nums[j]<<" ";}
            cout<<endl;
            cout<<endl;
        }
        b[0]=nums[1];
        return b;
    }
    vector<int> productExceptSelf1(vector<int>& nums) {
        vector<int> pre;
        int n=nums.size();
        int *suf=(int*)malloc(sizeof(int)*n);
        pre.push_back(nums[0]);
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre.push_back(nums[i]*pre[i-1]);
            suf[n-i-1]=nums[n-1-i]*suf[n-i];
        }
        vector<int> ans;
        ans.push_back(suf[1]);
        for(int i=1;i<n-1;i++){
            ans.push_back(pre[i-1]*suf[i+1]);
        }
        ans.push_back(pre[n-2]);
        return ans;
    }
};

int main(){
    vector<int> nums={1,2,3,4,5,6};
    Solution s;
    vector<int> b=s.productExceptSelf(nums);
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
}