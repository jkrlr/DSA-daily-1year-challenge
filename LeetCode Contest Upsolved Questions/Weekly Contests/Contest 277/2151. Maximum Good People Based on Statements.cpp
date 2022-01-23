// https://leetcode.com/problems/maximum-good-people-based-on-statements/

// Hard

// Tags - Recursion - Brute Force

// What this problem wants to teach me?
// If constraints are small => recursion 
// If you aren't able to generate the correct combination from given input 
// then in recursion problems first genreate all the possible combinationa and
// then check if a combination is valid , If valid then check what is asked in question in that valid combination

#include<bits/stdc++.h>
using namespace std;

// Recursion - Brute Force | Time - O(N^2 * 2^N), Space = O(N)-for Recursive Stack, for carr array
class Solution {
private:
    int n, ans;
    vector<vector<int>> statements;
    vector<char> carr;
private:
    bool check(){
        for(int i=0; i<n; i++){
            if(carr[i]=='G'){
                for(int j=0; j<n; j++){
                    if(statements[i][j] == 0 && carr[j] == 'G'){
                        return false;
                    }
                    if(statements[i][j] ==1 && carr[j] == 'B'){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
private:
    void createCombination(int index){
        // base case
        if(index==n){
            if(check()){    // check if current statement is valid or not
                int total = 0;
                for(int i=0; i<n; i++){     // if current statemetn is valid then count the Good
                    if(carr[i]=='G'){
                        total++;
                    }
                }
                ans = max(ans, total);
            }
            
            return;
        }
        
        // recursive case
        carr[index] = 'G';
        createCombination(index + 1);
        carr[index] = 'B';
        createCombination(index+1);
    }
public:
    int maximumGood(vector<vector<int>>& statements) {
        n = statements.size();
        carr.resize(n);
        this->statements = statements;
        createCombination(0);
        return ans;
    }
};
