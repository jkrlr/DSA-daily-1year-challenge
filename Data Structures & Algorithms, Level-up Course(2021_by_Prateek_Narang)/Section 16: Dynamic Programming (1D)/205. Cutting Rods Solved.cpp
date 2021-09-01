#include<iostream>
#include<climits>
using namespace std;
 
// Recursive - Time = O(n^n), Space = O(n)
int maxProfitRec(int prices[], int n){
	// base case
	if(n==0){
		return 0;
	}
 
	// recursive case
	int profit = INT_MIN;
	for(int i=0; i<n;i++){
		int cut = i+1;
		int currProfit = prices[i] + maxProfitRec(prices,n-cut);
		profit = max(profit, currProfit);
	}
	return profit;
}
 
// Top-Down - Time = O(n^2), Space = O(n)
int maxProfitTD(int *prices, int n, int *dp){
	if(n==0){
		return 0;
	}
	
	// check if value is precomputed
	if(dp[n]!=0){
		return dp[n];
	}
 
	int profit = INT_MIN;
	
	for(int i=0; i<n;i++){
		int cut = i+1;
		int currProfit = prices[i] + maxProfitTD(prices,n-cut,dp);
		profit = max(profit, currProfit);
	}
	return dp[n] = profit;
 
}
 
// Bottom-Up - Time = O(n^2), Space = O(n)
int maxProfitBU(int prices[], int n){
	int dp[n+1] = {INT_MIN};
	dp[0] = 0;
 
	for(int len = 1; len<=n; len++){
		for(int i = 0; i<len; i++){
			int cut = i+1;
			int currProfit = prices[i] + dp[len-cut];
			dp[len] = max(dp[len], currProfit);
		}
	}
	return dp[n];
}
 
int main(){
	int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(prices)/sizeof(int);
 
	cout<<maxProfitBU(prices,n)<<endl;
 
	int dp[n+1] = {0};
	cout<<maxProfitTD(prices,n,dp)<<endl;
	cout<<maxProfitRec(prices,n)<<endl;
}




/*
#include<iostream>
using std::string;
using std::cout;
using std::endl;
using namespace std;
 
// namespaces are used when we've to resolve the conflicts b/w the two variables having same names
 
namespace Jitendra{
	string name = "Jitendra";
 
}
 
namespace Kumar{
	string name = "Kumar";
}
 
int main(){
	cout<<Jitendra::name<<endl;
	cout<<Kumar::name<<endl;
} */
