// PPATH - Prime Path
// https://www.spoj.com/problems/PPATH/

// Very Good Question 
// Solved using single source shortest path in an unweighted graph algorithm


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

vi adj[100001];
vi primes;
int vis[100001], dist[100001];

bool isPrime(int n){
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}

bool isValid(int a, int b){
	int cnt=0;

	while(a){
		if((a%10) != (b%10))
			cnt++;
		a/=10, b/=10;
	}

	if(cnt==1)
		return true;
	else
		return false;
}

void buildGraph(){
	for(int i=1000;i<=9999;i++){
		if(isPrime(i))
			primes.push_back(i);
	}

	for(int i=0;i<primes.size();i++){
		for(int j=i+1;j<primes.size();j++){
			int a = primes[i];
			int b = primes[j];

			if(isValid(a,b))
				adj[a].push_back(b), adj[b].push_back(a);
		}
	}
}

void bfs(int src){

	queue<int> q;
	q.push(src);

	vis[src]=1;
	dist[src]=0;

	while(!q.empty()){
		int curr = q.front();
		q.pop();

		for(int child : adj[curr]){
			if(vis[child]==0){
				vis[child]=1;
				dist[child]= dist[curr]+1;
				q.push(child);
			}
		}
	}
}

int main()
{
	int t,a,b;
	cin>>t;

	buildGraph();

	while(t--){
		cin>>a>>b;

		for (int i=1000;i<=9999;i++){
			 vis[i]=0, dist[i]=-1;
		}

		bfs(a);

		if(dist[b]==-1)
			cout<<"Impossible"<<endl;
		else
			cout<<dist[b]<<endl;
	}
}