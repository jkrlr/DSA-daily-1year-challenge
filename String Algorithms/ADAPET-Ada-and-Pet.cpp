// ADAPET - Ada and Pet
// https://www.spoj.com/problems/ADAPET/

// EXAMPLE
// G O R E G O
//         G O R E G O 

// String  : S     K = 1   Ans = N
// Length  : L     K = 2   Ans = N + (N-ML)
// Integer : K     K = 3   Ans = N + (N-ML) + (N-ML) = N + 2(N-ML)
// Merge L : ML    K = K   Ans = N + (K-1)(N-ML)



#include<bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++)
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

int pi[1000001];

void CalcPI(string s){
    for (int i = 1; i < s.size();i++){
        int j = pi[i - 1];

        while (j>0 && s[i]!=s[j])
            j = pi[j - 1];
        
        if(s[i]==s[j])
            j++;

        pi[i] = j;
    }
}

int main()
{
    FAST_IO;
    string s;
    lli t,k;

	cin>>t;
    while (t--)
    {
    cin >> s >> k;    
    int n = s.size();

    CalcPI(s);

    cout << (n + (k - 1) * (n - pi[n - 1])) << endl;
    }
    
    return 0;
}