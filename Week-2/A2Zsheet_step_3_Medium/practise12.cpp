/*Rotate Image by 90 degree

Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.*/
//Done in leetcode already
 #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),i,j;
        int temp;
        for(i=1;i<n;i++){
            for(j=0;j<i;j++){
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};