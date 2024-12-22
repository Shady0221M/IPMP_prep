#include<iostream>
#include<vector>
#include<algorithm>//we get sort function on vectors

using namespace std;
class Solution {
public:
int max(int a,int b){
        return (a>b)?a:b;
    }
    void merge1(vector<vector<int>> &nums,int l,int u){
        int mid=(l+u)/2;
        int i=l,j=mid+1;
        vector<vector<int>> b;
        while(i<=mid && j<=u){
            if(nums[i][0]<nums[j][0]){
                b.push_back(nums[i++]);
            }else if(nums[i][0]==nums[j][0]){
                if(nums[i][1]<nums[j][1]){
                    b.push_back(nums[i++]);
                }else{
                    b.push_back(nums[j++]);
                }
            }else{
                b.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            b.push_back(nums[i++]);
        }
        while(j<=u){
            b.push_back(nums[j++]);
        }
        for(i=0;i<(u-l+1);i++){
            nums[l+i]=b[i];
        }
    }
    void mergesort(vector<vector<int>> &nums,int l,int u){
        if(l<u){
            int mid=(l+u)/2;
            mergesort(nums,l,mid);
            mergesort(nums,mid+1,u);
            merge1(nums,l,u);
        }
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        //mergesort(intervals,0,n-1);
        vector<vector<int>> b;
        b.push_back(intervals[0]);
        int k=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=b[k][1]){b[k][1]=max(intervals[i][1],b[k][1]);}
            else{b.push_back(intervals[i]);k++;}
        }
        return b;
    }
};
int main(){
    vector<vector<int>> nums={{1,3},{2,6},{8,10},{15,18}};
    Solution s;
    vector<vector<int>> b=s.merge(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i][0]<<" "<<nums[i][1]<<endl;
    }
}