// https://leetcode.com/problems/koko-eating-bananas/

// Medium

// Tags - Binary Search - Search Space, Array

// What this problem wants to teach me?
// In Array min/max type questions if greedy/dp possibly feel like not working
// and you to find the answer by traversing the whole array element by element
// and by taking the some max value or min value your answer is comes
// or you can start by value = 1 and increment the value by 1 each time if condition is not valid
// and if valid the answer is returned then, in such cases to optimize this brute force approach
// we can use binary search(search space concept) to make larger jumps instead by 1

#include<bits/stdc++.h>
using namespace std;

// Binary Search | Time = O(NLog(INT_MAX)), Space = O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h){
        int lo = 1, hi = INT_MIN;
        for(int& pile : piles){
            hi = max(hi, pile);
        }

        int ans = hi;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(canEat(piles,mid,h)){
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        return ans;
    }
private:
    bool canEat(vector<int>& piles, int speed, int& h){
        int hours = 0;
        for(int& pile: piles){
            int time = pile/speed;
            if(pile%speed)
                time +=1;

            hours += time;
            if(hours > h)
                return false;
        }
        return true;
    }
};

// Brute - Force | Time - O(N*INT_MAX), Space - O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {    
        // Start at an eating speed of 1.
        int speed = 1;

        while (true) {
            // hourSpent stands for the total number of hours that
            // Koko has spent with the current eating speed.
            int hourSpent = 0;

            // Iterate over the piles and calculate hourSpent.
            // We increase the hourSpent by ceil(pile / speed)
            for (int pile : piles) {
                hourSpent += pile / speed + (pile % speed != 0);
                if (hourSpent > h) {
                    break;
                }
            }

            // Check if Koko can finish all the piles within h hours,
            // If so, return speed. Otherwise, let speed increment by
            // 1 and repeat the previous iteration.
            if (hourSpent <= h) {
                return speed;
            } else {
                speed += 1;
            }            
        }
    }
};
