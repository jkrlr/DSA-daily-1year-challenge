// Time = O(n*k), Space = O(n)

#include<bits/stdc++.h>
using namespace std;
 
long long minimumCost(vector<int> stones, int k){
    int n = stones.size();
	vector<long long>dp(n,INT_MAX);
	dp[0] = 0;
	for(int i = 1; i<n; i++){
		for(int jump = 1; jump<=k; jump++){
			if(i-jump>=0){
				dp[i] = min(dp[i], abs(stones[i]-stones[i-jump]) + dp[i-jump]);
			}
		}
	}
	return dp[n-1];
}
