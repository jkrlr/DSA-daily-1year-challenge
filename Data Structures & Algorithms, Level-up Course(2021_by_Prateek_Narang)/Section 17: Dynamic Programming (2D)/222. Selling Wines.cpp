#include <iostream>
#include <vector>
using namespace std;

// Recurisve - Time = O(2^n), Space = O(n)
int MaxProfit(vector<int> &winePrices, int left, int right, int year)
{
	// base case
	if (left > right)
	{
		return 0;
	}

	// recursive case
	int sellLeft = winePrices[left] * year + MaxProfit(winePrices, left + 1, right, year + 1);
	int sellRight = winePrices[right] * year + MaxProfit(winePrices, left, right - 1, year + 1);

	int profit = max(sellLeft, sellRight);
	return profit;
}

// Top-Down - Time = O(n^2), Space = O(n^2)
int MaxProfitTD(vector<int> &winePrices, int left, int right, int year, vector<vector<int>> &dp)
{
	// base case
	if (left > right)
	{
		return 0;
	}

	// check if a state is precomputed
	if (dp[left][right] != 0)
	{
		return dp[left][right];
	}

	int sellLeft = winePrices[left] * year + MaxProfitTD(winePrices, left + 1, right, year + 1, dp);
	int sellRight = winePrices[right] * year + MaxProfitTD(winePrices, left, right - 1, year + 1, dp);

	int profit = max(sellLeft, sellRight);
	return dp[left][right] = profit;
}

// Top-Down - Time = O(n^2), Space = O(n^2)
int MaxProfitTD(int prices[], int L, int R, int y, int dp[][1000])
{
	// base case
	if (L > R)
	{
		return 0;
	}

	// check if a state is precomputed
	if (dp[L][R] != 0)
	{
		return dp[L][R];
	}

	int pickLeft = prices[L] * y + MaxProfitTD(prices, L + 1, R, y + 1, dp);
	int pickRight = prices[R] * y + MaxProfitTD(prices, L, R - 1, y + 1, dp);

	int profit = max(pickLeft, pickRight);
	return dp[L][R] = profit;
}

// Bottom-Up - Time = O(n^2), Space = O(n^2)
int MaxProfitBU(vector<int> &winePrices)
{
	int n = winePrices.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // i>j elements also initailized with 0 here.

	for (int i = n - 1; i >= 0; i--)
	{
		// bottom row to top row
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				dp[i][j] = n * winePrices[i];
			}
			if (i < j)
			{
				// dp(i...j) remaining then year is
				int year = n - (j - i);
				int pickLeft = winePrices[i] * year + dp[i + 1][j];
				int pickRight = winePrices[j] * year + dp[i][j - 1];
				dp[i][j] = max(pickLeft, pickRight);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return dp[0][n - 1];
}

int main()
{
	vector<int> winePrices = {2, 3, 5, 1, 4};
	int n = winePrices.size();
	int left = 0;
	int right = n - 1;
	int year = 1;
	cout << MaxProfit(winePrices, left, right, year) << endl;

	// size is n not n+1 because it will depends upon left and right
	// and range of left and right is 0 to n-1.
	vector<vector<int>> dp(n, vector<int>(n, 0));
	cout << MaxProfitTD(winePrices, left, right, year, dp) << endl;

	// print the dp
	// our ans is in dp[0][n-1] => left = 0 and right = n - 1
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	int prices[] = {2, 3, 5, 1, 4};
	int Dp[1000][1000] = {0};
	cout << MaxProfitTD(prices, 0, 4, 1, Dp) << endl;

	// Bottom-Up
	cout << MaxProfitBU(winePrices) << endl;
}
