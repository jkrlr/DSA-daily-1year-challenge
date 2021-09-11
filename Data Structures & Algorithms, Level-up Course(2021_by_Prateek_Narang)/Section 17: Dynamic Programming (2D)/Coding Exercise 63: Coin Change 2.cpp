// https://leetcode.com/problems/coin-change-2/
// Recursive : Time = O(m^(Sum/least value coin)), Space = O((Sum/least value coin))
// DP : Time = O(m*Sum), Space = O(m*Sum) 
 
#include<bits/stdc++.h>
using namespace std;

long long change(int Sum, vector<int> coins, int m, vector<vector<long long>>&dp){
	// base case
	if(Sum == 0){
		return 1;
	}
	if(m == 0){
		return 0;
	}
 
	// check if state is precomputed
	if(dp[m][Sum]!=-1){
		return dp[m][Sum];
	}
 
	long long include = 0, exclude = 0; 
	if(Sum >= coins[m-1]){
		include = change(Sum-coins[m-1], coins, m, dp);
	}
	exclude = change(Sum, coins, m-1, dp);
 
	return dp[m][Sum] = include + exclude;
}
 
long long findCombinations(int N, vector<int> coins){
	/* int M = coins.size();
	vector<vector<long long>>dp(M+1,vector<long long>(N+1,-1));
	return  change(N, coins, M, dp); */
 
	// Bottom-Up
	int M = coins.size();
	vector<vector<long long>>dp(M+1,vector<long long>(N+1,0));
	for(int m = 0 ; m<=M; m++){
        for(int s = 0 ; s<=N ; s++){
            if(m==0){
                dp[m][s] = 0;
             }
             if(s == 0){
                 dp[m][s] = 1;
             }
         }
    }
 
	for(int m = 1 ; m<=M; m++){
		for(int s = 1 ; s<=N ; s++){
			long long include = 0, exclude = 0;
			if(s >= coins[m-1]){
				include = dp[m][s - coins[m-1]];
			}
			exclude = dp[m-1][s];
			dp[m][s] = include + exclude;
		}
	}
	return dp[M][N];
}
