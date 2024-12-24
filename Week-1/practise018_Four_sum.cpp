#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>

using namespace std;
class Solution {
public:

    //O(n^3)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i=0,j,k,l;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> b;
        for(i=0;i<n-3;){
            for(j=i+1;j<n-2;){
                k=j+1;
                l=n-1;
                set<int> s;
                while(k<l){
                    long long int sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        b.push_back({nums[i],nums[j],nums[k],nums[l]});
                        cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<" "<<nums[l]<<endl;
                        int z=nums[k];
                        while(k<l && nums[k]==z) k++;
                        z=nums[l];
                        while(k<l && z==nums[l]) l--;
                    }else if(sum<target){
                        int z=nums[k];
                        while(k<l && nums[k]==z) k++;
                    }
                    else{
                        int z=nums[l];
                        while(k<l && nums[l]==z) l--;
                    }
                }
                int y=nums[j];
                while(j<n-2 && y==nums[j]) {j++;}
            }
            int y=nums[i];
            while(i<n-3 && y==nums[i]) {i++;}
            
        }
        return b;
    }

    //O(n^4)
    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        int i,j,k,l;
        int n=nums.size();
        set<vector<int>> s;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                for(k=j+1;k<n;k++){
                    for(l=k+1;l<n;l++){
                        int sum=nums[i]+nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        if(sum==target){
                            vector<int> a={nums[i],nums[j],nums[k],nums[l]};
                            sort(a.begin(),a.end());
                            s.insert(a);
                        }
                    }
                }
            }
        }
        vector<vector<int>> b(s.begin(),s.end());
        return b;
    }
    
};

int main(){
    vector<int> nums={1,0,-1,0,-2,2};
    int target=0;
    Solution s;
    vector<vector<int>> b=s.fourSum(nums,target); 
    cout<<b.size();
}