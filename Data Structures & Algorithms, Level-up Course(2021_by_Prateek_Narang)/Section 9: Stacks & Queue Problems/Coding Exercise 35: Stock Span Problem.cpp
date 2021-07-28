#include <bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> v)
{
    int n = v.size();
    vector<int> span(n, 0);

    //stack<pair<index,price_of_index>>
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top().second <= v[i])
        {
            s.pop();
        }

        int curr_span_val;
        if (s.empty())
        {
            curr_span_val = i + 1;
        }
        else
        {
            curr_span_val = i - s.top().first;
        }

        span.push_back(curr_span_val);
    }
}