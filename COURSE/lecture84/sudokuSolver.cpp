#include<iostream>
#include <vector>
using namespace std;



bool safe(int row, int col, vector<vector<int>>& board, int value){
    for(int i=0; i<9; i++){
        if (board[row][i] == value) return false;
        if (board[i][col] == value) return false;
        if (board[3*(row/3)+i/3][3*(col/3)+i%3] == value) return false;
    }
    return true;
}


bool solve(vector<vector<int>>& board){
    for(int row = 0; row < 9; row++){
        for(int col =0; col<9; col++){
            if (board[row][col] == 0){
                for(int i=1; i<=9; i++){
                    if (safe(row, col, board, i)){
                        board[row][col] = i;
                        if (solve(board)){
                            return true;
                        }
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}



void solveSudoku(vector<vector<int>>& sudoku){
  solve(sudoku)  ;
}