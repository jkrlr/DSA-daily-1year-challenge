#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 
// Top - Down  - Time = O(N*T), Space = O(N)
int minNumberOfCoinsForChangeTD(int n, vector<int> denoms, vector<int> &dp){
    // base case
    if(n==0){
        return 0;
    }
    
    // check if value is precomputed
    if(dp[n]!=0){
        return dp[n];
    }

    dp[n] = INT_MAX-1;	// Not used INT_MAX(2147483647) because if the coin can't change then 1 + subProblem becomes -2147483648 causes overflow
    for (int coin : denoms){
        if(n-coin>=0 && dp[n-coin]!=INT_MAX-1){
            int subProblem = minNumberOfCoinsForChangeTD(n-coin, denoms,dp);
            dp[n] = min(dp[n], 1 + subProblem);
        }
    }
    return dp[n];
}
 
// Bottom - UP  - Time = O(N*T), Space = O(N)
int minNumberOfCoinsForChangeBU(int n, vector<int> denoms){
    vector<int> dp(n+1,0);
    dp[0] = 0;
 
    for(int i = 1; i<=n; i++){
        dp[i] = INT_MAX;

        for(int coin : denoms){    
            if(i-coin>=0 && dp[i-coin]!=INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i-coin]);
            }
        }
    }
    return dp[n] == INT_MAX ? -1 : dp[n];
}
 
int main(){
	int n = 15;
	vector<int> denoms = {1, 3, 7, 10};
	vector<int> dp(n+1,0);
	cout<<minNumberOfCoinsForChangeTD(n,denoms, dp)<<endl;
	cout<<minNumberOfCoinsForChangeBU(n,denoms)<<endl;
}