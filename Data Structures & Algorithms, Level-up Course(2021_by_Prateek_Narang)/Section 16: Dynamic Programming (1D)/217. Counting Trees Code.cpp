// https://leetcode.com/problems/unique-binary-search-trees/

// In Next Revisit - Solve this problem using Catalan Number in Time = O(N), Space = O(1)
// https://www.youtube.com/watch?v=eoofvKI_Okg
// https://www.youtube.com/watch?v=0s20L4-chDA
// https://www.youtube.com/watch?v=0pTN0qzpt-Y

 
#include<iostream>
#include<vector>
using namespace std;
 
// Recursive - Time = O(n^n) , Space = O(n)
int countBST(int n){
	// base case
	if(n==0 || n==1){
		return 1;
	}
 
	// recursive case
	int ans = 0;
	for(int i = 1; i<=n; i++){
		int leftBSTCount = countBST(i-1);
		int rightBSTCount = countBST(n-i);
		ans +=  leftBSTCount * rightBSTCount;
	}
	return ans;
}
 
// Top-Down - Time = O(n^2) , Space = O(n)
int countBSTTopDown(int n, int dp[]){
	// base case
	if(n==0 || n==1){
		return 1;
	}
 
	if(dp[n]!=0){
		return dp[n];
	}
 
	int ans = 0;
	for(int i = 1; i<=n; i++){
		int leftBSTCount = countBSTTopDown(i-1,dp);
		int rightBSTCount = countBSTTopDown(n-i,dp);
		ans +=  leftBSTCount * rightBSTCount;
	}
	return dp[n] = ans;
}
 
// Bottom-Up - Time = O(n^2), Space = O(n)
int countBSTBottomUp(int n){
	vector<int>dp(n+1,0);
	dp[0] = dp[1] = 1;
 
	for(int i=2; i<=n; i++){
		for(int j = 1; j<=i; j++){
			dp[i] += dp[j-1] * dp[i-j];
		}
	}
	return dp[n];
}
 
int main(){
	int n;
	cin>>n;
 
	int dp[n+1] = {0};
	cout<<countBST(n)<<endl;
	cout<<countBSTTopDown(n,dp)<<endl;
	cout<<countBSTBottomUp(n)<<endl;
}
