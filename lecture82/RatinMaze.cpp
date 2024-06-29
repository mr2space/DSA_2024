#include<iostream>
#include <bits/stdc++.h> 
using namespace std;



void maze(int i, int j,vector<vector<int>>& arr, int n,vector<vector<bool>>& visited , string temp, vector<string>& ans){
    if (i < 0 || i >= n) return ;
    if (j < 0 || j >= n) return ;
    if (visited[i][j] != 0) return ;
    if (arr[i][j] == 0) return ;
    if (i == n-1  &&  j==n-1){
        ans.push_back(temp);
        return ;
    }

    visited[i][j]= 1;
    //down
    maze(i+1,j, arr, n, visited, temp+"D", ans);
    //left
    maze(i,j-1, arr, n, visited, temp+"L", ans);
    //right
    maze(i,j+1, arr, n, visited, temp+"R", ans);
    //up
    maze(i-1,j, arr, n, visited, temp+"U", ans);

    visited[i][j] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string temp = "";
    maze(0,0,arr, n, visited, temp, ans);
    return ans;
}


int main(){
    vector<vector<int>> arr = {{1,0},{1,1}};
    vector<string> a = searchMaze(arr, 2);
    for(int i=0; i < a.size(); i++){
        cout << a[i] << endl;
    }
    return 0;
}


