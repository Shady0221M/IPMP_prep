#include<iostream>
#include<vector>
#include<map>
using namespace std;
void merge(vector<vector<int>> &nums,int l,int u){
    int mid=(l+u)/2;
    int i,j,k=0,n=u-l+1;
    i=l;
    j=mid+1;
    vector<vector<int>> b;
    while(i<=mid && j<=u){
        if(nums[i]<nums[j]){b.push_back(nums[i++]);}
        else{b.push_back(nums[j++]);}
    }
    while(i<=mid){
        b.push_back(nums[i++]);
    }
    while(j<=u){
        b.push_back(nums[j++]);
    }
    for(i=0;i<n;i++){
        nums[l+i]=b[i];
    }
}
void mergesort(vector<vector<int>> &nums,int l,int u){
    if(l<u){
        int mid=(l+u)/2;
        mergesort(nums,0,mid);
        mergesort(nums,mid+1,u);
        merge(nums,l,u);
    }
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map1;
        int j,i;
        int n=nums.size();
        for(i=0;i<n;i++){
        map1[nums[i]]=i;
        } 
        for(i=0;i<n;i++){
        int comp=target-nums[i];
        if(map1.find(comp)!=map1.end() && map1[comp]!=i){
            break;
        }
        }
        return vector<int>{i,map1[target-nums[i]]};
    }
    vector<int> twoSum1(vector<int>& num, int target) {
        cout<<"Hello";
        vector<vector<int>> nums;
        int i,j;
        int n=num.size();
        for(i=0;i<n;i++){
            nums.push_back({num[i],i});
            // nums[i]={num[i],i};
        }
        for(i=0;i<n;i++){
            for(j=0;j<2;j++){
                cout<<nums[i][0]<<" "<<nums[i][1]<<endl;
            }
        }
        i=0,j=nums.size()-1;
        mergesort(nums,0,j);
        while(i<j){
            if(nums[i][0]+nums[j][0]==target){break;}
            else if(nums[i][0]+nums[j][0]<target){
                i++;
            }else j--;
        }
        return vector<int>{nums[i][1],nums[j][1]};
    }
};
int main(){
    Solution s;
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> ans=s.twoSum1(nums,target);
    cout<<"[";
    cout<<ans[0]<<","<<ans[1];
    cout<<"]";
    
}