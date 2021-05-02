// C. Rotation Matching
// https://codeforces.com/contest/1365/problem/C

// For Identity Array i.e. ar = {1,2,3,4.......}
// For element j, the no. of cyclic shift needed to reach at it's correct position = (j-pos[j]+N)%N

//  Cyclic shift needed : (final_pos[j]-initialpos[j]+N)%N (Here, pos[j] is initialpos[j])

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

int freq[200001];
int pos[200001];

int main()
{
    int n, x, y, ele, mx = 0;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> ele;
        pos[ele] = i;
    }
    for (int i = 1; i <= n; i++){
        cin>>ele;
        x = i;
        y = pos[ele];

        freq[(y - x + n) % n]++;
    }

    for(int i=0;i<=n;i++){
        mx = max(mx, freq[i]);
    }

    cout << mx;
}