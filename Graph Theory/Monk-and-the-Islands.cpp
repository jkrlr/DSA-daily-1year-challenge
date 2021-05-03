// Monk and the Islands
// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/

// Solved using Single source shortest path algorithm using bfs


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

vi adj[10001];
int vis[10001], dis[10001];

void bfs(int node){
	vis[node]=1;
	dis[node]=0;

	queue<int> q;
	q.push(node);

	while(!q.empty()){
		int curr = q.front();
		q.pop();

		for(int child : adj[curr]){
			if(vis[child]==0){
				vis[child]=1;
				dis[child]= dis[curr]+1;
				q.push(child);
			}
		}
	}
}

int main()
{
	int t,n,m,a,b;
	cin>>t;

	while(t--){
		cin>>n>>m;

		for (int i=1;i<=n;i++){
			adj[i].clear(), vis[i]=0, dis[i]=0;
		}

		for(int i=1;i<=m;i++){
			cin>>a>>b;
			adj[a].pb(b), adj[b].pb(a);
		}

		bfs(1);

		cout<<dis[n]<<endl;
	}
}