// https://leetcode.com/problems/find-median-from-data-stream/
// Time = O(NLogN), Space = O(N)

#include<bits/stdc++.h>
using namespace std;

class MedianHandler{
public:
    float median;
	priority_queue<int> leftHeap;   // max heap
    priority_queue<int, vector<int>, greater<int>> rightHeap; // min heap

    //Complete this method to update median after every insertion 
    void push(int number){
        // Initialization
        if(leftHeap.empty() && rightHeap.empty()){
            leftHeap.push(number);
            return;
        }

        median = getMedian();
        
        // left or right or equal
        if(leftHeap.size() > rightHeap.size()){
            if(number < median){
                    rightHeap.push(leftHeap.top());	// push root of left heap into right heap
                    leftHeap.pop();
                    leftHeap.push(number);	// now push current element into left heap
            }
            else{
                    rightHeap.push(number);
            }
        }
        else if(leftHeap.size() == rightHeap.size()){
                if(number < median){
                    leftHeap.push(number);
                }
                else{
                    rightHeap.push(number);
                }
        }
        else{
            if(number < median){
                    leftHeap.push(number);
            }
            else{
                    leftHeap.push(rightHeap.top());	// push root of right heap into left heap
                    rightHeap.pop();
                    rightHeap.push(number);	// now push current element into right heap
            }
        }     
    }
    
    //Complete this , Should return the median in O(1) time
    float getMedian(){
        if(leftHeap.size() > rightHeap.size()){
            median = leftHeap.top();
        }
        else if(rightHeap.size() > leftHeap.size()){
            median = rightHeap.top();
        }
        else{
            int mid1 = leftHeap.top();
            int mid2 = rightHeap.top();
            median  = mid1 + (mid2-mid1)/2.0;        
        }
        return median;
    }
};