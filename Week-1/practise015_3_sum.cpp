#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>


using namespace std;
class Solution {
public:
//two pointer approach since one positive and one negative value(or both zeroes) 
//should always be there(i starts from 0, k starts fron n-1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> b;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j,k;
        while(i<n){
            j=i+1;
            k=n-1;
            
                while(j<k){
                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum==0){
                        b.push_back(vector<int> {nums[i], nums[j], nums[k]});
                        cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                        int z=nums[j];
                        while(j<k && z==nums[j]){j++;}
                        z=nums[k];
                        while(j<k && z==nums[k]){k--;}
                    }else if(sum<0){int z=nums[j];
                        while(j<k && z==nums[j]){j++;}}
                    else{
                        int z=nums[k];
                        while(j<k && z==nums[k]){k--;}
                    }
                    
                }
            
            int y=nums[i];
            while(y==nums[i]){i++;}
        }
        return b;
    }

    //O(n^2logn) reduced time complexity-uing hash map 
    //Space complexity O(2*(no.of unique triplets+n))
    // n-extra space for hash set
    vector<vector<int>> threeSum2(vector<int>& nums) {
        set<vector<int>> s;
        int i,j,n=nums.size();
        for(i=0;i<n;i++){
            set<int> a;
            for(j=i+1;j<n;j++){
                
                if(a.find(-(nums[i]+nums[j]))!=a.end()){
                    vector<int> b={nums[i],nums[j],-(nums[i]+nums[j])};
                    sort(b.begin(),b.end());
                    s.insert(b);
                }
                a.insert(nums[j]);
                
            }
        }
        //copy contents of set into finl vector<vector<int>>
        vector<vector<int>> c(s.begin(),s.end());
        return c;
    }
    //O(n^3logn) time complexity--Space(2O(no. of unique triplets))
    vector<vector<int>> threeSum1(vector<int>& nums) {
        int i,j,k,n=nums.size();
        vector<vector<int>> b;
        set<vector<int>> s;
        vector<int> a;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                for(k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        a={nums[i], nums[j], nums[k]};
                        sort(a.begin(),a.end());
                        s.insert(a);
                    }
                }
            }
        }
        for(auto it:s){
            b.push_back(it);
        }
        return b;
    }
};
int main(){
    vector<int> nums={0,0,0};
    Solution s;
    vector<vector<int>> b=s.threeSum(nums);
}
