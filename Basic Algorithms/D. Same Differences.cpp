// D. Same Differences
// https://codeforces.com/contest/1520/problem/D

// Problem Statement :
// Given array with n integers, find pairs i,j such that 
// i< j and aj - ai = j-i 

// => ai - i = aj - j
// Now, we can form a new ar from (ai-i) and 
// then store the frequency of same numbers into hash map

// Time Complexity = O(n) -> for traversing the hashmap
// Space Complexity = O(n) -> for storing the hashmap

// Complexity for iteration over a HashMap is O(n + s), where n is the number of mappings and s is the size. 
// It must iterate linearly over all s buckets and linearly over all n entries.

#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
#define INF 1000000000
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;

int ar[200001];

int main()
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;

		for(int i=1;i<=n;i++)
			cin>>ar[i];

		for(int i=1;i<=n;i++)
			ar[i] = ar[i]-i;

		map<lli,lli> m;
		for(int i=1;i<=n;i++){
			if(m[ar[i]]>0)
				m[ar[i]]++;
			else
				m[ar[i]]=1;
		}
		lli ans =0;
		for(auto it : m){
			long long int  p = it.second;
			ans+=p*(p-1)/2;
		}
		cout<<ans<<endl;


	}
    return 0;
}