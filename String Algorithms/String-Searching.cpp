// String Searching
// https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/tutorial/

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

int pi[200001];

int main()
{
    string P, T;
    cin >> P;
    cin >> T;

    string SearchString = P + '#' + T;

    for (int i = 1; i < SearchString.size();i++){
        int j = pi[i - 1];

        while (j>0 && (SearchString[i]!=SearchString[j]))
            j = pi[j - 1];
        
        if(SearchString[i]==SearchString[j])
                j++;
        pi[i] = j;        
    }

    int ans = 0;
    int n = P.size();
    for (int i = n; i < SearchString.size();i++){
        if(pi[i]==n)
            ans++;
    }

    cout << ans << endl;

    return 0;
}
