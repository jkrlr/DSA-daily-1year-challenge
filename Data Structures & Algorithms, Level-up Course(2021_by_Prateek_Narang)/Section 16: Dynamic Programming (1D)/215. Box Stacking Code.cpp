// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
// Solve LeetCode question in next visit
// Add Brute Force and Bottom-Up Approach of this questions
// Also print the boxes as well
 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
bool compareBoxes(vector<int> &boxA, vector<int> &boxB){
	return boxA[2] < boxB[2];
}
 
bool canPlace(vector<int> &boxB, vector<int> &boxA){
	int widthA = boxA[0];
	int depthA = boxA[1];
	int heightA = boxA[2];
	
	int widthB = boxB[0];
    int depthB = boxB[1];
    int heightB = boxB[2];
    
    // If boxes are sorted by height then why compare height here?
    // because two boxes may have same height but we want strictly smaller height
    if(widthB < widthA && depthB < depthA && heightB < heightA){
        return true;
    }
    return false;
}
 
// Time = O(m*n), Space = O(m)
int largestStackHeight(vector<vector<int>> boxes){
	int m = boxes.size();
 
	// 1. sort according to height i.e. 3rd element
	sort(boxes.begin(), boxes.end(),compareBoxes);
 
	// 2. Bottom-Up
    vector<int> dp(m, 0);
    for (int i = 0; i < m; i++){
        dp[i] = boxes[i][2];	// height of ith box
    }

    for(int i = 1; i<m; i++){
		// check for all boxes whose index is less than i
		for(int j = 0; j<i; j++){
            if(canPlace(boxes[j], boxes[i])){
                int currHeight = boxes[i][2];
                dp[i] = max(dp[i], currHeight + dp[j]);
            }	
        }
    }
    int largest = *max_element(dp.begin(),dp.end());
    return largest;
}
 
int main(){
	vector<vector<int>> boxes = {{2,1,2},
			{3,2,3},
			{2,2,8},
			{2,3,4},
			{2,2,1},
			{4,4,5}};
	cout<<largestStackHeight(boxes)<<endl;
}
