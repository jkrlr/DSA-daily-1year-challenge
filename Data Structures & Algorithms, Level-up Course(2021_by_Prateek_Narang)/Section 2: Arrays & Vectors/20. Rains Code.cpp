// https://leetcode.com/problems/trapping-rain-water/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int trappedWater(vector<int> heights){
    int water = 0;
    int n = heights.size();

    // Corner case
    if(n<=2)
        return 0;

    // Left Max, Right Max
    vector<int> Left(n), Right(n);
    Left[0] = heights[0];
    Right[n - 1] = heights[n - 1];

    // for (int i = 1; i < n;i++)
    //     Left[i] = max(Left[i - 1], heights[i]);

    // for (int i = n - 2; i >= 0;i--)
    //     Right[i] = max(Right[i + 1], heights[i]);
    
    for (int i = 1; i < n;i++){
        Left[i] = max(Left[i - 1], heights[i]);
        Right[n-i-1] = max(Right[n-i], heights[n-i-1]);       
    }

    for (int i = 0;i<n;i++)
        water += min(Left[i], Right[i]) - heights[i];

    return water;
}

int main(){
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trappedWater(heights) << endl;
    return 0;
}