// https://leetcode.com/problems/can-place-flowers/

// Easy

// Tags - Array, Greedy

// What this problem wants to teach me?
// How the multiple if else and else if conditions are evaluated
// How to handle and group the multiple if and else conditions efficently
// In which type question we've to made the changes in the input (means inplace changes are allowed)

#include<bits/stdc++.h>
using namespace std;

// Greedy | Time - O(N), Space - O(1)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0, count = 0;
        while(i<flowerbed.size()){
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0)){
                flowerbed[i++] = 1;
                count++;
            }
            
            if(count>=n)
                return true;
            i++;
        }
        
        return false;
    }
};

// Greedy - Less Modular code | Time - O(N), Space - O(1)
// without making changes in the input array
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size()==1){
            if((flowerbed[0]==1 && n>0) || (flowerbed[0]==0 && n>1))
                return false;
            else
                return true;
        }
        
        int i = 0;
        
        while(i< flowerbed.size() && n>0){
            if(flowerbed[i]==0){
                if(i==0 && flowerbed[i+1]==0){
                    i+=2; 
                    n--;
                }
                else if(i==flowerbed.size()-1 && flowerbed[i-1]==0){
                    i+=1;
                    n--;
                }
                else if(i-1>=0 && flowerbed[i-1]==0 && i+1<flowerbed.size() && flowerbed[i+1]==0){
                    i+=2;
                    n--;
                }
                else
                    i++;
            }
            else
                i+=2;
        }
        
        return n==0;
    }
};