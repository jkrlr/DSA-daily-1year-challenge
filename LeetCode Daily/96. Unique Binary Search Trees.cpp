// https://leetcode.com/problems/unique-binary-search-trees/

// Medium

// Tags - Dp, Recursion, BST, Math-Catalan Number

// What this problem wants to teach me?

#include<bits/stdc++.h>
using namespace std;

// DP-TopDown | Time - O(N^2), Space - O(N)
class Solution {
private:
    vector<int> dp = vector<int>(20,-1);    // Pay attention to this declaration
    
public:
    int numTrees(int n) {
        // base case
        if(n<=1){
            return 1;
        }
        
        // check if state is precomputed or not
        if(dp[n]!=-1){
            return dp[n];
        }
        
        // recursive case
        int uniqueBST = 0;
        
        for(int i=1; i<=n; ++i){
            uniqueBST += numTrees(i-1)*numTrees(n-i);
        }
        
        return dp[n] = uniqueBST;
    }
};  

// Complete all below after endsem

// https://www.youtube.com/watch?v=0pTN0qzpt-Y&t=44s
// https://www.youtube.com/watch?v=0s20L4-chDA&t=886s

// https://leetcode.com/problems/unique-binary-search-trees/discuss/1565543/C%2B%2BPython-5-Easy-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Catalan-O(N)
// https://leetcode.com/problems/unique-binary-search-trees/discuss/1565599/C%2B%2B-EASY-INTUITIVE-SOL-(2-approaches)-oror-Recursive-DP-oror-Catalan-Numbers
// https://leetcode.com/problems/unique-binary-search-trees/discuss/31666/DP-Solution-in-6-lines-with-explanation.-F(i-n)-G(i-1)-*-G(n-i)

// https://leetcode.com/problems/unique-binary-search-trees-ii/         Complete this question also


