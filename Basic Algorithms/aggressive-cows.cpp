// https://www.spoj.com/problems/AGGRCOW/
// Topic - Advance Binary Search Monotonic function property used
// f(dist) : is it possible to arrange C cows such than minimum distance between them greater than equal to dist

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++)
#define mod 1000000000
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

int ar[1000001];

bool isValid(int mid, int n, int c){
	int cnt =0;
	int pre = -INF;

	for(int i=1;i<=n;i++){
		if(ar[i]-pre >= mid)
			cnt++,pre=ar[i];
	}

	if(cnt>=c)
		return true;
	else
		return false;
}

int getAns(int n, int c){
	int res = 0;
	int L = 0;
	int H = ar[n] - ar[1];

	while(L<=H){
		int  mid = L +(H-L)/2;
		if(isValid(mid,n,c)){
			res = max(res,mid);
			L = mid +1;
		}
		else
			H = mid-1;
	}
	
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
		int n,c;
		cin>>n>>c;
		for(int i=1;i<=n;i++)
			cin>>ar[i];
		
		cout<<getAns(n,c)<<endl;
	}
	return 0;
}