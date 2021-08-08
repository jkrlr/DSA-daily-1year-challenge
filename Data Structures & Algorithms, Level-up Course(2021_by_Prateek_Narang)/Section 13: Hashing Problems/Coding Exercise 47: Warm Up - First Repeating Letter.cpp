// Time = O(n), Space =  O(n)

#include<bits/stdc++.h>
using namespace std;
 
 
char firstRepeatChar(string input){
      char ans = '\0';
	unordered_set<char> s;
	
	for(char ch: input){
		if(s.count(ch)>0){
			ans = ch;
			return ans;
		}
		else
			s.insert(ch);
	}
	return ans;
}
