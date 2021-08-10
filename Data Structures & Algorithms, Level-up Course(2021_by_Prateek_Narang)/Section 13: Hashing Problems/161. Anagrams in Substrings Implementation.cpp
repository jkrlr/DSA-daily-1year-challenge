// Time = O(N^3 + N^2) = O(N^3), Space = O(N)

// Instead of storing the substrings and then store the hash and then club the same hash key
// We're directly calculating the hash of substrings and clubbing the same anagrams in one time by using with the helper function
// Map -> used becoz by default map can handle key of type vector<int> , So it can handle complex keys as well
// Unorderd_Map -> for using it you have to define your own hash function to it

#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
1. Generate all substrings
2. Generate hash values of each substring
3. Hash the 'hash' values of substrings to club all anagrams in single bucket, to get their frequency
4. From the freq count, we can easily count pairs
*/
 
vector<int> getHashValue(string str, int start, int end){
	vector<int> hash(26,0);
	
	// In worst case we are traversing the whole string
	for(int i=start;i<=end;i++){
		char ch = str[i];
		hash[ch - 'a']++;
	}
	return hash;
}
 
int AnagramsSubstrings(string str){
	int n = str.length();
	map<vector<int>,int> m;
 
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){	// O(N^2)
			// substring str[i...j]
			vector<int> h = getHashValue(str,i,j);	// O(N)
			
			// put it inside the map
			m[h]++;
		}
	}
	
	// count pairs
	int ans = 0;
	for(auto p : m){
		int freq = p.second;
		if(freq>=2){
			ans+=freq*(freq-1)/2;
		}
	}
	return ans;
}
 
int main(){
	string str;
	cin>> str;
	
	cout<<AnagramsSubstrings(str)<<endl;
}
