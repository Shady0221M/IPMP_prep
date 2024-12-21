#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int i,j,n,m=1;
        vector<vector<int>> b;

        for(i=0;i<numRows;i++){
            vector<int> a;
            n=m*11;
            m=n;
            while(n!=0){
                a.push_back(n%10);
                n=n/10;
            }
            b.push_back(a);
        }
        return b;
    }

    vector<vector<int>> generate1(int numRows) {
        int i,j;
        vector<vector<int>> b;

        for(i=0;i<numRows;i++){
            vector<int> a;
            for(j=0;j<=i;j++){
                if(j==0 || j==i){a.push_back(1);}
                else{
                    a.push_back(b[i-1][j]+b[i-1][j-1]);
                }
            }
            b.push_back(a);
        }
        return b;
    }
};
int main(){
    Solution s;
    s.generate(5);
}