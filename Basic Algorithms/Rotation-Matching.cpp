// C. Rotation Matching
// https://codeforces.com/contest/1365/problem/C


#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
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

int main()
{       

	int maxF_a=0,maxF_b=0;
	int a[200002], b[200002];


    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int i=1;i<=n;i++)
    	cin>>b[i];

    map<lli,lli> Freq_a, Freq_b;

    for(int i=1;i<=n;i++){
    	lli cost_a = (a[i] - i + n)%n; 
    	lli cost_b = (b[i] - i + n)%n; 

    	Freq_a[cost_a]++;
    	Freq_b[cost_b]++;
    }

    for(auto f:Freq_a){
    	if(maxF_a<f.second)
    		maxF_a=f.second;
    }

    for(auto f:Freq_b){
    	if(maxF_b<f.second)
    		maxF_b=f.second;
    }

    lli ans = min(maxF_a,maxF_b);

    cout<<ans<<endl;

    return 0;
}