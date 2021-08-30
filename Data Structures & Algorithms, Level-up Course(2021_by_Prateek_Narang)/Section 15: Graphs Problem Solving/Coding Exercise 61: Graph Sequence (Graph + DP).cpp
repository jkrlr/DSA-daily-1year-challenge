// Implicit 2D-Graph
// DP - optimal substructure + overlapping subproblems
// Time = O(MxN), Space = O(MXN)


/* 
4-way dfs at every cell
store what is maxlen
reused when currenSource as subproblem
*/


#include<bits/stdc++.h>
using namespace std;
 
int dfs(vector<vector<int> > &matrix, vector<vector<int> > &dp, int row, int col, int m, int n){
	if(dp[row][col]!=-1){
		return dp[row][col];
	}
 
	int path  = 1;
	
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
 
	int nbrsPathMax = 0;
	for(int k = 0; k<n; k++){
		int nRow = row + dx[k];
		int nCol = col + dy[k];
 
		if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && matrix[row][col]<matrix[nRow][nCol]){
			int nbrPath = dfs(matrix,dp,nRow,nCol,m,n);
			nbrsPathMax = max(nbrsPathMax, nbrPath);
		}
	}
	
	path += nbrsPathMax;
	return dp[row][col] = path;
}
 
int longestPathSequence(vector<vector<int> > matrix){
    // Hint : You may need to use DP, to store the longestPath length for already visited 'states'
  	int m = matrix.size();
	int n = matrix[0].size();
 
    vector<vector<int>> dp(m, vector<int>(n,-1));
	int longest  = 0;
	for(int row = 0; row<m; row++){
		for(int col = 0; col<n; col++){
			int path = dfs(matrix,dp,row,col,m,n);
			longest = max(longest, path);
		}
	}
 
	return longest;
}
