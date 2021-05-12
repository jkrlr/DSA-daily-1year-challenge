// RMQSQ - Range Minimum Query
// https://www.spoj.com/problems/RMQSQ/

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
#define INF 1000000000
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)
 
using namespace std;

int ar[100001], st[4 * 100001];

void build(int si, int ss, int se){
	if(ss==se){
		st[si]=ar[ss];
		return;
	}

	int mid = ss + (se-ss)/2;

	build(2*si, ss, mid);
	build(2*si+1,mid+1, se);

	st[si]= min(st[2*si],st[2*si+1]);
}

int query(int si, int ss, int se, int qs, int qe){

	if(qe<ss || qs>se)
		return INF;

	if(ss>=qs && se<=qe)
		return st[si];

	int mid = ss + (se-ss)/2;

	int left = query(2*si, ss, mid, qs, qe);
	int right = query(2*si+1, mid+1, se, qs, qe);

	return min(left , right) ;
	
}


int main(){

	int n,q,l,r;

	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}

	build(1,1,n);

	cin>>q;

	while(q--){
		cin>>l>>r;
		cout<<query(1,1,n,l+1,r+1)<<endl;
	}

    return 0;
}