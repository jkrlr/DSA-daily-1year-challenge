// Binomial Coefficient using Modulo inverse

// Problem Statement :

// Given q queries of type N K, Calculate C(N,K) % P, Where P > N.
// (If we P < N, Then we'll use Lucas Theorem otherwise we'll use the below discussed method(Modulo inverse method)).

// Problem Solution :

// C(N,K) = N! / (K! * (N-K)!)
// C(N,K) = N!%P / (K!%P * (N-K)!*P)

#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define P 1000000007
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
#define INF 1000000000
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;
int F[1000001];

int power(int a, int n){
	int res=1;

	while(n){
		if(n%2)
			res=(res*1LL*a)%P, n--;
		else
			a = (a*1LL*a)%P, n/=2;
	}
	return res;
}

int C(int n, int k){
	if(k > n)
		return 0;

	int res=F[n];

	// res = res/k!;
	// i.e. res = res*inv(F[k])

	res = (res*1LL*power(F[k], P-2))%P;
	res = (res*1LL*power(F[n-k],P-2))%P;

	return res;
}

int main()
{

    F[0]=1;

	// When we multiply a number with 1LL -> Then the number become long long int type and doesn't cause integer overflow.
	// otherwise you can declare all variables with long long int , then no need to multiply with 1LL.
    for(int i=1;i<=1000000;i++)
    	F[i]=(F[i-1]*1LL*i)%P;  // N! = (N-1)! * N

    int q,n,k;

    cin >> q;

    while (q--)
    {
        cin >>n>>k;
        cout<<C(n,k)<<endl;
    }

    return 0;
}




