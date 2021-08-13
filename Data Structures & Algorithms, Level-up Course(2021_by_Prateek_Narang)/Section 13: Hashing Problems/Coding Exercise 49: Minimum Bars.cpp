// https://leetcode.com/problems/word-break-ii/

// You are using vector.length() and string.size() -> correct is vector.size() and string.length()
// you misspell lenght() -> correct is length()
// You are making mistake in while loops by using || -> correct is && 

// In recursion - If we're calculating the res<string> vector, by pushing back output_string and passing both res, output_string parameter - then return type of recursive function is void means simply return or bool(in case of codition checking) 
        
// afer returning if paused recursion value is modified(means variable is by default or knowingly passed by reference not pass a copy) - Think if old value is required instead of modified - Then backtracking used in recursion

//All o/p combinations case - probably recursion + Backtracking 

// when you have to explore all the possibilities(means feel like - at every place you have to start from beginning is required) at a given index-value or in packets of group of indices-values - Recursion used

// Look Carefully - Are you computing same values again and again? Yes - DP lagagi

// take care of spelling mistake in google docs and don't forget to declare variables before using it

// while code writing - if stuck - take pen & paper - write code by dry run through test case

#include<bits/stdc++.h>
using namespace std;

int minBarsHelper(string str, unordered_set<string> m, int start){
	// base case
	if(str[start]=='\0'){
		return 0;
	}
 
	// recursive case
	int bars = INT_MAX;
	string currString = ""; 
	
	for(int i = start;i<str.length();i++){
		currString += str[i];
		
		if(m.find(currString)!=m.end()){
			int remainingSubproblem = minBarsHelper(str,m,i+1);
			
			if(remainingSubproblem!=-1){
				bars = min(bars, 1 + remainingSubproblem);
            }
        }
    }
    if(bars==INT_MAX){
		return -1;
	}
	return bars;
}

 
int min_bars(string s, vector<string> words, int n){
    unordered_set<string> m;

    for (int i = 0; i < n;i++){
        m.insert(words[i]);
    }
    int start = 0;
 
    // recursive helper function
    int output = minBarsHelper(s,m,start);
    return output-1;    // -1 because at null character it is also doing 1 partition

}

/* LeetCode Solution */
/* void wordBreakHelper(string s, unordered_set<string> &m,vector<string> &res, string output, int start){
	// base case	
	if(s[start]== '\0'){
		output.pop_back(); // remove the space at the end of output
		res.push_back(output);
		return;
	}
 
	// recursive case
	string sub_s;
	for(int i=start ; i<s.length();i++){
		sub_s += s[i];
		if(m.find(sub_s)!=m.end()){
			string new_output = output + sub_s + " "; // created copy - not required to revert changes becoz of copy passing
			wordBreakHelper(s,m,res,new_output,i+1);
		}
	}
}
 
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        	unordered_set<string> m;
		for(string word : wordDict){
			m.insert(word);
		}
		vector<string> res;
		string output;
		int start =0;
		
		wordBreakHelper(s,m,res,output,0);
		return res;
    }
};
 */