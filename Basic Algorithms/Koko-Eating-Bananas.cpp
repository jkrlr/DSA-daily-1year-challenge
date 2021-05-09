// 875. Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/

// Solving Problem : Monotonic Function (Binary Search)

// F(x) : return number of hours taken to eat all bananas with speed x. 

// Example : 30, 11, 23, 4, 20

// F(5) returns 19

// Task : Prove that function F() is monotonic. 

// If F(x) is k then,
//     1. If you increasing banana speed. then, number of hours taken will be 
//     either same of decreases, in other words f(x+h)<=k. 

// Solving Problem : The Approach

// For F(x), we'll apply apply binary search on speed.

// L:1
// R:max_of_piles-array

// Input : 30, 11, 23, 4, 20
// h = 6 

// L   mid     R 
// 1   15      30

// f(15)=8     Ans=30

// L    mid     R 
// 16   23      30

// f(23)=6     Ans=23 i.e min(23,30) which is min(curr_ans,prev_ans)


class Solution {
public:
    
    int f(vector<int>& ar, int mid){
        int hours =0 ;
        
        for(int P : ar)
            hours+=(P+mid-1)/mid;     // (P+mid-1)/mid is equivalent to ceil(P/mid)
        
        return hours;
    }
    
    int minEatingSpeed(vector<int>& ar, int H) {
        int L =1;
        int R = *max_element(ar.begin(), ar.end()); // max_element() -> returns iterator to the maximum element in an array, we're using * to accesing the value
        int ans=R;
        
        while(L<=R){
            int mid = L + (R-L)/2;
            
            if(f(ar, mid)<=H)
                ans=min(ans, mid), R=mid-1;
            else
                L=mid+1;

        }
        
        return ans;
    }
};