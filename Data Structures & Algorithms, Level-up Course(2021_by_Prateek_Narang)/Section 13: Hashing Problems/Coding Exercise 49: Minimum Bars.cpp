#include<bits/stdc++.h>
using namespace std;

int min_bars_helper(string s, unordered_set<string> &hash, int start){
	// base case
	if(s[start]=='\0'){
		return 0;
	}
	
	// recursive case
	int ans = INT_MAX;
	string substr;
	for(int i = start;i<s.size();i++){
		substr += s[i];
		if(hash.find(substr)!=hash.end()){
			int subProblem = min_bars_helper(s,hash,start+1);
			ans = min(ans,subProblem);
		}
	}

	if(ans==INT_MAX){
		return -1;
	}
	return ans;
}
 
int min_bars(string s, string words[], int n){
    unordered_set<string> hash;

    for (int i = 0; i < n;i++){
        hash.insert(words[i]);
    }

	
	int output = min_bars_helper(s,hash, 0);
	return output-1;
}
