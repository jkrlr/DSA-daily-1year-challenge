// https://codeforces.com/problemset/problem/1354/B
// Topic - Advance Binary Search Monotonic function property used
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
#define INF 1000000007
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;

string s;

bool isValid(int k){
	int freq[4] = {0};

	for(int i=0;i<k-1;i++){
		int ind = s[i] - '0';s
		freq[ind]++;
	}
	for(int i = k-1 ;i<=s.size();i++){
		int ind = s[i] - '0';
		freq[ind]++;

		if(freq[1]>0 and freq[2]>0 and freq[3]>0)
			return true;

	    ind = s[i-(k-1)] - '0';
		freq[ind]--;

	}
	return false;
}

int getAns(string s){
	int res = INF;
	int L = 3;
	int R = s.size();

	while(L<=R){
		int  mid = L +(R-L)/2;
		if(isValid(mid)){
			res = min(res,mid);
			R = mid -1;
		}
		else
			L = mid+1;
	}
	if(res==INF)
		return 0;
	else
		return res;
}

int main()
{   
    FAST_IO;
    
    #ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
	#endif
	
	int t;
	cin>>t;
	while(t--)
	{   
		cin>>s;
		
		cout<<getAns(s)<<endl;
	}
	return 0;
}