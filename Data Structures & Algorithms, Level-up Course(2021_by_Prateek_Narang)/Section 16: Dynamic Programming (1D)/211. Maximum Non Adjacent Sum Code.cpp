// https://leetcode.com/problems/house-robber/submissions/
// Revise Leetcode approaches -> nice explained and multiple varieties learn
// In Bottom up dp think about the smallest cases like if array is empty or array size is 1 or 2 and see your code accordingly.

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 
// Recursive - Time = O(2^n), Space = O(n)
int maxSubsetSumNoAdjacent(vector<int> &ar, int idx){
	// base case
	if(idx >= ar.size()){
		return 0;
	}
	// recursive case
	int include = ar[idx] + maxSubsetSumNoAdjacent(ar, idx+2); 
	int exclude = maxSubsetSumNoAdjacent(ar, idx+1);
 
	return max(include, exclude);
}
 
// Top-Down - Time = O(n), Space = O(n)
int maxSubsetSumNoAdjacentTD(vector<int> &ar, vector<int> &dp, int idx){
	// base case
	if(idx >= ar.size()){
		return 0;
	}
	
	if(dp[idx]!=0){
		return dp[idx];
	}
 
	int include = ar[idx] + maxSubsetSumNoAdjacent(ar, idx+2); 
	int exclude = maxSubsetSumNoAdjacent(ar, idx+1);
 
	return dp[idx] = max(include, exclude);
 
}

// Bottom - Time = O(n), Space = O(n)
int maxSubsetSumNoAdjacentBU(vector<int> &ar){
	int n = ar.size();
	vector<int>dp(n,0);
	
	// Corner case
    /* If array contains negative elements - we can return max(ar[0], 0) 
    means if ar[0] = -ve, then return 0 */
	if(n==1){
		return max(0,ar[0]);
	}
	else if(n==2){
		return max(0, max(ar[0], ar[1]));
	}
	// Bottom-Up logic
	dp[0] = max(0,ar[0]);
	dp[1] =  max(0, max(ar[0], ar[1]));
 
	for(int i = 2; i<n; i++){
		int include = ar[i] + dp[i-2];
		int exclude = dp[i-1];
		dp[i] = max(include, exclude);
	}
	return dp[n-1];
}

// Bottom-Up optimized - Time = O(n), Space = O(1)
/*We can notice that in the previous step we use only dp[i-1] and memo[i-2], so going just 2 steps back. 
We can hold them in 2 variables instead. 
This optimization is met in Fibonacci sequence creation and some other problems.
*/
int maxSubsetSumNoAdjacentBUOptimized(vector<int> &ar){
	int n = ar.size();

	// Corner case
    /* If array contains negative elements - we can return max(ar[0], 0) 
    means if ar[0] = -ve, then return 0 */
	if(n==1){
		return max(0,ar[0]);
	}
	else if(n==2){
		return max(0, max(ar[0], ar[1]));
	}
	// Bottom-Up Optimized logic - this code is not giving right answers check it later
	int lastToLast = max(0,ar[0]);
	int last =  max(0, max(ar[0], ar[1]));
 
	for(int i = 2; i<n; i++){
        int temp = last;
        int last = max(ar[i] + lastToLast, last);
        lastToLast = temp;
    }
    return last;
}

int main(){
    vector<int> ar({6, 10, 12, 7, 14});
    int n = sizeof(ar) / sizeof(int);
    int idx = 0;
	vector<int> dp(n,0);
 
	cout<<maxSubsetSumNoAdjacent(ar,idx)<<endl;
	cout<<maxSubsetSumNoAdjacentTD(ar,dp,idx)<<endl;
	cout<<maxSubsetSumNoAdjacentBU(ar)<<endl;
	cout<<maxSubsetSumNoAdjacentBUOptimized(ar)<<endl;
}
