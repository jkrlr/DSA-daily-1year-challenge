// Time = O(m + (CommonElements)*Log(CommonElements)), Space = O(n)
#include<bits/stdc++.h>
using namespace std;
 
vector<int> commonElements(vector<int> v1, vector<int> v2){
	vector<int>res;
	unordered_set<int> s(v1.begin(),v1.end());
 
	for(int num: v2){
		if(s.count(num)>0){
			res.push_back(num);
		}
	}
	sort(res.begin(),res.end());
	return res;
}
 
 
