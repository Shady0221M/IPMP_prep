#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
    void formNQueeens(int row,vector<vector<string>> &array,vector<int> &column,vector<int> &ld, vector<int> &rd,int n,vector<string> &dummy){
        if(row==n){
            array.push_back(dummy);
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    cout<<dummy[i][j]<<" ";
                }cout<<"   ";
            }
            dummy.clear();
            cout<<"Hi!!\n";
            return;
        }
        for(int i=0;i<n;i++){
            if(column[i] || rd[i+row] || ld[row-i+n-1]) continue;
            column[i]=1;rd[i+row]=1;ld[row-i+n-1]=1;
            string s;
            for(int j=0;j<n;j++){
                if(j==i){s.push_back('Q');}
                else{s.push_back('.');}
            }
            dummy.push_back(s);
            s.clear();
            formNQueeens(row+1,array,column,ld,rd,n,dummy);
            column[i]=0;rd[i+row]=0;ld[row-i+n-1]=0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> array;
        vector<string> dummy;
        vector<int> ld(2*n-1),rd(2*n-1),column(n);
       formNQueeens(0,array,column,ld,rd,n,dummy);
       return array; 
    }
};

int main(){
    Solution s;
    vector<vector<string>> p=s.solveNQueens(4);
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                cout<<p[i][j][k]<<" ";
            }
            cout<<"    ";
        }
        cout<<endl;
    }
}