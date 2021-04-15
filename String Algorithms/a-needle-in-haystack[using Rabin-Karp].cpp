// Rabin - Karp String matching algorithm
// Find all occurrences of pattern in text: O(N+M)
// => i.e. (N-M+1)*O(1) = (total no of windows)*(comparision time of one window)
// N - length of string, M - length of string pattern

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
lli powr[1000001];
const int p = 31;

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
	lli p_power=1;
	dp[0]=(input_str[0] - 'a' + 1);

	for(int i=1;i<input_str.size();i++){
		
		char ch = input_str[i];
		p_power=(p*p_power)%mod;
		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power)%mod;
	}
}

lli getHash(string key){
	lli p_power=1;
	lli ans =0;

	for(char ch:key){
		ans = (ans + (ch - 'a' + 1)*p_power)%mod;
		p_power = (p*p_power)%mod;
	}
	return ans;
}

lli subStringHash(int L, int R){
	  lli ans = dp[R];

	  if(L>0)
	  	ans = ((ans - dp[L-1]) + mod)%mod;

	  return ans;
}

int main()
{   
	for(int i=0;i<=1000000;i++)
		powr[i]=power(p, i);

	int n,L,R;
	string needle, haystack;

	while(cin>>n)
	{   		
		cin>>needle;
		cin>>haystack;

		lli needleHash = getHash(needle);
		init(haystack);

		for(L=0,R=needle.size()-1;R<haystack.size();L++,R++){
			if((needleHash*powr[L])%mod == subStringHash(L,R))
				cout<<L<<endl;
		}
		cout<<endl;
	}
	return 0;
}