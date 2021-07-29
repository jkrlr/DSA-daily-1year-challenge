// https://leetcode.com/problems/online-stock-span/
// Time = O(N), Space = O(N)
#include <bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> prices)
{
    int n = prices.size();
    vector<int> span(n);

    stack<int> s; // indices of the days

    s.push(0);
    span[0] = 1;

    //loop for rest of the days ->O(N)-> Push and Pop each element only once!
    for (int i = 1; i < n; i++)
    {
        int currentPrice = prices[i];
        while (!s.empty() && prices[s.top()] <= currentPrice)
        {
            s.pop();
        }

        if (!s.empty())
        {
            int prevHighest = s.top();
            span[i] = i - prevHighest;
        }
        else
        {
            span[i] = i + 1;
        }
        //push this element into the stack
        s.push(i);
    }

    return span;
}

/* LeetCode: 
class StockSpanner {
public:
    stack<pair<int,int>> s; // prices,indices of the days

    StockSpanner() {
        
    }
    
    int next(int price) {
            
            int res = 1;

            while (!s.empty() && s.top().first<=price)
            {
                res+=s.top().second;
                s.pop();
            }
            s.push({price,res});
            return res;
    }
}; */