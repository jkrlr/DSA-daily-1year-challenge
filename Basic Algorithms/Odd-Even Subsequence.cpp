// D. Odd-Even Subsequence
// https://codeforces.com/contest/1370/problem/D

// Problem Approach :

// we will apply binary search on answer and find minimum cost. 
// Ans = min(max_odd_element, max_even_element)

// Suppose we will able to find the subsequence to length atleast k, 
// where all the elements in either odd or even series are <=x 
// (we will apply binary search on x) then answer <=x 

// Input Array : 5 3 50 2 4 5 (k=4)
// Subsequence : 3 50 2 4

// L = 1   H = 50(Max of arr elements) mid = 25    ans=50

// isValidOdd(mid):
//             count = 0;
//             Series:

// isValidOdd(mid):
//             count = 5;
//             Series: 5,3,2,4,5          // We're checking only for elements coming for odd index, we don't care about element coming for even index

// L = 1   H = 24(old_mid - 1)       mid = 12    ans=25

// isValidOdd(mid):
//             count = 0;
//             Series:

// isValidOdd(mid):
//             count = 5;
//             Series: 5,3,2,4,5

// We are going so on so forth, until we are getting the subsequence of length atleast k.
// The same thing we will do to find isValidEven() series.
// Then finally we calulate the min(OddSeries, EvenSeries)

// Time Complexity = O(n*log(1e9)) = O(n*log(n))

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
int ar[200001];
int n, k;

bool isValidOdd(int val)
{
	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		// We're checking only for elements coming for odd index.
		// we don't care about element coming for even index in subsequence.
		if (cnt % 2 == 0) //means till now length of segment is even and next element is coming for odd index.
		{
			if (ar[i] <= val)
				cnt++;
		}
			else
				cnt++;
	}

	return cnt >= k;
}

bool isValidEven(int val)
{
	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{

		// We're checking only for elements coming for even index.
		// we don't care about element coming for odd index in subsequence.
		if (cnt % 2 == 0)
			cnt++;
		else if (ar[i] <= val)
			cnt++;
	}

	return cnt >= k;
}

int BinarySearch(int L, int H)
{
	int ans = H;

	while (L <= H)
	{
		int mid = L + (H - L) / 2;

		// isValidOdd -> return true if all the elements at odd indexes of subsequence(of atleast length k) <=mid
		if (isValidOdd(mid) || isValidEven(mid))
			ans = mid, H = mid - 1;
		else
			L = mid + 1;
	}

	return ans;
}

int main()
{

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> ar[i];

	cout << BinarySearch(1, 1e9);

	return 0;
}
