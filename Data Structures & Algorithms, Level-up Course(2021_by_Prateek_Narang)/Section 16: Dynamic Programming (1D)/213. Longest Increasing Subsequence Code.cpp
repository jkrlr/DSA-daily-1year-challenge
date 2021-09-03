// https://leetcode.com/problems/longest-increasing-subsequence/
// Revisit it next time and solve it in (n*Logn) 
// and print the subsequence also
// add brute force solution(Time = O(2^n)) and print all the solutins

#include<iostream>
#include<vector>
using namespace std;
 
// Bottom-Up - Time = O(n^2), Space = O(n)
int LCS(vector<int> &ar){
	int n = ar.size();
	vector<int> dp(n,1);
 
	int len = 1;
	for(int i = 1; i<n; i++){
		for(int j=0; j<i; j++){
			if(ar[i] > ar[j]){
				dp[i] = max(dp[i], 1 + dp[j]);
				len = max(len, dp[i]);
			}
		}
	}
	return len;
}
 
int main(){
	vector<int> ar = {50, 4, 10, 8, 30, 100};
	cout<<LCS(ar)<<endl;
}
