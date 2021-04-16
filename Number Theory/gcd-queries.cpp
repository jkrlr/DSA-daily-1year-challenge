// https://www.codechef.com/problems/GCDQ
// Gcd Queries : GCDQ

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007s
#define endl '\n'
#define INF 1000000000
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;
int ar[100001];
int pre[100005], suf[100005]; 


int gcd(int a, int b){
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}


int main()
{       
	FAST_IO;
	int t,n,q,L,R;

	cin>>t;

	while(t--)
	{   		
		cin>>n>>q;

		for(int i=1;i<=n;i++)
			cin>>ar[i];

		pre[0]=suf[n+1]=0;

		for(int i=1;i<=n;i++)
			pre[i]=gcd(ar[i],pre[i-1]);
		
		for(int i=n;i>=1;i--)
			suf[i]=gcd(ar[i],suf[i+1]);

		while(q--){
			
			cin>>L>>R;
			cout<<gcd(pre[L-1],suf[R+1])<<endl;
		}
	}
	return 0;
}
