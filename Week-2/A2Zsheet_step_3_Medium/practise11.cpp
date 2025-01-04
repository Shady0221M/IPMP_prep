/* Set Matrix Zero


Problem Statement: Given a matrix if an element 
in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.*/
 #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
//Using first row and first col as marker + additional marker as row0,then based on that marking every element 0
//Complexity 
//time-O(mn)
//spaceO(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j,k,m=matrix.size(),n=matrix[0].size();
        int row0=-1;
        
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(i==0 && matrix[0][j]==0) row0=0;
                else{
                    if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
                }
                
            }
        }
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                if(!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j]=0;
                }
            }
        }
        if(!matrix[0][0]){for(i=0;i<m;i++){
            matrix[i][0]=0;
        }}
        if(row0==0){
            for(i=0;i<n;i++){matrix[0][i]=0;}
        }
    }

//Better-using two arrays as marker for rows and columns
//Complexity time-O(mn)     space-O(m+n)
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j,k,m=matrix.size(),n=matrix[0].size();
        vector<int> row(m,0);
        vector<int> col(n,0);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;col[j]=1;
                }
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
//Brute force O(mn(m+n)) -time .space-O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j,k,m=matrix.size(),n=matrix[0].size();
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(matrix[i][j]==0){
                    for(k=0;k<m;k++){
                        if(matrix[k][j]!=0) matrix[k][j]=-1;
                    }
                    for(k=0;k<n;k++){
                        if(matrix[i][k]!=0) matrix[i][k]=-1;
                    }
                    matrix[i][j]=-1;
                }
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(matrix[i][j]==-1){matrix[i][j]=0;}
            }
        }
    }
};