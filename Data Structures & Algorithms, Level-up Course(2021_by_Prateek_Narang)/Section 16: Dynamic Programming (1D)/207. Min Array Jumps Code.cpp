// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// This problems can be solved using greedy in Time = O(n), Space = O(1)
/* 
*DP question
*Can be solved using Greedy
*Revision [Why Greedy is applicable here]?
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 
// Recursive - Time = O(n^n), Space = O(n)
int minJumpsRec(vector<int> &ar, int idx){
	// base case
	if(idx == ar.size()){
		return 0;
	}
    if(idx > ar.size()){
        return INT_MAX;
    }

    // recursive case
	int steps = INT_MAX;
    int maxjump = ar[idx];

	for(int jump=1; jump<=maxjump; jump++){
        int subproblem = minJumpsRec(ar, idx + jump);
        if(subproblem!=INT_MAX){
            steps = min(steps, 1 + subproblem);
        }
	}
	
	return steps;
}
 
// Top-Down - Time = O(n^2), Space = O(n)
int minJumpsTD(vector<int> &ar, vector<int> &dp, int idx){
	// base case
	if(idx == ar.size()){
		return 0;
	}
    if(idx > ar.size()){
        return INT_MAX;
    }
 
	// check if subproblem is precomputed
	if(dp[idx]!=0){
		return dp[idx];
	}
 
	int steps = INT_MAX;
    int maxjump = ar[idx];
    for (int jump = 1; jump <= maxjump; jump++){
        int subproblem = minJumpsTD(ar, dp, idx + jump);
        if(subproblem!=INT_MAX){
            steps = min(steps, 1 + subproblem);
        }
    }

    return dp[idx] = steps;
}
 
int main(){
	vector<int> ar = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5};
	int idx  = 0;
	int n = ar.size();
	vector<int> dp(n,0);
	
	cout<<minJumpsRec(ar,idx)<<endl;
	cout<<minJumpsTD(ar,dp,idx)<<endl;
	// cout<<minJumpsBU(ar)<<endl;
    // cout << minJumpsGreedy(ar) << endl;
}
