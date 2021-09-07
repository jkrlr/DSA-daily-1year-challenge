 
#include<iostream>
#include<vector>
using namespace std;
 
// Recurisve - Time = O(2^n), Space = O(n)
int MaxProfit(vector<int> &winePrices, int left, int right, int year){
	// base case
	if(left > right){
		return 0;
	}
	
	// recursive case
	int sellLeftMost = winePrices[left]*year + MaxProfit(winePrices, left+1, right, year+1);
	int sellRightMost = winePrices[right]*year + MaxProfit(winePrices, left, right-1, year+1);
	
	int profit = max(sellLeftMost, sellRightMost);
	return profit;
}
 
int main(){
	vector<int> winePrices = {2, 3, 5, 1, 4};
	int n = winePrices.size();
	int left = 0; int right = n-1;
int year = 1;
	cout<<MaxProfit(winePrices, left, right, year)<<endl;
	
	vector<int>dp
}
