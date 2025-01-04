/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
bool search(vector<vector<char>>& board,int i,int j, string &word,vector<vector<int>>&b,int l){
    bool p=false;
    int m=board.size();
    int n=board[0].size();
    if(i-1>=0){
        if(board[i-1][j]==word[l] && !b[i-1][j]){
            if   (l==word.size()-1) p=true;
            else {  b[i-1][j]=1;
                    p=search(board,i-1,j,word,b,l+1);
                    b[i-1][j]=0;
                }
        }
    }
    if(i+1<m && !p){
        if(board[i+1][j]==word[l] && !b[i+1][j]){
            if   (l==word.size()-1) p=p||true;
            else {
                    b[i+1][j]=1;
                    p=p||search(board,i+1,j,word,b,l+1);
                    b[i+1][j]=0;
                }
        }
    }if(j-1>=0  && !p){
        if(board[i][j-1]==word[l] && !b[i][j-1]){
            if   (l==word.size()-1) p=p||true;
            else {
                    b[i][j-1]=1;
                    p=p||search(board,i,j-1,word,b,l+1);
                    b[i][j-1]=0;
                }
        }
    }if(j+1<n && !p){
        if(board[i][j+1]==word[l] && !b[i][j+1]){
            if   (l==word.size()-1) p=p||true;
            else {
                    b[i][j+1]=1;
                    p=p||search(board,i,j+1,word,b,l+1);
                    b[i][j+1]=0;
                }
        }
    }
    return p;
}
    bool exist(vector<vector<char>>& board, string word) {
        int i,j,m,n,p,l;
        m=board.size();
        n=board[0].size();
        vector<vector<int>> b(m,vector<int> (n,0));
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    cout<<endl;
                    cout<<"started"<<endl;
                    l=0;
                    b[i][j]=1;
                    if(l==word.size()-1) return true;
                    p=search(board,i,j,word,b,l+1);
                    if(p==1){return true;}
                    b[i][j]=0;
                }
            }
        }
        return false;
    }
};