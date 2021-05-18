/* => 10. Minimum Subset Sum Difference (or Minimum sum partition)
https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Flow :
-> Problem Statement
-> Similarity -> ?? 
-> Solve using the previous concept

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Problem Statement :
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:
Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
-> Similarity :
                        ar 
                       / \
                      P1  P2
                      |   |
                      S1  S2

S1 = S2 => S2 - S1 = 0 -> Equal sum partition prob.
but in this case, abs(S2 - S1) = Minimum (it can be zero also) => which means first we've to find out S1 and S2.

This prob is similar with -> Equal sum partition
and we solved Equal sum partition with the help of -> Subset Sum
So, we will solve this prob. with the help of Subset sum(also with Equal sum partition).

------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-> Solution Approach :

Now, How to find Sum1 and Sum2?
we don't know the exact value of S1 and S2, but can we find the range of S1, S2?
Yes ->  S1, S2 ∈ [0 , ∑ar[i]] 

                        ar 
                       / \
                      P1  P2
                      |    |
                      S1 + S2 = ∑ar[i] = Range
                    
                      S1   S2=Range-S1
                               ---
                              ∑ar[i]

=> S2 - S1 = Min
(Range - S1) - S1 = Min
Range - 2*S1 = Min

Example ar[] = {1, 2, 7} -> So, the S1,S2 ∈ {1,2,3,7,8,9} only not upto the whole range(0,10).

|-1-2-3-------|-------7-8-9-|
0           Range/2        Range(=10)
 <_____S1____> <__Range-S1__>

We are taking S1 value to be upto Range/2 . So that the value of S2-S1 = +ve always.
So, we don't need to take the abs difference.

How to filer ki given kon sa sum exist karega aur kon sa nahi -> by using Subset Sum.
Last row to t[n][sum] in Subset sum prob.-> will gives ki kon sa sum exist karega(True value) aur kon sa nahi(False value).

--------------------------------------------------------------------------------------------------------------------------- */
// -> Implementation :

// Time Complexity = O(n*Range) = O(n*∑ar[i]) -> for calculating the table values in SubsetSum.
// Space Complexity = O(n*Range) = O(n*∑ar[i]) -> For Storing the table in SubsetSum.

class Solution{

	public:
	vector<int> SubsetSum(int ar[], int n, int Range){
	    vector<int> res;
	    bool t[n+1][Range+1];
	    
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=Range;j++){
	            if(i==0)
	                t[i][j] = false;
	                
	           if(j==0)
	                t[i][j]=true;
	        }
	    }
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=Range;j++){
                if(ar[i-1]<=j)
                    t[i][j] =  t[i-1][j-ar[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
	        }
	    }


	    for(int j=0;j<=Range/2;j++){
            if(t[n][j])
                res.push_back(j);
	    }
	    
	    return res;
	}
	
	int minDiffernce(int ar[], int n) 
	{ 
        int initial_sum =0;
        // STL function to calculate the sum of ar.
        int Range = accumulate(ar, ar+n, initial_sum);
        
        vector<int> range_values = SubsetSum(ar,n,Range);
        
        int minimum = INT_MAX;
        
        for(int i=0;i<range_values.size();i++)
                minimum = min(minimum, (Range - 2*range_values[i]));
                
        return minimum;
	} 
};
















































































































