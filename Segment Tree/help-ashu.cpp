// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/
// Based on Segment tree point Update
// Time Complexity = O(qlogr) or O(nlogn)

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
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;
const int maxN = 100001;
int ar[maxN];
// {odd, even}
pair<int,int> st[4*maxN];

void build(int si, int ss, int se){
	if(ss==se){
		if(ar[ss]%2 ==1 )
			st[si]={1,0};
		else
			st[si]={0,1};
		return;
	}

	int mid = ss +(se-ss)/2;

	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);

	st[si].first=st[2*si].first + st[2*si+1].first;
	st[si].second=st[2*si].second + st[2*si+1].second;


}

void update(int si, int ss, int se, int qi, int newVal){
	if(ss==se){
		if(ar[ss]%2 == 1)
			st[si]={0,1};
		else
			st[si]={1,0};
		
		ar[ss]=newVal;
		return;
	}

	int mid = ss +(se-ss)/2;

	if(qi<=mid)
		update(2*si, ss, mid, qi, newVal);
	else
		update(2*si+1, mid+1, se, qi, newVal);

	st[si].first=st[2*si].first + st[2*si+1].first;
	st[si].second=st[2*si].second + st[2*si+1].second;
}

int getEven(int si, int ss, int se, int l, int r){
	if(ss>r || se<l)
		return 0;
	if(ss>=l && se<=r)
		return st[si].second;

	int mid = ss +(se-ss)/2;
	int left = getEven(2*si,ss,mid,l,r);
	int right = getEven(2*si+1,mid+1,se,l,r);

	return left + right;
}

int getOdd(int si, int ss, int se, int l, int r){
	if(ss>r || se<l)
		return 0;
	if(ss>=l && se<=r)
		return st[si].first;

	int mid = ss +(se-ss)/2;
	int left = getOdd(2*si,ss,mid,l,r);
	int right = getOdd(2*si+1,mid+1,se,l,r);

	return left + right;	
}

int main()
{   
	int n,q,code,l,r;
	cin>>n;

	for(int i=1;i<=n;i++)
		cin>>ar[i];

	build(1,1,n);
	cin>>q;
	while(q--)
	{   		
		cin>>code>>l>>r;

		if(code==0){
			if((ar[l] % 2) == r%2)
				continue;
			else
				update(1,1,n,l,r);
		}
		else if(code==1){
			cout<<getEven(1,1,n,l,r)<<endl;
		}
		else{
			cout<<getOdd(1,1,n,l,r)<<endl;
		}

	}
	return 0;
}