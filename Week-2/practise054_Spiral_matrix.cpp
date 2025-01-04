/*Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> b;
        int i,j,m=matrix.size(),n=matrix[0].size(),s;
        s=(m<n)?m:n;
        for(i=0;i<s/2;i++){
            for(j=i;j<n-i;j++){
                b.push_back(matrix[i][j]);
            }
            for(j=i+1;j<m-i-1;j++){
                b.push_back(matrix[j][n-1-i]);
            }
            for(j=n-i-1;j>=i;j--){
                b.push_back(matrix[m-i-1][j]);
            }
            for(j=m-i-2;j>i;j--){
                b.push_back(matrix[j][i]);
            }
        }
        if(s%2==0){return b;}
        if(s==m){
            for(j=s/2;j<n-s/2;j++){
                b.push_back(matrix[s/2][j]);
            }
        }else{
            for(j=s/2;j<m-s/2;j++){
                b.push_back(matrix[j][s/2]);
            }
        }
        return b;
    }
};