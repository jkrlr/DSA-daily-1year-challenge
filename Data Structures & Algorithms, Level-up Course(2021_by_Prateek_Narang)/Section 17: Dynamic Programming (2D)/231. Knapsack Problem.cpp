// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

#include<iostream>
#include <cstring>
using namespace std;
 
// Recursive : Time = O(2^N), Space = O(N)
int knapSack(int prices[], int wts[], int N, int W){
	// base case
	if(N==0 || W==0){
		return 0;
	}
 
	// recursive case
	if(W >= wts[N-1]){
		int includeItem = prices[N-1] + knapSack(prices, wts, N-1, W-wts[N-1]);
		int excludeItem = 0 + knapSack(prices, wts, N-1, W);
		return max(includeItem, excludeItem);
	}
	else{
		return knapSack(prices, wts, N-1, W);
	}
}
 
// Top-Down : Time = O(N*W), Space = O(N*W)
int dp[1001][1001];
int knapSackTD(int prices[], int wts[], int N, int W){
	// base case
	if(N==0 || W==0){
		return 0;
	}
 
	// check if state is precomputed
	if(dp[N][W]!= -1){
		return dp[N][W];
	}
 
	if(W >= wts[N-1]){
		int includeItem = prices[N-1] + knapSackTD(prices, wts, N-1, W-wts[N-1]);
		int excludeItem = 0 + knapSackTD(prices, wts, N-1, W);
		return dp[N][W] = max(includeItem, excludeItem);
	}
	else{
		return dp[N][W] = knapSackTD(prices, wts, N-1, W);
	}
}
 
// Bottom-Up : Time = O(N*W), Space = O(N*W)
int knapSackBU(int prices[], int wts[], int N, int W){
	int dp[N+1][W+1];
 
	// Initialization
	for(int n=0; n<=N; n++){
		for(int w=0; w<=W; w++){
			if(n==0 || w==0){
				dp[n][w] = 0;
			}
		}
	}
 
	// Bottom Up
	for(int n=1; n<=N; n++){
		for(int w=1; w<=W; w++){
			if(w >= wts[n-1]){
				int includeItem = prices[n-1] + dp[n-1][w-wts[n-1]];
				int excludeItem = dp[n-1][w];
				dp[n][w] = max(includeItem, excludeItem);
			}
            else{
                dp[n][w] = dp[n-1][w];
            }
		}
	}
	return dp[N][W];
}
 
// Bottom-Up - Space Optimized : Time = O(N*W), Space = O(W)
// knowing that fact - current row depends upon previous row only
int knapSackBUOptimized(int prices[], int wts[], int N, int W){
	int dp[2][W+1];
	memset(dp,0,sizeof(dp));
 
	// Bottom Up
	for(int n=1; n<=N; n++){
		for(int w=1; w<=W; w++){
			if(w >= wts[n-1]){
				int includeItem = prices[n-1] + dp[0][w-wts[n-1]];
				int excludeItem = dp[0][w];
				dp[1][w] = max(includeItem, excludeItem);
			}
            else{
                dp[1][w] = dp[0][w];
            }
		}
 
		// store the 1st row value into 0th row for next iteration calculation
		for(int w=1; w<=W; w++){
			dp[0][w] = dp[1][w];
		}
	}
	return dp[1][W];
}
 
int main(){
	int wts[] = {2,7,3,4};
	int prices[] = {5,20,20,10};
	int N = 4;
	int W = 11;
 
	// Recursive
	cout<<knapSack(prices,wts,N,W)<<endl;
	
	// Top-Down
	memset(dp,-1, sizeof(dp));
	cout<<knapSackTD(prices,wts,N,W)<<endl;
 
	// Bottom-Up
	cout<<knapSackBU(prices,wts,N,W)<<endl;
 
	// Bottom-Up Optimized
	cout<<knapSackBUOptimized(prices,wts,N,W)<<endl;
}
