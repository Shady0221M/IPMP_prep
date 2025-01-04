/*Spiral Traversal of Matrix

Problem Statement: Given a Matrix, print the given matrix in spiral order.*/

 #include<iostream>
#include<vector>
#include<algorithm>
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