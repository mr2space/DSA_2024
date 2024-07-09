#include <bits/stdc++.h> 
using namespace std;


void saveResult(vector<vector<bool>>& board, vector<vector<int>>& ans, int n){
    vector<int> temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}


unordered_map<int, bool> rowmap, updia, downdia;

bool isSafe(int col,int row, vector<vector<bool>>& board, int n ){
    if(rowmap[row]) return false;
    if(downdia[row+col]) return false;
    if(updia[(n-1)+(col-row)]) return false;
    return true;
}




void solve(int col, vector<vector<bool>>& board, int n,  vector<vector<int>>& ans){
    if (col == n){
        saveResult(board, ans, n);
        return ;
    }

    for(int row=0; row<n; row++){
        if (isSafe(col, row, board, n)){
            board[col][row] = 1;
            rowmap[row] = 1;
            updia[(n-1)+(col-row)] = 1;
            downdia[row+col] =1;
            solve(col+1, board, n, ans);
            board[col][row] = 0;
            rowmap[row] = 0;
            updia[(n-1)+(col-row)] = 0;
            downdia[row+col] = 0;
        }
    }
}



vector<vector<int>> nQueens(int n)
{
    vector<vector<bool>> board(n, vector<bool>(n, 0));
    vector<vector<int>> ans;

    solve(0, board, n, ans);
    return ans;
}