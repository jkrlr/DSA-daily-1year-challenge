// https://leetcode.com/problems/maximum-frequency-stack/

// Hard

// Tags - Bucket Sort, Heap

// What this problem wants to teach me?
// Bucket Sort

/* Intuition
    Evidently, we care about the frequency of an element. Let freq be a Map from x to the number of occurrences of x.

    Also, we (probably) care about maxfreq, the current maximum frequency of any element in the stack. 
    This is clear because we must pop the element with the maximum frequency.

    The main question then becomes: among elements with the same (maximum) frequency, how do we know which element is most recent? 
    We can use a stack to query this information: the top of the stack is the most recent.

    To this end, let group be a map from frequency to a stack of elements with that frequency. 
    We now have all the required components to implement FreqStack.*/

#include<bits/stdc++.h>
using namespace std;

// Bucket Sort | Push and Pop - Time = O(1), Space = O(N)
class FreqStack {
private:
    unordered_map<int, int> numToFreq;
    unordered_map<int, stack<int>> freqToStack;
    int maxFreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        int curFreq = ++numToFreq[val];
        freqToStack[curFreq].push(val);
        maxFreq = max(maxFreq, curFreq);
    }
    
    int pop() {
        int val = freqToStack[maxFreq].top();
        freqToStack[maxFreq].pop();
        
        numToFreq[val]--;
        if(freqToStack[maxFreq].size()==0)
            maxFreq--;
        
        return val;
    }
};