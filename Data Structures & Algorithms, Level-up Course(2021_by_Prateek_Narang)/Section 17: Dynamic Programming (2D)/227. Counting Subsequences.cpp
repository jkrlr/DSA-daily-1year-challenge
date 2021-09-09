// https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
 
// Recursive : Time = O(2^n), Space = O(n) , n is size of s1
int countSubSequence(string s1, string s2, int idxS1, int idxS2){
	// base case
	if(s2[idxS2] == '\0'){
		return 1;
	}
	if(s1[idxS1] == '\0'){
		return 0;
	}
 
	// recursive case
	if(s1[idxS1] == s2[idxS2]){
		int include = countSubSequence(s1, s2, idxS1 + 1, idxS2 + 1);
		int exclude = countSubSequence(s1, s2, idxS1 + 1, idxS2);
		return include + exclude;
	}
	else{
		return countSubSequence(s1, s2, idxS1 + 1, idxS2);
	}
}
 
// Top-Down : Time = O(n1*n2), Space = O(n1*n2)
int countSubSequenceTD(string s1, string s2, int idxS1, int idxS2, vector<vector<int>> &dp){
	// base case
	if(s2[idxS2] == '\0'){
		return 1;
	}
	if(s1[idxS1] == '\0'){
		return 0;
	}
 
	// check if state is precomputed 
	if(dp[idxS1][idxS2] != -1){
		return dp[idxS1][idxS2];
	}
 
	if(s1[idxS1] == s2[idxS2]){
		int include = countSubSequenceTD(s1, s2, idxS1 + 1, idxS2 + 1, dp);
		int exclude = countSubSequenceTD(s1, s2, idxS1 + 1, idxS2, dp);
		return dp[idxS1][idxS2] = include + exclude;
	}
	else{
		return dp[idxS1][idxS2] = countSubSequenceTD(s1, s2, idxS1 + 1, idxS2, dp);
	}
}
 
// Bottom-Up: Time = O(n1*n2), Space = O(n1*n2)
int countSubSequenceBU(string s1, string s2){
	int n1 = s1.length();
	int n2 = s2.length();
	vector<vector<int>> dp(n1+1, vector<int>(n2+1));
 
	// Base case turns into Initialization
	for(int i = 0; i<=n1; i++){
		for(int j = 0; j<=n2; j++){
			if(i==0){
				dp[i][j] = 0;
			}
			if(j==0){
				dp[i][j] = 1;
			}
		}
	}
 
	for(int i = 1; i<=n1; i++){
		for(int j = 1; j<=n2; j++){
			// because indexing for strings is 0 based and for dp is 1 based
			if(s1[i-1] == s2[j-1]){
				int include = dp[i-1][j-1];
				int exclude = dp[i-1][j];
				dp[i][j] = include + exclude;
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n1][n2];
}
 
int main(){
	string s1 = "ABCECDG";
	string s2 = "ABC";
	int n1 = s1.length();
	int n2 = s2.length();
	vector<vector<int>> dp(n1, vector<int>(n2,-1));
	cout<<countSubSequence(s1, s2, 0, 0)<<endl;
	cout<<countSubSequenceTD(s1, s2, 0, 0, dp)<<endl;
	cout<<countSubSequenceBU(s1, s2)<<endl;
}
