// Time = O(2^N), Space = O(N)

#include<iostream>
#include<unordered_set>
#include<climits>
#include<vector>
using namespace std;

// Main Logic
int minBarsHelper(string str, unordered_set<string> m, int start){
	// base case
	if(str[start]=='\0'){
		return 0;
	}
 
	// recursive case
	int bars = INT_MAX;
	string currString = ""; 
	for(int i = start;i<str.size();i++){
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
 
int minBars(string str, vector<string> words){
	unordered_set<string> m;
	for(string w:words){
		m.insert(w);
	}
	int start = 0;
 
	// recursive helper function
	int output = minBarsHelper(str,m,start);
	return output-1;    // -1 because at null character it is also doing 1 partition
}
 
 
int main(){
	string str = "thequickbrownfoxjumpsoverthehighbridge";
	vector<string> words = {"the", "fox", "thequickbrownfox", "jumps", "lazy", "lazyfox", "highbridge","the","over", "bridge", "high", "tall","quick", "brown"};
	
	cout<<minBars(str,words)<<endl;
}
