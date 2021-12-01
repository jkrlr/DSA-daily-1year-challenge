// https://leetcode.com/problems/unique-binary-search-trees/

// Medium

// Tags - Dp, Recursion, BST, Math-Catalan Number

// What this problem wants to teach me?
// Catalan Number Series : 1, 1, 2, 5, 14, 42, 132,...
// Cn = CoCn-1 + C1Cn-2 + ... + Cn-1Co

// Catalan Number F(n) = [Σ(i=1 to N)]F(i-1)*1*F(N-i) = (Left&Root&Right) = (2nCn)/(n+1)
// FollowUps => Count(Binary Trees) = n! * F(n) -> we can inchange all the nodes in particular tree
// FollowUps => Count(Unlabelled Binary Trees) = means with unique structure = Count(BST's) = F(n)

/* Catalan Number Problems
    1. No. Of BST's     => Cn
    2. Ublabelled Trees => Cn
    3. N parantheses (with and without letters) => Cn
    4. Dyck Words       => Cn
    5. Mountain Ranges  => Cn
    6. Path on Grid     => Cn
    7. Convex Polygon   => C(n-2)
    8. Conect Disjoint Chords   => Cn
 */

// Tautorials
// https://www.youtube.com/watch?v=0pTN0qzpt-Y&t=44s
// https://www.youtube.com/watch?v=0s20L4-chDA&t=886s

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

// DP-BottomUp | Time - O(N^2), Space - O(N)
class Solution {
public:
    int numTrees(int N) {
        vector<int>dp(N+1,0);
        dp[0] = dp[1] = 1;

        for (int n = 2; n <= N; n++){
            for (int i = 1; i <= n; i++){
                dp[n] += dp[i - 1] * dp[n - i];
            }
        }

        return dp[N];
    }
};  