/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1*/
 #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
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