// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/

// Hard

// Revision

// Tags - Binary Search-Search Space 

// What this problem wants to teach me?
// If arrays given are sorted and we can't use binary search directly
// Then, we should think in terms of search space for our ans by finding ans for a particular value for given inputs

/* Intuition
    Binary search the result, and count the number of smaller product.

    We can firstly consider the simple situation with no negatives.
    The base of this question is the two sum problem.

    In two sum problem,
    we can count the number of pair with sum <= x.

    In this two product problem,
    we need to count the number of pair with product <= x. */

/* Let check(x) be the answer to the question: how many products are less or equal than x.
Then we use binary search and find the first moment where we have exactly k such numbers . */

// Time = O(M*(LogN)*Log(10^10)), Space = O(M+N)   M = nums1.size(), N = nums2.size()

#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    int findMaxIndex(vector<int>& nums2, long long num, long long midVal){
        int leftIndex = 0;
        int rightIndex = nums2.size() - 1;
        int resultIndex = -1;

        while(leftIndex <= rightIndex){

            int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

            if(num * nums2[midIndex] <= midVal){
                resultIndex = midIndex;
                leftIndex = midIndex + 1;
            }
            else{
                rightIndex = midIndex - 1;
            }
        }

        return resultIndex + 1;
    }

    int findMinIndex(vector<int>& nums2, long long num, long long midVal){
        int leftIndex = 0;
        int rightIndex = nums2.size() - 1;
        int resultIndex = nums2.size();

        while(leftIndex <= rightIndex){

            int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

            if(num * nums2[midIndex] <= midVal){
                resultIndex = midIndex;
                rightIndex = midIndex - 1;
            }
            else{
                leftIndex = midIndex + 1;
            }
        }

        return nums2.size() - resultIndex;
    }

    bool check(long long midVal, vector<int>& nums1, vector<int>& nums2, long long k){
        long long cnt = 0;

        for (int i = 0; i < nums1.size(); i++){
            long long num = nums1[i];

			//If num == 0, product of val and each element in nums2 will be 0. And if midVal>=0, then because all
			//products are 0, all products will be smaller or equal to midVal. So we can add all products in the answer

            if(num == 0 && midVal>=0){
                cnt += nums2.size();
            }
            else if(num > 0){
                cnt += findMaxIndex(nums2, num, midVal);
            }
            else if(num < 0){
                cnt += findMinIndex(nums2, num, midVal);
            }
        }

        return cnt >= k;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long lo = -1e10;
        long long hi = 1e10;
        long long result = -1;

        while(lo <= hi){

            long long mid = lo + (hi - lo) / 2;

            if(check(mid,nums1,nums2,k)){
                result = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return result;
    }
};
