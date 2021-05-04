// Subset Sum Problem
// https://www.interviewbit.com/problems/subset-sum-problem/

// Given a set of non-negative integers, and a value sum, 
// determine if there is a subset of the given set with sum equal to given sum.
// Example:

// Input:  set[] = {3, 34, 4, 12, 5, 2}, sum = 9
// Output:  1  //There is a subset (4, 5) with sum 9.

// Flow
// 1. Problem Statement
// 2. Similarity (with 01 Knapsack Prob.)
// 3. Code Variation
//         /      \
// Initialization Code


int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int t[n + 1][B + 1];

    for(int i=0;i<=n;i++){
        for(int j=0; j<=B;j++){
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1; j<=B;j++){
            if(A[i-1]<=j)
                t[i][j] = (t[i-1][j-A[i-1]] || t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][B];
    
}

