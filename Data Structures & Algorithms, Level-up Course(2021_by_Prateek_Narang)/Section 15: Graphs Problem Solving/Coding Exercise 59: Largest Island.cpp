// https://leetcode.com/problems/max-area-of-island/
// Time = O(mxn), Space = O(mxn)

// Implicit 2D-Graph

#include<bits/stdc++.h>
using namespace std;
 
int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int m, int n){
	visited[row][col] = true;
    int currSize = 1;
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    for(int k = 0; k<4; k++){
        int nRow = row + dx[k];
        int nCol = col + dy[k];
    
        if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && !visited[nRow][nCol] && grid[nRow][nCol]==1){
            int subComponent = dfs(grid, visited, nRow, nCol, m, n);
            currSize += subComponent;
        }
    }
    return currSize;
}
 
int largest_island(vector<vector<int> > grid){    
    int largest = 0;
	int m = grid.size();
	int n = grid[0].size();
 
	vector<vector<bool>> visited(m, vector<bool>(n,false));
	
	// 4-way dfs
	for(int row = 0; row<m; row++){
		for(int col = 0; col<n; col++){
			if(grid[row][col]==1 && visited[row][col]==false){
				int currSize = dfs(grid,visited,row,col,m,n);
				largest = max(currSize, largest);
			}
		}
	}
	return largest;
}
