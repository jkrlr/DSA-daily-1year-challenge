// B. TMT Document
// https://codeforces.com/contest/1509/problem/B

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

int main(){

	int t,n;
	string s;

	cin>>t;

	while(t--){
		cin>>n>>s;
		int cnt_T=0, cnt_M=0;
		bool flag = true;

		for(int i=0;i<s.length();i++){
			if(s[i]=='T')
				cnt_T++;
			else
				cnt_M++;

			if(cnt_M>cnt_T){
				flag=false;
				break;			    
			}

		}

		if(cnt_T!=(2*cnt_M))
			flag=false;

		if(flag==false){
			cout<<"NO"<<endl;
			continue;
		}

		cnt_T=0, cnt_M=0;

		for(int i=s.length()-1;i>=0;i--){
			if(s[i]=='T')
				cnt_T++;
			else
				cnt_M++;

			if(cnt_M>cnt_T){
				flag=false;
				break;			    
			}

		}

		if(cnt_T!=(2*cnt_M))
			flag=false;

		if(flag==false){
			cout<<"NO"<<endl;
		}
		else
			cout<<"YES"<<endl;

	}

    return 0;
}