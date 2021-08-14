// https://leetcode.com/problems/group-anagrams/
// Time = O(N), Space = O(N) , N -> size of wordsDict

/*  In String problems - If string to string comparision happens
    - Decrease the comparision complexity to O(1) by hashing */

// Sorting can be used in place of calculating the hash key vector
// Sorting is useful when input string contains chars of other than lowercase alphabets
// Sorting of anagrams produce the same string

// use auto& rather then auto to avoid unnecessary copy

#include<bits/stdc++.h>
using namespace std;
 
vector<int> getHashValue(string s){
	vector<int> hash(26,0);
	for(char ch : s){
		int idx = ch - 'a';
		hash[idx]++;
	}
	return hash;
}
 
vector<vector<string>> groupAnagrams(vector<string> strs){
    	
	map<vector<int>, vector<string>> m;
	
	// store same hash strings(anagrams) into map
	for(string s :strs){
		vector<int> key = getHashValue(s);
		m[key].push_back(s);
	}
 
	vector<vector<string>> res;
	for(auto it : m){
		auto anagrams = it.second;
		res.push_back(anagrams);
	}
	return res;
}
 
