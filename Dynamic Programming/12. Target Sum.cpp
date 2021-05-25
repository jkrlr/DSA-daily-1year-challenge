/*-> Target Sum Problem [LeetCode : Solved using Count the no. of subsets with given difference]

Flow :

-> Problem statement :
Given a list of non-negative integers, a1, a2, ..., an, and a target, S.
Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.

Example :
Input: ar is [1, 1, 2, 3], S is 1. 
Output: 3
Explanation: 

+1 -1 -2 +3 = 1
-1 +1 -2 +3 = 1
+1 +1 +2 -3 = 1
*/
/*
-> Will try to reduce the Problem Statement :

-> In this question what we've to return -> Count (means return type is int)
                      +1 -1 -2 +3 
                      /         \
                    +1+3       -1-2
                    (1,3)  -   (1,2)   = 1

-> Solved it using already solved Problem :

Now, we can clearly see this problem is actually nothing but it's the "Count of # of subsets with given d/f" problem.

Target Sum      ---------> Count of Subsets with given Diff     ---------> Subset Sum
*/
// Time Complexity = O(n*Sum) -> for calculating the table
// Space Complexity = O(n*Sum) -> for storing the table 