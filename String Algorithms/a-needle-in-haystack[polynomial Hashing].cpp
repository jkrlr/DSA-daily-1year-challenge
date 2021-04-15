// https://www.spoj.com/problems/NHAY/
// Polynomial Rolling Hashing used
// Time Complexity O(nlogn + m)
// n - length of text, m - length of pattern
// Can be solved using KMP

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
#define INF 1000000000

using namespace std;

lli dp[1000001];
lli inv[1000001];

lli power(lli a, lli n){
	lli ans=1;

	while(n){
		if(n%2)
			ans=(ans*a)%mod, n--;
		else
			a=(a*a)%mod, n/=2;
	}
	return ans;
}

void init(string input_str){
	lli p=31;
	lli p_power=1;
	inv[0]=1;
	dp[0]=(input_str[0] - 'a' + 1);

	for(int i=1;i<input_str.size();i++){
		char ch = input_str[i];
		p_power=(p*p_power)%mod;
		inv[i]=power(p_power, mod - 2);

		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power)%mod;
	}
}

lli getHash(string key){
	lli p=31;
	lli p_power=1;
	lli ans =0;

	for(int i=0;i<key.size();i++){
		char ch = key[i];
		ans = (ans + (ch - 'a' + 1)*p_power)%mod;
		p_power = (p*p_power)%mod;
	}
	return ans;
}

lli subStringHash(int L, int R){
	  lli ans = dp[R];

	  if(L>0)
	  	ans = ((ans - dp[L-1]) + mod)%mod;

	  ans = (ans*inv[L])%mod;

	  return ans;
}

int main()
{   
	
	int n,L,R;
	string needle, haystack;

	while(cin>>n)
	{   		
		cin>>needle;
		cin>>haystack;

		lli needleHash = getHash(needle);
		init(haystack);

		for(L=0,R=needle.size()-1;R<haystack.size();L++,R++){
			if(needleHash==subStringHash(L,R))
				cout<<L<<endl;
		}
		cout<<endl;
	}
	return 0;
}