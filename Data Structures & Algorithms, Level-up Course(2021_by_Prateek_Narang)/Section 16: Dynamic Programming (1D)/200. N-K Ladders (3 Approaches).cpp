#include<iostream>
using namespace std;
 
// Recursive - Time = (k^N), Space = O(N)
int countWays(int n, int k){
	// base case
	if(n==0 || n==1){
		return 1;
	}
 
	// recursive case
	int ans = 0;
	for(int jump=1; jump<=k;jump++){
		if(n-jump>=0){
			ans += countWays(n-jump, k);
		}
	}
	return ans;
}
 
// Top-Down - Time = (k*N), Space = O(N)
int countWays(int n, int k, int dp[]){
	// check if state is already computed
    if(dp[n]!=0){
		return dp[n];
	}
	
	for(int jump = 1; jump<=k; jump++){
		if(n-jump>=0){
			dp[n] += countWays(n-jump,k,dp);
		}
	}
	return dp[n];
}
 
 
// Bottom-Up - Time = (k*N), Space = O(N)
int countWays(int n, int k){
	int dp[n+1] = {0};
	dp[0] = dp[1] = 1;
 
	for(int i = 2 ; i<=n; i++){
		for(int jump = 1; jump<=k; jump++){
			if(i-jump>=0){
				dp[i] += dp[i-jump];
			}
		}
    }
    return dp[n]; 
}
 
// Bottom-Up(Optimized-Recurrence) - Time = (N+k), Space = O(N)
// If the next ans comes from the window which is made up continuous elements 
// then only we can optimize recurrence
int countWays(int n, int k){
	int dp[n+1] = {0};
	dp[0] = dp[1] = 1;
 
	for(int i = 2 ; i<=n; i++){
		if(i-(k+1) >= 0){
			dp[i] = 2*dp[i-1] - dp[i - (k+1)];
		}
		else{
			dp[i] = 2*dp[i-1];
		}
    }
    return dp[n]; 
}
 
int main(){
	int n, k;
	cin>>n>>k;
	
	// Recursive
	cout<<countWays(n,k)<<endl;
	
	// Top-Down
	int dp[n+1] = {0};
	dp[0] = dp[1] = 1;
	cout<<countWays(n,k,dp)<<endl;
 
	// Bottom-Up
    cout<<countWays(n,k)<<endl;

    // Bottom-Up(Optimized-Recurrence) 
    cout<<countWays(n,k)<<endl;

}
