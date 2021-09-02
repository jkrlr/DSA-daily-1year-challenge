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
int minJumpsRec(vector<int> &ar, int start){
	// base case
	if(start == ar.size()){
		return 0;
	}
    if(start > ar.size()){
        return INT_MAX;
    }

    // recursive case
	int minJumps = INT_MAX-1;
	for(int jump=1; jump<=ar[start]; jump++){
		int currJumps = minJumpsRec(ar,start + jump);
		minJumps = min(minJumps, currJumps);
	}
	
	return 1 + minJumps;
}
 
// Top-Down - Time = O(n^2), Space = O(n)
int minJumpsTD(vector<int> &ar, vector<int> &dp, int start){
	// base case
	if(start == ar.size()){
		return 0;
	}
    if(start > ar.size()){
        return INT_MAX;
    }
 
	// check if subproblem is precomputed
	if(dp[start]!=0){
		return dp[start];
	}
 
	int minJumps = INT_MAX-1;
	for(int jump=1; jump<=ar[start]; jump++){
		int currJumps = minJumpsTD(ar,dp,start + jump);
		minJumps = min(minJumps, currJumps);
	}
	
	return dp[start] = 1 + minJumps;
}
 
int main(){
	vector<int> ar = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5};
	int start  = 0;
	int n = ar.size();
	vector<int> dp(n,0);
	
	cout<<minJumpsRec(ar,start)<<endl;
	cout<<minJumpsTD(ar,dp,start)<<endl;
	// cout<<minJumpsBU(ar)<<endl;
    // cout << minJumpsGreedy(ar) << endl;
}
